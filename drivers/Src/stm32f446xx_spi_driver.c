/*
 * stm32f446xx_spi_driver.c
 *
 *  Created on: Sep 11, 2026
 *      Author: user
 */

#include "stm32f446xx_spi_driver.h"

/*
 * Peripheral Clock Setup
 */

void SPI_PeriClockControl(SPI_RegDef_t *pSPIx, uint8_t EnorDi){
	if(EnorDi == ENABLE){
		if(pSPIx == SPI1){
			SPI1_PCLK_EN();
		}
		else if(pSPIx == SPI2){
			SPI2_PCLK_EN();
		}
		else if(pSPIx == SPI3){
			SPI3_PCLK_EN();
		}
	}
	else{
		if(pSPIx == SPI1){
			SPI1_PCLK_DI();
		}
		else if(pSPIx == SPI2){
			SPI2_PCLK_DI();
		}
		else if(pSPIx == SPI3){
			SPI3_PCLK_DI();
		}
	}
}

/*
 * Init and De-init
 */
void SPI_Init(SPI_Handle_t *pSPIHandle){
	uint32_t tempreg = 0;

	/* Clock Mode Configuration*/
	tempreg |= pSPIHandle->SPI_Config.SPI_ClockMode;

	/* Device Role Configuration*/
	tempreg |= (pSPIHandle->SPI_Config.SPI_DeviceRole << 2);

	/* Baud Rate Prescaler Configuration*/
	tempreg |= (pSPIHandle->SPI_Config.SPI_BaudRatePrescaler << 3);

	/* Number of the Bits of the Data Configuration*/
	tempreg |= (pSPIHandle->SPI_Config.SPI_DataBitNo << 11);

	/* Bus Configuration*/
	if(pSPIHandle->SPI_Config.SPI_BusConfig == SPI_FULL_DUPLEX){
		tempreg &= ~(0x1 << 10);
		tempreg &= ~(0x1 << 15);
	}
	else if(pSPIHandle->SPI_Config.SPI_BusConfig == SPI_HALF_DUPLEX){
		tempreg &= ~(0x1 << 10);
		tempreg |= (0x1 << 15);
	}
	else if(pSPIHandle->SPI_Config.SPI_BusConfig == SPI_SIMPLEX){
		tempreg |= (0x1 << 10);
		tempreg &= ~(0x1 << 15);
	}

	/*NSS configuration*/
	tempreg |= (pSPIHandle->SPI_Config.SPI_NSSConfig << 9);
	if(pSPIHandle->SPI_Config.SPI_NSSConfig == SPI_NSS_SOFTWARE){
		if(pSPIHandle->SPI_Config.SPI_DeviceRole == SPI_ROLE_MASTER){
			tempreg |= (0x1 << 8);
		}
		else if(pSPIHandle->SPI_Config.SPI_DeviceRole == SPI_ROLE_SLAVE){
			tempreg &= ~(0x1 << 8);
		}
	}
	else if(pSPIHandle->SPI_Config.SPI_NSSConfig == SPI_NSS_HARDWARE){
		pSPIHandle->SPIx->CR[1] |= (0x1 << 2);
	}

	pSPIHandle->SPIx->CR[0] = tempreg;
}

void SPI_DeInit(SPI_RegDef_t *pSPIx){
	if(pSPIx == SPI1){
		SPI1_RESET();
	}
	else if(pSPIx == SPI2){
		SPI2_RESET();
	}
	else if(pSPIx == SPI3){
		SPI3_RESET();
	}
}

/*
 * Send Data
 */
void SPI_SendData(SPI_Handle_t *pSPIHandle, uint8_t *pData, uint32_t len){
	if(pSPIHandle->SPI_Config.SPI_DataBitNo == SPI_BIT_NO_8){
		for(uint8_t i = 0; i<len; i++){
			while(SPI_GetFlagStatus(pSPIHandle->SPIx, SPI_FLAG_TXE) == 0);
			pSPIHandle->SPIx->DR = *(pData+i);
		}
	}
	else if(pSPIHandle->SPI_Config.SPI_DataBitNo == SPI_BIT_NO_16){
		uint16_t* pData1 = (uint16_t*) pData;
		for(uint8_t i = 0; i<(len/2); i++){
			while(SPI_GetFlagStatus(pSPIHandle->SPIx, SPI_FLAG_TXE) == 0);
			pSPIHandle->SPIx->DR = *(pData1+i);
		}
	}
}

/*
 * Other Control APIs
 */
uint8_t SPI_GetFlagStatus(SPI_RegDef_t *pSPIx, uint8_t FlagName){
	return ((pSPIx->SR & (0x1 << FlagName)) >> FlagName);
}

