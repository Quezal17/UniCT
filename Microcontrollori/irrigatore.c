/*
 * irrigatore.c
 *
 *  Created on: 26 gen 2020
 *      Author: simone
 */

#include <stdio.h>
#include <stdlib.h>
#include "stm32_unict_lib.h"

enum{
	ST_RUN,
	ST_MENU,
	ST_SETUP,
	ST_SHOW
};

int stato=ST_RUN;
int count_sec=-1;
int count_min=0;
int min_inizio=0;
int sec_inizio=0;
int min_fine=0;
int sec_fine=0;
int min_time=0;
int sec_time=0;
int temp_min=0;
int temp_sec=0;
int menu=0;

int main(){
	CONSOLE_init();
	DISPLAY_init();
	GPIO_init(GPIOB);
	GPIO_init(GPIOC);

	GPIO_config_output(GPIOB,0);
	GPIO_config_output(GPIOC,2);
	GPIO_config_output(GPIOB,8);


	GPIO_config_input(GPIOB,10); //X
	GPIO_config_EXTI(GPIOB,EXTI10);
	EXTI_enable(EXTI10,FALLING_EDGE);

	GPIO_config_input(GPIOB,4); //Y
	GPIO_config_EXTI(GPIOB,EXTI4);
	EXTI_enable(EXTI4,FALLING_EDGE);

	GPIO_config_input(GPIOB,5); //Z
	GPIO_config_EXTI(GPIOB,EXTI5);
	EXTI_enable(EXTI5,FALLING_EDGE);

	ADC_init(ADC1,ADC_RES_6,ADC_ALIGN_RIGHT);
	ADC_channel_config(ADC1,GPIOC,0,10);
	ADC_channel_config(ADC1,GPIOC,1,11);
	ADC_on(ADC1);

	TIM_init(TIM2);
	TIM_config_timebase(TIM2,42000,2000);
	TIM_enable_irq(TIM2,IRQ_UPDATE);
	TIM_set(TIM2,0);
	TIM_on(TIM2);

	for(;;){
		char str[5];
		switch(stato){
		case ST_RUN:
			GPIO_write(GPIOB,8,1);
			GPIO_write(GPIOB,0,0);
			sprintf(str,"%02d%02d",count_min,count_sec);
			DISPLAY_puts(0,str);
			break;
		case ST_MENU:
			GPIO_write(GPIOB,8,0);
			GPIO_write(GPIOC,2,0);
			GPIO_write(GPIOB,0,1);
			if(menu==0)
				sprintf(str,"ti  ");
			else if(menu==1)
				sprintf(str,"St  ");
			else if(menu==2)
				sprintf(str,"En  ");
			DISPLAY_puts(0,str);
			break;
		case ST_SETUP:
			ADC_sample_channel(ADC1,11);
			ADC_start(ADC1);
			while(!ADC_completed(ADC1)){}
			int adc_val= ADC_read(ADC1);
			temp_min=adc_val*23/63;

			ADC_sample_channel(ADC1,10);
			ADC_start(ADC1);
			while(!ADC_completed(ADC1)){}
			adc_val= ADC_read(ADC1);
			temp_sec=adc_val*59/63;
			sprintf(str,"%02d%02d",temp_min,temp_sec);
			DISPLAY_puts(0,str);

			break;
		case ST_SHOW:
			GPIO_write(GPIOB,8,1);
			switch(menu){
				case 0:
					sprintf(str,"%02d%02d",min_time,sec_time);
					break;
				case 1:
					sprintf(str,"%02d%02d",min_inizio,sec_inizio);
					break;
				case 2:
					sprintf(str,"%02d%02d",min_fine,sec_fine);
					break;
			}
			DISPLAY_puts(0,str);
			break;
		}

	}

}

void EXTI15_10_IRQHandler(){ //X
	if(EXTI_isset(EXTI10))
	{
		if(stato==ST_MENU)
		{
			menu++;
			if(menu==3)
				menu=0;
		}
		if(stato==ST_SETUP)
		{
			switch(menu){
						case 0:
							min_time=temp_min;
							sec_time=temp_sec;
							count_min=min_time;
							count_sec=sec_time;
							break;
						case 1:
							min_inizio=temp_min;
							sec_inizio=temp_sec;
							break;
						case 2:
							min_fine=temp_min;
							sec_fine=temp_sec;
							break;
						}
			stato=ST_SHOW;
		}
		if(stato==ST_RUN)
			stato=ST_MENU;
		EXTI_clear(EXTI10);
	}
}

void EXTI4_IRQHandler(){ //Y
	if(EXTI_isset(EXTI4))
	{
		if(stato==ST_MENU)
			stato=ST_RUN;
		else if(stato==ST_SETUP)
			stato=ST_SHOW;
		else if(stato==ST_SHOW)
			stato=ST_MENU;
		EXTI_clear(EXTI4);
	}
}

void EXTI9_5_IRQHandler(){ //Z
	if(EXTI_isset(EXTI5))
	{
		if(stato==ST_MENU)
			stato=ST_SHOW;
		else if(stato==ST_SHOW)
			stato=ST_SETUP;
		EXTI_clear(EXTI5);
	}
}

void TIM2_IRQHandler(){
	if(TIM_update_check(TIM2))
	{
		if(stato==ST_RUN){

			if(count_min>=min_inizio && count_sec>=sec_inizio)
				GPIO_write(GPIOC,2,1);
			if(count_min>=min_fine && count_sec>=sec_fine)
				GPIO_write(GPIOC,2,0);
			count_sec++;
			if(count_sec==60)
			{
				count_sec=0;
				count_min++;
			}
			if(count_min==23)
				count_min=0;
		}
		if(stato==ST_SETUP)
			GPIO_toggle(GPIOB,8);
		TIM_update_clear(TIM2);
	}
}

