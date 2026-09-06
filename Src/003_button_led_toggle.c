/**
 ******************************************************************************
 * @file    003_button_led_toggle.c
 * @author  Mehmet Ali Özder
 * @brief   STM32F446xx GPIO Driver - Button Controlled LED Toggle Application
 * @date    2026-09-06
 ******************************************************************************
 * @details
 * This application tests GPIO input functionality by reading the user button
 * to toggle the on-board LED.
 * Pin Configuration:
 *  - LED (Output)    : Port GPIOA, Pin 5  (On-board LED / LD2)
 *  - Button (Input)  : Port GPIOC, Pin 13 (On-board User Button / B1)
 ******************************************************************************
 */

#include "stm32f446xx_gpio_driver.h"

void delay(void){
	for(volatile uint32_t i =0;i<300000;i++);
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

	GPIO_PeriClockControl(GPIOC, ENABLE);
	GPIO_Handle_t user_button1 = {0};

	user_button1.pGPIOx = GPIOC;
	user_button1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	user_button1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IN;
	user_button1.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	GPIO_Init(&user_button1);

	for(;;){
		if(GPIO_ReadFromInputPin(GPIOC,GPIO_PIN_NO_13) == 0){
			GPIO_ToggleOutputPin(GPIOA,GPIO_PIN_NO_5);
			delay();
			while (GPIO_ReadFromInputPin(GPIOC, GPIO_PIN_NO_13) == 0);
		}
	}
}


