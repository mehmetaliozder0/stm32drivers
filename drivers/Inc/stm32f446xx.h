/*
 * stm32f446xx.h
 *
 *  Created on: Sep 3, 2026
 *      Author: user
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

#include <stdint.h>

/*
 * base addresses of Flash and SRAM memories
 */

#define FLASH_BASEADDR               0x08000000U      /*base address of flash memory*/
#define SRAM1_BASEADDR               0x20000000U    /*base address of sram1*/
#define SRAM2_BASEADDR               0x2001C000U      /*base address of sram2*/
#define ROM_BASEADDR                 0x1FFF0000U      /*base address of rom*/
#define SRAM                         SRAM1_BASEADDR   /*base address of sram*/

/*
 * base addresses of AHBx APBx Bus Peripherals
 */

#define PERIPH_BASEADDR               0x40000000U      /*base address of peripheral registers*/
#define APB1PERIPH_BASEADDR           PERIPH_BASEADDR  /*base address of apb1 peripherals*/
#define APB2PERIPH_BASEADDR           0x40010000U      /*base address of apb2 peripherals */
#define AHB1PERIPH_BASEADDR           0x40020000U      /*base address of ahb1 peripherals*/
#define AHB2PERIPH_BASEADDR           0x50000000U      /*base address of ahb2 peripherals*/

/*
 * base addresses of AHB1 peripherals
 */

// GPIO PORTS
#define GPIOA_BASEADDR                (AHB1PERIPH_BASEADDR + 0x0000)
#define GPIOB_BASEADDR                (AHB1PERIPH_BASEADDR + 0x0400)
#define GPIOC_BASEADDR                (AHB1PERIPH_BASEADDR + 0x0800)
#define GPIOD_BASEADDR                (AHB1PERIPH_BASEADDR + 0x0C00)
#define GPIOE_BASEADDR                (AHB1PERIPH_BASEADDR + 0x1000)
#define GPIOF_BASEADDR                (AHB1PERIPH_BASEADDR + 0x1400)
#define GPIOG_BASEADDR                (AHB1PERIPH_BASEADDR + 0x1800)
#define GPIOH_BASEADDR                (AHB1PERIPH_BASEADDR + 0x1C00)

/*
 * base addresses of APB1 peripherals
 */

//I2C
#define I2C1_BASEADDR                  (APB1PERIPH_BASEADDR + 0x5400)
#define I2C2_BASEADDR                  (APB1PERIPH_BASEADDR + 0x5800)
#define I2C3_BASEADDR                  (APB1PERIPH_BASEADDR + 0x5C00)

//SPI
#define SPI2_BASEADDR                  (APB1PERIPH_BASEADDR + 0x3800)
#define SPI3_BASEADDR                  (APB1PERIPH_BASEADDR + 0x3C00)

// USART/UART
#define USART2_BASEADDR                (APB1PERIPH_BASEADDR + 0x4400)
#define USART3_BASEADDR                (APB1PERIPH_BASEADDR + 0x4800)
#define UART4_BASEADDR                 (APB1PERIPH_BASEADDR + 0x4C00)
#define UART5_BASEADDR                 (APB1PERIPH_BASEADDR + 0x5000)

/*
 * base addresses of APB2 peripherals
 */

#define SPI1_BASEADDR                  (APB1PERIPH_BASEADDR + 0x3000)

#define USART1_BASEADDR                (APB1PERIPH_BASEADDR + 0x1000)
#define USART6_BASEADDR                (APB1PERIPH_BASEADDR + 0x1400)

#define EXTI_BASEADDR                  (APB1PERIPH_BASEADDR + 0x3C00)
#define SYSCFG_BASEADDR                (APB1PERIPH_BASEADDR + 0x3800)



/*
 * peripheral register definition structures
 */

typedef struct
{
	volatile uint32_t MODER;        // GPIO port mode register
	volatile uint32_t OTYPER;		// GPIO port output type register
	volatile uint32_t OSPEEDER;     // GPIO port output speed register
	volatile uint32_t PUPDR;        // GPIO port pull-up/pull-down register
	volatile uint32_t IDR;          // GPIO port input data register
	volatile uint32_t ODR;          // GPIO port output data register
	volatile uint32_t BSRR;         // GPIO port bit set/reset register
	volatile uint32_t LCKR;         // GPIO port configuration lock register
	volatile uint32_t AFR[2];       // AFR[0]:GPIO alternate function low register & AFR[1]:GPIO alternate function high register
}GPIO_RegDef_t;


/*
 * Periphal base adresses typecasted to xxx_RegDef_t
 */

#define GPIOA                ((GPIO_RegDef_t*) GPIOA_BASEADDR)
#define GPIOB                ((GPIO_RegDef_t*) GPIOB_BASEADDR)
#define GPIOC                ((GPIO_RegDef_t*) GPIOC_BASEADDR)
#define GPIOD                ((GPIO_RegDef_t*) GPIOD_BASEADDR)
#define GPIOE                ((GPIO_RegDef_t*) GPIOE_BASEADDR)
#define GPIOF                ((GPIO_RegDef_t*) GPIOF_BASEADDR)
#define GPIOG                ((GPIO_RegDef_t*) GPIOG_BASEADDR)
#define GPIOH                ((GPIO_RegDef_t*) GPIOH_BASEADDR)





#endif /* INC_STM32F446XX_H_ */
