/**
 ******************************************************************************
 * @file    004_button_interrupt.c
 * @author  Mehmet Ali Özder
 * @brief   STM32F446xx GPIO Driver - Button Interrupt Controlled LED Toggle Application
 * @date    2026-09-07
 ******************************************************************************
 * @details
 * This application tests GPIO external interrupt (EXTI) functionality by
 * capturing user button press events via NVIC to toggle the on-board LED.
 *
 * Pin Configuration:
 *  - LED (Output)         : Port GPIOA, Pin 5 (On-board LED / LD2)
 *  - Button (Interrupt)   : Port GPIOC, Pin 13 (On-board User Button / B1)
 *
 * Interrupt Configuration:
 *  - Trigger Edge         : Falling Edge (GPIO_MODE_IT_FT)
 *  - Pull Configuration   : Internal Pull-Up (GPIO_PIN_PU)
 *  - EXTI Line            : EXTI13
 *  - NVIC IRQ Number      : IRQ_NO_EXTI15_10 (IRQ 40)
 *  - Priority             : NVIC_IRQ_PRI15 (15)
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f446xx_gpio_driver.h"

int main(void)
{
	// 1. Configure On-board Green LED (PA5)
	GPIO_PeriClockControl(GPIOA, ENABLE);
	GPIO_Handle_t user_led2 = {0};
	user_led2.pGPIOx = GPIOA;
	user_led2.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_5;
	user_led2.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	user_led2.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	user_led2.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;
	user_led2.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_NO_PUPD;
	GPIO_Init(&user_led2);

	// 2. Configure On-board Blue User Button (PC13) in Interrupt Mode
	GPIO_PeriClockControl(GPIOC, ENABLE);
	GPIO_Handle_t user_button1 = {0};
	user_button1.pGPIOx = GPIOC;
	user_button1.GPIO_PinConfig.GPIO_PinNumber = GPIO_PIN_NO_13;
	user_button1.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_IT_FT;
	user_button1.GPIO_PinConfig.GPIO_PinPuPdControl = GPIO_PIN_PU;
	GPIO_Init(&user_button1);

	// 3. Configure NVIC Priority and Enable IRQ Delivery
	GPIO_IRQPriorityConfig(IRQ_NO_EXTI15_10, NVIC_IRQ_PRI15);
	GPIO_IRQInterruptConfig(IRQ_NO_EXTI15_10, ENABLE);

	/* Loop forever */
	for(;;);
}

/**
 * @brief  ISR for EXTI lines 10 to 15 (Handles PC13 Button Interrupt)
 */
void EXTI15_10_IRQHandler(void){
	// Clear pending flag
	GPIO_IRQHandling(GPIO_PIN_NO_13);
	// Toggle output LED
	GPIO_ToggleOutputPin(GPIOA, GPIO_PIN_NO_5);

}


