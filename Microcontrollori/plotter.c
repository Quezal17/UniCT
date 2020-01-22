/*
 * plotter.c
 *
 *  Created on: 22 gen 2020
 *      Author: simone
 */

#include "stm32_unict_lib.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
enum{
	SET_TARGET,
	ST_RUN
};
int stato=SET_TARGET;
int count_time=0;
int x=0;
int y=0;
int testinax=0;
int testinay=0;
int t_on_run=0;
int t_on_reset=0;
int main(){
	CONSOLE_init();
	DISPLAY_init();

	GPIO_init(GPIOB);
	GPIO_init(GPIOC);

	GPIO_config_output(GPIOB,0);
	GPIO_config_output(GPIOC,2);

	GPIO_config_input(GPIOB,10); //X
	GPIO_config_EXTI(GPIOB,EXTI10);
	EXTI_enable(EXTI10,FALLING_EDGE);

	GPIO_config_input(GPIOB,4); //Y
	GPIO_config_EXTI(GPIOB,EXTI4);
	EXTI_enable(EXTI4,FALLING_EDGE);

	GPIO_config_input(GPIOB,5); //Z
	GPIO_config_EXTI(GPIOB,EXTI5);
	EXTI_enable(EXTI5,FALLING_EDGE);

	ADC_init(ADC1,ADC_RES_8,ADC_ALIGN_RIGHT);
	ADC_channel_config(ADC1,GPIOC,1,11);
	ADC_channel_config(ADC1,GPIOC,0,10);
	ADC_on(ADC1);

	TIM_init(TIM2);
	TIM_config_timebase(TIM2,42000,400);
	TIM_enable_irq(TIM2,IRQ_UPDATE);
	TIM_set(TIM2,0);
	TIM_on(TIM2);


	for(;;){
		switch(stato){
		char str[5];
		case SET_TARGET:
			printf("stato SET_TARGET\n");
			GPIO_write(GPIOC,2,1);
			GPIO_write(GPIOB,0,0);
			ADC_sample_channel(ADC1,11); // x setup
			ADC_start(ADC1);
			while(!ADC_completed(ADC1)){}
			int adc_val= ADC_read(ADC1);
			x = adc_val * 99/255;

			ADC_sample_channel(ADC1,10);  //y setup
			ADC_start(ADC1);
			while(!ADC_completed(ADC1)){}
			adc_val= ADC_read(ADC1);
			y = adc_val * 99/255;

			sprintf(str,"%02d%02d",x,y);
			DISPLAY_puts(0,str);
			break;
		case ST_RUN:
			printf("stato ST_RUN\n");
			GPIO_write(GPIOB,0,1);
			GPIO_write(GPIOC,2,0);
			sprintf(str,"%02d%02d",testinax,testinay);
			DISPLAY_puts(0,str);

			break;
		default:
			break;
		}
	}
}

void EXTI15_10_IRQHandler(){ //X
	if(EXTI_isset(EXTI10))
	{
		if(stato==ST_RUN)
		{
			stato=SET_TARGET;

		}
		EXTI_clear(EXTI10);
	}
}

void EXTI4_IRQHandler(){ //Y
	if(EXTI_isset(EXTI4))
	{
		if(stato==SET_TARGET)
		{
			stato=ST_RUN;

		}
		EXTI_clear(EXTI4);
	}
}

void EXTI9_5_IRQHandler(){ //Z
	if(EXTI_isset(EXTI5))
	{
		if(stato==ST_RUN)
		{
			x=0;
			y=0;
		}
		EXTI_clear(EXTI5);
	}
}

void TIM2_IRQHandler(){
	if(TIM_update_check(TIM2))
	{
		if(stato==ST_RUN)
		{
			if(testinax<x)
				testinax++;
			else if(testinax>x)
				testinax--;


			if(testinay<y && testinax==x)
				testinay++;
			else if(testinay>y && testinax==x)
				testinay--;

		}
		TIM_update_clear(TIM2);
	}
}

