/*
 * stm32f446xx_spi_driver.h
 *
 *  Created on: Sep 11, 2026
 *      Author: user
 */

#ifndef INC_STM32F446XX_SPI_DRIVER_H_
#define INC_STM32F446XX_SPI_DRIVER_H_

#include "stm32f446xx.h"

typedef struct{
	uint8_t SPI_ClockMode;
	uint8_t SPI_DeviceRole;
	uint8_t SPI_BaudRatePrescaler;
	uint8_t SPI_DataBitNo;
	uint8_t SPI_BusConfig;
	uint8_t SPI_NSSConfig;
}SPI_Config_t;

typedef struct{
	SPI_RegDef_t *SPIx;
	SPI_Config_t SPI_Config;
}SPI_Handle_t;

/*
 * SPI clock mode configuration macros
 */
#define SPI_CLK_MODE_0				0x0
#define SPI_CLK_MODE_1				0x1
#define SPI_CLK_MODE_2				0x2
#define SPI_CLK_MODE_3				0x3

/*
 * SPI device role configuration macros
 */
#define SPI_ROLE_SLAVE				0x0
#define SPI_ROLE_MASTER				0x1

/*
 * SPI clock baud rate prescaler configuration macros
 */
#define SPI_BR_PRE_2				0x0
#define SPI_BR_PRE_4				0x1
#define SPI_BR_PRE_8				0x2
#define SPI_BR_PRE_16				0x3
#define SPI_BR_PRE_32				0x4
#define SPI_BR_PRE_64				0x5
#define SPI_BR_PRE_128				0x6
#define SPI_BR_PRE_256				0x7

/*
 * SPI number of the bits of the data configuration macros
 */
#define SPI_BIT_NO_8				0x0
#define SPI_BIT_NO_16				0x1

/*
 * SPI bus configuration macros
 */
#define SPI_FULL_DUPLEX				0
#define SPI_HALF_DUPLEX				1
#define SPI_SIMPLEX					2

/*
 * SPI NSS configuration macros
 */
#define SPI_NSS_HARDWARE			0x0
#define SPI_NSS_SOFTWARE			0x1

/*
 * SPI status flag name macros
 */
#define SPI_FLAG_RXNE 				0x0
#define SPI_FLAG_TXE 				0x1
#define SPI_FLAG_BSY				0x7

/*********************************************************************************
 * 							APIs supported by this driver
 * 		For more information abput the APIs check the function definitions
 *********************************************************************************/

/*
 * Peripheral Clock Setup
 */
void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi);

/*
 * Init and De-init
 */
void SPI_Init(SPI_Handle_t *pSPIHandle);
void SPI_DeInit(SPI_RegDef_t *pSPIx);

/*
 * Send Data
 */
void SPI_SendData(SPI_Handle_t *pSPIHandle, uint8_t *pData, uint32_t len);

/*
 * Receive Data
 */
void SPI_ReceiveData(SPI_Handle_t *pSPIHandle, uint8_t *pData, uint32_t len);

/*
 * Peripheral Control
 */
void SPI_PeripheralControl(SPI_RegDef_t * SPIx, uint8_t EnorDi);


/*
 * Other Control APIs
 */
uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint8_t FlagName);



#endif /* INC_STM32F446XX_SPI_DRIVER_H_ */
