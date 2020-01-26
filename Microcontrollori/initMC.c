#include "stm32_unict_lib.h"
#include <stdio.h>

int main()
{
    CONSOLE_init();
    DISPLAY_init();
	GPIO_init(GPIOB);
	GPIO_init(GPIOC);

	GPIO_config_output(GPIOB, 0); //rosso
	GPIO_config_output(GPIOC, 2); //giallo
	GPIO_config_output(GPIOC, 3); //verde
	GPIO_config_output(GPIOB, 8); //due punti
	GPIO_write(GPIOB, 8, 1);
	DISPLAY_dp(0,1); //accensione pallino 0

	//X
	GPIO_config_input(GPIOB, 10);
	GPIO_config_EXTI(GPIOB, EXTI10);
	EXTI_enable(EXTI10, FALLING_EDGE);

	ADC_init(ADC1, ADC_RES_6, ADC_ALIGN_RIGHT);
	ADC_channel_config(ADC1, GPIOC, 1, 11);
	ADC_on(ADC1);

	TIM_init(TIM3);
	TIM_config_timebase(TIM3, 42000, 200); //Pinc=0.5 ms, 100 ms
	TIM_enable_irq(TIM3, IRQ_UPDATE);
	TIM_set(TIM3, 0);
	TIM_on(TIM3);

    for(;;){
        ADC_sample_channel(ADC1, 11);
		ADC_start(ADC1);
		while (!ADC_completed(ADC1)){}
		int adc_val = ADC_read(ADC1);
		P = adc_val * (max - min) / (2^nbits-1) + min;

        char str[5];
        sprintf(str, "SE%02d", P);
		DISPLAY_puts(0, str);
    }
}

void EXTI4_IRQHandler()
{
	if (EXTI_isset(EXTI4)) //Y
	{
		
		EXTI_clear(EXTI4);
	}
}

void EXTI9_5_IRQHandler()
{
	if (EXTI_isset(EXTI5)) //Z
	{
		
		EXTI_clear(EXTI5);
	}

	if (EXTI_isset(EXTI6)) //T
	{
		
		EXTI_clear(EXTI6);
	}
}

void EXTI15_10_IRQHandler()
{
	if (EXTI_isset(EXTI10)) //X
	{
		
		EXTI_clear(EXTI10);
	}
}

void TIM2_IRQHandler()
{
	if (TIM_update_check(TIM2))
	{

		TIM_update_clear(TIM2);
	}
}