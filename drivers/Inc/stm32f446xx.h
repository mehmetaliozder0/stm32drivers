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

#define RCC_BASEADDR                  (AHB1PERIPH_BASEADDR + 0x3800)

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
	volatile uint32_t MODER;        // GPIO port mode register                                                                      address offset: 0x00
	volatile uint32_t OTYPER;		// GPIO port output type register																address offset: 0x04
	volatile uint32_t OSPEEDER;     // GPIO port output speed register																address offset: 0x08
	volatile uint32_t PUPDR;        // GPIO port pull-up/pull-down register															address offset: 0x0C
	volatile uint32_t IDR;          // GPIO port input data register																address offset: 0x10
	volatile uint32_t ODR;          // GPIO port output data register																address offset: 0x14
	volatile uint32_t BSRR;         // GPIO port bit set/reset register																address offset: 0x18
	volatile uint32_t LCKR;         // GPIO port configuration lock register														address offset: 0x1C
	volatile uint32_t AFR[2];       // AFR[0]:GPIO alternate function low register & AFR[1]:GPIO alternate function high register   address offset: 0x20
}GPIO_RegDef_t;

typedef struct
{
	volatile uint32_t CR;             // RCC clock control register                                                address offset: 0x00
	volatile uint32_t PLLCFGR;        // RCC PLL configuration register                                            address offset: 0x04
	volatile uint32_t CFGR;           // RCC clock configuration register                                          address offset: 0x08
	volatile uint32_t CIR;            // RCC clock interrupt register                                              address offset: 0x0C
	volatile uint32_t AHB1RSTR;       // RCC AHB1 peripheral reset register                                        address offset: 0x10
	volatile uint32_t AHB2RSTR;       // RCC AHB2 peripheral reset register                                        address offset: 0x14
	volatile uint32_t AHB3RSTR;       // RCC AHB3 peripheral reset register                                        address offset: 0x18
	uint32_t RESERVED0;               // RESERVED
	volatile uint32_t APB1RSTR;       // RCC APB1 peripheral reset register                                        address offset: 0x20
	volatile uint32_t APB2RSTR;       // RCC APB2 peripheral reset register                                        address offset: 0x24
	uint32_t RESERVED1[2];			  // RESERVED
	volatile uint32_t AHB1ENR;        // RCC AHB1 peripheral clock enable register                                 address offset: 0x30
	volatile uint32_t AHB2ENR;        // RCC AHB2 peripheral clock enable register                                 address offset: 0x34
	volatile uint32_t AHB3ENR;        // RCC AHB3 peripheral clock enable register                                 address offset: 0x38
	uint32_t RESERVED2;				  // RESERVED
	volatile uint32_t APB1ENR;        // RCC APB1 peripheral clock enable register                                 address offset: 0x40
	volatile uint32_t APB2ENR;        // RCC APB2 peripheral clock enable register                                 address offset: 0x44
	uint32_t RESERVED3[2];			  // RESERVED
	volatile uint32_t AHB1LPENR;      // RCC AHB1 peripheral clock enable in low power mode register               address offset: 0x50
	volatile uint32_t AHB2LPENR;      // RCC AHB2 peripheral clock enable in low power mode register               address offset: 0x54
	volatile uint32_t AHB3LPENR;      // RCC AHB3 peripheral clock enable in low power mode register               address offset: 0x58
	uint32_t RESERVED4;               // RESERVED
	volatile uint32_t APB1LPENR;      // RCC APB1 peripheral clock enable in low power mode register               address offset: 0x60
	volatile uint32_t APB2LPENR;      // RCC APB2 peripheral clock enabled in low power mode register              address offset: 0x64
	uint32_t RESERVED5[2];			  // RESERVED
	volatile uint32_t BDCR;           // RCC Backup domain control register                                        address offset: 0x70
	volatile uint32_t CSR;            // RCC clock control and status register                                     address offset: 0x74
	uint32_t RESERVED6[2];			  // RESERVED
	volatile uint32_t SSCGR;          // RCC spread spectrum clock generation register                             address offset: 0x80
	volatile uint32_t PLLI2SCFGR;     // RCC PLLI2S configuration register                                         address offset: 0x84
	volatile uint32_t PLLSAICFGR;     // PLLSAICFGR                                                                address offset: 0x88
	volatile uint32_t DCKCFGR;        // RCC dedicated clock configuration register                                address offset: 0x8C
	volatile uint32_t CKGATENR;       // RCC clocks gated enable register                                          address offset: 0x90
	volatile uint32_t DCKCFGR2;       // RCC dedicated clocks configuration register 2                             address offset: 0x94
}RCC_RegDef_t;


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

