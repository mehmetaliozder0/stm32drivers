/*
 * stm32f446xx_gpio_driver.c
 *
 *  Created on: Sep 3, 2026
 *      Author: user
 */

#include "stm32f446xx_gpio_driver.h"


/*
 * Peripheral Clock Setup
 */
void GPIO_PeriClockControl(GPIO_RegDef_t *pGPIOx, uint8_t EnOrDi){
	if(EnOrDi == ENABLE){
		if(pGPIOx == GPIOA){
			GPIOA_PCLK_EN();
		}
		else if(pGPIOx == GPIOB){
			GPIOB_PCLK_EN();

		}
		else if(pGPIOx == GPIOC){
			GPIOC_PCLK_EN();

		}
		else if(pGPIOx == GPIOD){
			GPIOD_PCLK_EN();

		}
		else if(pGPIOx == GPIOE){
			GPIOE_PCLK_EN();

		}
		else if(pGPIOx == GPIOF){
			GPIOF_PCLK_EN();

		}
		else if(pGPIOx == GPIOG){
			GPIOG_PCLK_EN();

		}
		else if(pGPIOx == GPIOH){
			GPIOH_PCLK_EN();

		}
	}
	else{
		if(pGPIOx == GPIOA){
			GPIOA_PCLK_DI();
		}
		else if(pGPIOx == GPIOB){
			GPIOB_PCLK_DI();

		}
		else if(pGPIOx == GPIOC){
			GPIOC_PCLK_DI();

		}
		else if(pGPIOx == GPIOD){
			GPIOD_PCLK_DI();

		}
		else if(pGPIOx == GPIOE){
			GPIOE_PCLK_DI();

		}
		else if(pGPIOx == GPIOF){
			GPIOF_PCLK_DI();

		}
		else if(pGPIOx == GPIOG){
			GPIOG_PCLK_DI();

		}
		else if(pGPIOx == GPIOH){
			GPIOH_PCLK_DI();

		}
	}
}

/*
 * Init and De-init
 */
void GPIO_Init(GPIO_Handle_t *pGPIOHandle){
	uint32_t temp = 0;
	//1 - configure the mode of the gpio pin
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode <= GPIO_MODE_ANALOG){
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinMode << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
		pGPIOHandle->pGPIOx->MODER |= temp;
	}
	else{

	}
	//2 - configure the speed
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinSpeed << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDER &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OSPEEDER |= temp;

	//3- configure the pupd settings
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinPuPdControl << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR &= ~(0x3 << (2 * pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->PUPDR |= temp;

	//4- configure the optype
	temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinOPType << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER &= ~(0x1 << (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber));
	pGPIOHandle->pGPIOx->OTYPER |= temp;

	//5- configure
	if(pGPIOHandle->GPIO_PinConfig.GPIO_PinMode == GPIO_MODE_ALTFN){
		uint8_t temp1, temp2;
		temp1 = (pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) / 8;
		temp2 = ((pGPIOHandle->GPIO_PinConfig.GPIO_PinNumber) % 8);
		temp = (pGPIOHandle->GPIO_PinConfig.GPIO_PinAltFunMode << (4 * temp2));
		pGPIOHandle->pGPIOx->AFR[temp1] &= ~(0xF << (4 * temp2));
		pGPIOHandle->pGPIOx->AFR[temp1] |= temp;
	}
}
void GPIO_DeInit(GPIO_RegDef_t *pGPIOx){

	if(pGPIOx == GPIOA){
		GPIOA_RESET();
	}
	else if(pGPIOx == GPIOB){
		GPIOB_RESET();
	}
	else if(pGPIOx == GPIOC){
		GPIOC_RESET();
	}
	else if(pGPIOx == GPIOD){
		GPIOD_RESET();
	}
	else if(pGPIOx == GPIOE){
		GPIOE_RESET();
	}
	else if(pGPIOx == GPIOF){
		GPIOF_RESET();
	}
	else if(pGPIOx == GPIOG){
		GPIOG_RESET();
	}
	else if(pGPIOx == GPIOH){
		GPIOH_RESET();
	}
}

/*
 * Data read and write
 */
uint8_t GPIO_ReadFromInputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){
	uint8_t value;
	value = ((pGPIOx->IDR >> PinNumber) & 0x1);
	return value;
}
uint16_t GPIO_ReadFromInputPort(GPIO_RegDef_t *pGPIOx){
	uint16_t value;
	value = (uint16_t)(pGPIOx->IDR);
	return value;
}
void GPIO_WriteToOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber, uint8_t Value){
	if(Value == GPIO_PIN_SET){
		pGPIOx->ODR |= (0x1 << PinNumber);
	}
	else{
		pGPIOx->ODR &= ~(0x1 << PinNumber);
	}
}
void GPIO_WriteToOutputPort(GPIO_RegDef_t *pGPIOx, uint16_t Value){
	pGPIOx->ODR = Value;
}
void GPIO_ToggleOutputPin(GPIO_RegDef_t *pGPIOx, uint8_t PinNumber){
	pGPIOx->ODR ^= (0x1 << PinNumber);
}

/*
 *  IRQ Configuration and ISR handling
 */
void GPIO_IRQConfig(uint8_t IRQNumber, uint8_t IRQPriority, uint8_t EnOrDi){

}
void GPIO_IRQHandling(uint8_t PinNumber){

}


