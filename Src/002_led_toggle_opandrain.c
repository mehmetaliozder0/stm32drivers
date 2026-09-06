/**
 ******************************************************************************
 * @file    002_led_toggle_opendrain.c
 * @author  Mehmet Ali Özder
 * @brief   STM32F446xx GPIO Driver - Open Drain LED Toggling Test Application
 * @date    2026-09-05
******************************************************************************
 * @details
 * This application verifies GPIO output operation in Open-Drain (OD) mode.
 *
 * Hardware Notes:
 *  - Internal Pull-Up (GPIO_PIN_PU): LED brightness will be negligible or off
 *    due to the high internal pull-up resistance (~40 kOhm).
 *  - Optional External Pull-Up: Connect a 470 Ohm - 1 kOhm resistor between
 *    PA5 (or an external GPIO pin) and 3.3V (VDD) for full LED brightness.
 ******************************************************************************
 */

#include "stm32f446xx_gpio_driver.h"

void delay(void){
	for(volatile uint32_t i =0;i<1000000;i++);
}

int main(void){
	GPIO_PeriClockControl(GPIOA, ENABLE);

	GPIO_Handle_t user_led2 = {0};

	user_led2.pGPIOx = GPIOA;
	user_led2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	user_led2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	user_led2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_OD;
	user_led2.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD; // No internal pull-up; external 1k pull-up connected between 3.3V and PA5 (D13)
	user_led2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	GPIO_Init(&user_led2);

	for(;;){
		GPIO_ToggleOutputPin(GPIOA,GPIO_PIN_NO_5);
		delay();
	}
}