#define RCC                	 ((RCC_RegDef_t*) RCC_BASEADDR)

/*
 * Clock Enable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_EN()     (RCC->AHB1ENR |= (1 << 0))
#define GPIOB_PCLK_EN()     (RCC->AHB1ENR |= (1 << 1))
#define GPIOC_PCLK_EN()     (RCC->AHB1ENR |= (1 << 2))
#define GPIOD_PCLK_EN()     (RCC->AHB1ENR |= (1 << 3))
#define GPIOE_PCLK_EN()     (RCC->AHB1ENR |= (1 << 4))
#define GPIOF_PCLK_EN()     (RCC->AHB1ENR |= (1 << 5))
#define GPIOG_PCLK_EN()     (RCC->AHB1ENR |= (1 << 6))
#define GPIOH_PCLK_EN()     (RCC->AHB1ENR |= (1 << 7))

/*
 * Clock Enable Macros for I2Cx peripherals
 */

#define I2C1_PCLK_EN()     (RCC->APB1ENR |= (1 << 21))
#define I2C2_PCLK_EN()     (RCC->APB1ENR |= (1 << 22))
#define I2C3_PCLK_EN()     (RCC->APB1ENR |= (1 << 23))

/*
 * Clock Enable Macros for SPIx peripherals
 */

#define SPI1_PCLK_EN()     (RCC->APB2ENR |= (1 << 12))
#define SPI2_PCLK_EN()     (RCC->APB1ENR |= (1 << 14))
#define SPI3_PCLK_EN()     (RCC->APB1ENR |= (1 << 15))


/*
 * Clock Enable Macros for USARTx peripherals
 */

#define USART1_PCLK_EN()     (RCC->APB2ENR |= (1 << 4))
#define USART2_PCLK_EN()     (RCC->APB1ENR |= (1 << 17))
#define USART3_PCLK_EN()     (RCC->APB1ENR |= (1 << 18))
#define UART4_PCLK_EN()      (RCC->APB1ENR |= (1 << 19))
#define UART5_PCLK_EN()      (RCC->APB1ENR |= (1 << 20))
#define USART6_PCLK_EN()     (RCC->APB2ENR |= (1 << 5))

/*
 * Clock Disable Macros for GPIOx peripherals
 */

#define GPIOA_PCLK_DI()     (RCC->AHB1ENR &= ~(1 << 0))
#define GPIOB_PCLK_DI()     (RCC->AHB1ENR &= ~(1 << 1))
#define GPIOC_PCLK_DI()     (RCC->AHB1ENR &= ~(1 << 2))
#define GPIOD_PCLK_DI()     (RCC->AHB1ENR &= ~(1 << 3))
#define GPIOE_PCLK_DI()     (RCC->AHB1ENR &= ~(1 << 4))
#define GPIOF_PCLK_DI()     (RCC->AHB1ENR &= ~(1 << 5))
#define GPIOG_PCLK_DI()     (RCC->AHB1ENR &= ~(1 << 6))
#define GPIOH_PCLK_DI()     (RCC->AHB1ENR &= ~(1 << 7))

/*
 * Clock Disable Macros for I2Cx peripherals
 */

#define I2C1_PCLK_DI()     (RCC->APB1ENR &= ~(1 << 21))
#define I2C2_PCLK_DI()     (RCC->APB1ENR &= ~(1 << 22))
#define I2C3_PCLK_DI()     (RCC->APB1ENR &= ~(1 << 23))

/*
 * Clock Disable Macros for SPIx peripherals
 */

#define SPI1_PCLK_DI()     (RCC->APB2ENR &= ~(1 << 12))
#define SPI2_PCLK_DI()     (RCC->APB1ENR &= ~(1 << 14))
#define SPI3_PCLK_DI()     (RCC->APB1ENR &= ~(1 << 15))


/*
 * Clock Disable Macros for USARTx peripherals
 */

#define USART1_PCLK_DI()     (RCC->APB2ENR &= ~(1 << 4))
#define USART2_PCLK_DI()     (RCC->APB1ENR &= ~(1 << 17))
#define USART3_PCLK_DI()     (RCC->APB1ENR &= ~(1 << 18))
#define UART4_PCLK_DI()      (RCC->APB1ENR &= ~(1 << 19))
#define UART5_PCLK_DI()      (RCC->APB1ENR &= ~(1 << 20))
#define USART6_PCLK_DI()     (RCC->APB2ENR &= ~(1 << 5))







#endif /* INC_STM32F446XX_H_ */
