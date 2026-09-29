/*
 * ssd1306.h
 *
 *  Created on: Sep 17, 2026
 *      Author: user
 */

#ifndef INC_SSD1306_H_
#define INC_SSD1306_H_

#include "stm32f446xx_gpio_driver.h"
#include "stm32f446xx_spi_driver.h"
#include "fonts.h"

/* PIN MACROS FOR OLED PINS*/
#define SSD1306_CS_PORT		GPIOA
#define SSD1306_CS_PIN 		GPIO_PIN_NO_8

#define SSD1306_DC_PORT		GPIOA
#define SSD1306_DC_PIN		GPIO_PIN_NO_9

#define SSD1306_RES_PORT	GPIOA
#define SSD1306_RES_PIN		GPIO_PIN_NO_10

/*Init and Deinit*/
void OLED_Init(SPI_Handle_t *pSPIHandle);

/* Send data and command*/
void OLED_WriteData(uint8_t *pData, uint32_t len);
void OLED_WriteCommand(uint8_t cmd);

/*Filling buffer function*/
void OLED_Fill(uint8_t color);
void OLED_FillRectangle(uint8_t x_start, uint8_t y_start, uint8_t x_finish, uint8_t y_finish, uint8_t color);

void OLED_UpdateScreen(void);

void OLED_DrawPixel(uint8_t x, uint8_t y, uint8_t color);
void OLED_DrawChar(uint8_t x, uint8_t y, char ch, uint8_t color);
void OLED_DrawString(uint8_t x, uint8_t y, const char *text, uint8_t color);
void OLED_DrawImage(uint8_t x, uint8_t y, uint8_t width, uint8_t length, const uint8_t *bitmap, uint8_t color);
#endif /* INC_SSD1306_H_ */
