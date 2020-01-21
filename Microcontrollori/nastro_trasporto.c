/*
 * nastro_trasporto.c
 *
 *  Created on: 20 gen 2020
 *      Author: simone
 */

#include "stm32_unict_lib.h"
#include <stdio.h>
#include <stdlib.h>

enum
{
	ST_CONF,
	ST_RUN,
	ST_SVUOTA
};
int stato = ST_CONF;

enum
{
	ROSSO,
	VERDE,
	GIALLO
};
int contenitori[3] = {0, 0, 0};
int P = 0;
int count_time = 0;
int t_on = 0;
int flash_type;
int count_flash_red = 0;
int count_flash_green = 0;
int count_flash_yellow = 0;
int main()
{
	GPIO_init(GPIOB);
	GPIO_init(GPIOC);

	DISPLAY_init();

	GPIO_config_output(GPIOB, 0); //rosso
	GPIO_config_output(GPIOC, 2); //giallo
	GPIO_config_output(GPIOC, 3); //verde
	GPIO_config_output(GPIOB, 8); //due punti
	GPIO_write(GPIOB, 8, 1);

	//X
	GPIO_config_input(GPIOB, 10);
	GPIO_config_EXTI(GPIOB, EXTI10);
	EXTI_enable(EXTI10, FALLING_EDGE);

	//Y
	GPIO_config_input(GPIOB, 4);
	GPIO_config_EXTI(GPIOB, EXTI4);
	EXTI_enable(EXTI4, FALLING_EDGE);

	//Z
	GPIO_config_input(GPIOB, 5);
	GPIO_config_EXTI(GPIOB, EXTI5);
	EXTI_enable(EXTI5, FALLING_EDGE);

	//T
	GPIO_config_input(GPIOB, 6);
	GPIO_config_EXTI(GPIOB, EXTI6);
	EXTI_enable(EXTI6, FALLING_EDGE);

	ADC_init(ADC1, ADC_RES_6, ADC_ALIGN_RIGHT);
	ADC_channel_config(ADC1, GPIOC, 1, 11);
	ADC_on(ADC1);

	TIM_init(TIM2);
	TIM_config_timebase(TIM2, 42000, 2000); //Pinc=0.5 ms, 1 sec
	TIM_enable_irq(TIM2, IRQ_UPDATE);

	TIM_init(TIM3);
	TIM_config_timebase(TIM3, 42000, 200); //Pinc=0.5 ms, 100 ms
	TIM_enable_irq(TIM3, IRQ_UPDATE);
	TIM_set(TIM3, 0);
	TIM_on(TIM3);

	for (;;)
	{
		switch (stato)
		{
			char str[5];
		case ST_CONF:
			ADC_sample_channel(ADC1, 11);
			ADC_start(ADC1);
			while (!ADC_completed(ADC1)){}
			int adc_val = ADC_read(ADC1);
			P = adc_val * (20 - 10) / 63 + 10;
			sprintf(str, "SE%02d", P); //setup
			DISPLAY_puts(0, str);
			break;
		case ST_RUN:
			sprintf(str, "  %02d", count_time);
			DISPLAY_puts(0, str);
			if (t_on)
			{
				sprintf(str, "%02d", contenitori[flash_type]);				
				DISPLAY_puts(0, str);
			}
			break;
		case ST_SVUOTA:
			TIM_off(TIM2);
			sprintf(str, "EE%02d", P);
			DISPLAY_puts(0, str);
			if (contenitori[ROSSO] > 5)
			{
				contenitori[ROSSO] = 0;
				GPIO_write(GPIOB, 0, 1);
			}
			if (contenitori[VERDE] > 5)
			{
				contenitori[VERDE] = 0;
				GPIO_write(GPIOC, 3, 1);
			}
			if (contenitori[GIALLO] > 5)
			{
				contenitori[GIALLO] = 0;
				GPIO_write(GPIOC, 2, 1);
			}
			delay_ms(2000);
			GPIO_write(GPIOB, 0, 0);
			GPIO_write(GPIOC, 2, 0);
			GPIO_write(GPIOC, 3, 0);
			stato = ST_RUN;
			TIM_set(TIM2, 0);
			TIM_on(TIM2);
			break;
		}
	}
}

void EXTI4_IRQHandler()
{
	if (EXTI_isset(EXTI4)) //Y - VERDE
	{
		if (stato == ST_RUN)
		{
			contenitori[VERDE]++;
			t_on = 1;
			flash_type = VERDE;
		}
		EXTI_clear(EXTI4);
	}
}

void EXTI9_5_IRQHandler()
{
	if (EXTI_isset(EXTI5)) //Z - GIALLO
	{
		if (stato == ST_RUN)
		{
			contenitori[GIALLO]++;
			t_on = 1;
			flash_type = GIALLO;
		}
		EXTI_clear(EXTI5);
	}

	if (EXTI_isset(EXTI6)) //T
	{
		if (stato == ST_CONF)
		{
			count_time = 0;
			t_on = 0;
			stato = ST_RUN;
			TIM_set(TIM2, 0);
			TIM_on(TIM2);
		}
		else if (stato == ST_RUN)
		{
			stato = ST_CONF;
			TIM_off(TIM2);
		}

		EXTI_clear(EXTI6);
	}
}

void EXTI15_10_IRQHandler()
{
	if (EXTI_isset(EXTI10)) //X - ROSSO
	{
		if (stato == ST_RUN)
		{
			contenitori[ROSSO]++;
			t_on = 1;
			flash_type = ROSSO;
		}
		EXTI_clear(EXTI10);
	}
}

void TIM2_IRQHandler()
{
	if (TIM_update_check(TIM2))
	{

		if (stato == ST_RUN)
		{
			count_time++;
			if (count_time == P)
			{
				stato = ST_SVUOTA;
				count_time = 0;
			}
		}
		TIM_update_clear(TIM2);
	}
}

void TIM3_IRQHandler()
{
	if (TIM_update_check(TIM3))
	{

		if (t_on && flash_type == ROSSO)
		{
			count_flash_red++;
			if (count_flash_red < 6)
			{
				GPIO_toggle(GPIOB, 0);
			}
			else
			{
				GPIO_write(GPIOB, 0, 0);
				count_flash_red = 0;
				t_on = 0;
			}
		}

		if (t_on && flash_type == VERDE)
		{
			count_flash_green++;
			if (count_flash_green < 6)
			{
				GPIO_toggle(GPIOC, 3);
			}
			else
			{
				GPIO_write(GPIOC, 3, 0);
				count_flash_green = 0;
				t_on = 0;
			}
		}

		if (t_on && flash_type == GIALLO)
		{

			if (count_flash_yellow < 6)
			{
				GPIO_toggle(GPIOC, 2);
			}
			else
			{
				GPIO_write(GPIOC, 2, 0);
				count_flash_yellow = 0;
				t_on = 0;
			}
			count_flash_yellow++;
		}

		TIM_update_clear(TIM3);
	}
}
