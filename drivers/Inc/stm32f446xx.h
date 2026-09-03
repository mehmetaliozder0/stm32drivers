/*
 * stm32f446xx.h
 *
 *  Created on: Sep 3, 2026
 *      Author: user
 */

#ifndef INC_STM32F446XX_H_
#define INC_STM32F446XX_H_

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






#endif /* INC_STM32F446XX_H_ */
