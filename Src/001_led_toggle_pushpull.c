/**
 ******************************************************************************
 * @file    001_led_toggle_pushpull.c
 * @author  Mehmet Ali Özder
 * @brief   STM32F446xx GPIO Driver - Push-Pull LED Toggling Test Application
 * @date    2026-09-05
 ******************************************************************************
 * @details
 * This application tests the GPIO output functionality in Push-Pull mode.
 * Pin Configuration:
 *  - Port: GPIOA
 *  - Pin:  GPIO_PIN_NO_5 (On-board LED / LD2)
 ******************************************************************************
 */

#include "stm32f446xx_gpio_driver.h"

void delay(void){
	for(volatile int i =0;i<1000000;i++);
}

int main(void){
	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Handle_t user_led2 = {0};

	user_led2.pGPIOx = GPIOA;
	user_led2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	user_led2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	user_led2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	user_led2.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	user_led2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO_Init(&user_led2);

	for(;;){
		GPIO_ToggleOutputPin(GPIOA,GPIO_PIN_NO_5);
		delay();
	}
}


