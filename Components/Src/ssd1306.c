/*
 * ssd1306.c
 *
 *  Created on: Sep 17, 2026
 *      Author: user
 */

#include "ssd1306.h"

static uint8_t SSD1306_Buffer[1024];

static void delay_ms(uint32_t ms){
	for(volatile uint32_t i = 0; i<(ms * 4000); i++);
}

static SPI_Handle_t *pOLED_SPI;

/* Pin configuration function for oled pins*/
static void OLED_GPIO_Init(void){
	GPIO_Handle_t OledPinsConfigs = {0};

	OledPinsConfigs.GPIO_PinConfig.GPIO_PinMode = GPIO_MODE_OUT;
	OledPinsConfigs.GPIO_PinConfig.GPIO_PinOPType = GPIO_OP_TYPE_PP;
	OledPinsConfigs.GPIO_PinConfig.GPIO_PinSpeed = GPIO_SPEED_FAST;

	/*CS pin*/
	OledPinsConfigs.pGPIOx = SSD1306_CS_PORT;
	OledPinsConfigs.GPIO_PinConfig.GPIO_PinNumber = SSD1306_CS_PIN;
	GPIO_PeriClockControl(SSD1306_CS_PORT, ENABLE);
	GPIO_Init(&OledPinsConfigs);
	GPIO_WriteToOutputPin(SSD1306_CS_PORT, SSD1306_CS_PIN, SET);

	/*DC pin*/
	OledPinsConfigs.pGPIOx = SSD1306_DC_PORT;
	OledPinsConfigs.GPIO_PinConfig.GPIO_PinNumber = SSD1306_DC_PIN;
	GPIO_PeriClockControl(SSD1306_DC_PORT, ENABLE);
	GPIO_Init(&OledPinsConfigs);

	/*RES pin*/
	OledPinsConfigs.pGPIOx = SSD1306_RES_PORT;
	OledPinsConfigs.GPIO_PinConfig.GPIO_PinNumber = SSD1306_RES_PIN;
	GPIO_PeriClockControl(SSD1306_RES_PORT, ENABLE);
	GPIO_Init(&OledPinsConfigs);
}

/*Reset*/
static void OLED_Reset(void){
	GPIO_WriteToOutputPin(SSD1306_RES_PORT, SSD1306_RES_PIN, DISABLE);
	delay_ms(10);
	GPIO_WriteToOutputPin(SSD1306_RES_PORT, SSD1306_RES_PIN, ENABLE);
	delay_ms(10);
}

/*Init and Deinit*/
void OLED_Init(SPI_Handle_t *pSPIHandle){
	pOLED_SPI = pSPIHandle;
	OLED_GPIO_Init();
	OLED_Reset();

	OLED_WriteCommand(0xA8); 	/*Set MUX Ratio*/
	OLED_WriteCommand(0x3F);	/**/
	OLED_WriteCommand(0xD3);	/*Set Display Offset*/
	OLED_WriteCommand(0x00);	/**/
	OLED_WriteCommand(0x40);	/*Set Display Start Line*/
	OLED_WriteCommand(0xA1);	/*Set Segment re-map*/
	OLED_WriteCommand(0xC8);	/*Set COM Output Scan Direction*/
	OLED_WriteCommand(0xDA);	/*Set COM Pins hardware configuration*/
	OLED_WriteCommand(0x12);	/**/
	OLED_WriteCommand(0x81);	/*Set Contrast Control*/
	OLED_WriteCommand(0x7F);	/**/
	OLED_WriteCommand(0xA4);	/*Disable Entire Display On*/
	OLED_WriteCommand(0xA6);	/*Set Normal Display*/
	OLED_WriteCommand(0xD5);	/*Set Osc Frequency*/
	OLED_WriteCommand(0x80);	/**/
	OLED_WriteCommand(0x8D);	/*Enable charge pump regulator*/
	OLED_WriteCommand(0x14);	/**/
	OLED_WriteCommand(0x20);	/* Set Memory Addressing Mode*/
	OLED_WriteCommand(0x00);	/* 0x00 = Horizontal Addressing Mode */
	OLED_WriteCommand(0xAF);	/*Display On*/
}

/* Send data and command*/
void OLED_WriteData(uint8_t *pData, uint32_t len){
	GPIO_WriteToOutputPin(SSD1306_DC_PORT, SSD1306_DC_PIN, ENABLE);
	GPIO_WriteToOutputPin(SSD1306_CS_PORT, SSD1306_CS_PIN, DISABLE);
	SPI_SendData(pOLED_SPI,pData, len);
	while(SPI_GetFlagStatus(pOLED_SPI->SPIx, SPI_FLAG_BSY));
	GPIO_WriteToOutputPin(SSD1306_CS_PORT, SSD1306_CS_PIN, ENABLE);
}

void OLED_WriteCommand(uint8_t cmd){
	GPIO_WriteToOutputPin(SSD1306_DC_PORT, SSD1306_DC_PIN, DISABLE);
	GPIO_WriteToOutputPin(SSD1306_CS_PORT, SSD1306_CS_PIN, DISABLE);
	SPI_SendData(pOLED_SPI, &cmd, 1);
	while(SPI_GetFlagStatus(pOLED_SPI->SPIx, SPI_FLAG_BSY));
	GPIO_WriteToOutputPin(SSD1306_CS_PORT, SSD1306_CS_PIN, ENABLE);
}

/*Filling buffer function*/
void OLED_Fill(uint8_t color)
{
    uint8_t fill_val = (color == 0) ? 0x00 : 0xFF;

    for(uint32_t i = 0; i < sizeof(SSD1306_Buffer); i++)
    {
        SSD1306_Buffer[i] = fill_val;
    }
}

void OLED_FillRectangle(uint8_t x_start, uint8_t y_start, uint8_t x_finish, uint8_t y_finish, uint8_t color){
	for(uint8_t i = x_start; i<x_finish; i++){
		for(uint8_t j = y_start; j<y_finish; j++){
			OLED_DrawPixel(i,j, color);
		}
	}
}

/* Screen Update*/
void OLED_UpdateScreen(void)
{
    OLED_WriteCommand(0x21); // Set Column Address
    OLED_WriteCommand(0X00); // First Column: 0
    OLED_WriteCommand(0x7F); // Last Column: 127

    OLED_WriteCommand(0x22); // Set Page Address
    OLED_WriteCommand(0x00); // First page: 0
    OLED_WriteCommand(0x07); // Last Page: 7 (8 pages x 8 pixels = 64 rows)

    OLED_WriteData(SSD1306_Buffer, sizeof(SSD1306_Buffer));
}

void OLED_DrawPixel(uint8_t x, uint8_t y, uint8_t color){
	if((x > 127) || (y > 63)) return;
	uint8_t page = y/8; 	/*page 0 to page 7*/
	uint8_t segment = x; 	/*segment 0 to segment 127*/
	uint8_t row = y%8; 		/*row 0 to row 7 of the page*/
	uint16_t byte_no = page*128 + segment;
	if(color == 1){
		SSD1306_Buffer[byte_no] |= (0x1 << row);
	}
	else if(color == 0){
		SSD1306_Buffer[byte_no] &= ~(0x1 << row);
	}
}

void OLED_DrawChar(uint8_t x, uint8_t y, char ch, uint8_t color){
	if((ch < 32) || (ch > 128)) return;
	for(uint8_t i = 0; i<8; i++){
		for(uint8_t j = 0; j<8; j++){
			if(FONT8x8[ch - 32][i] & (0x1 << j)){
				OLED_DrawPixel(x+i,y+j, color);
			}
		}
	}
}

void OLED_DrawString(uint8_t x, uint8_t y, const char *text, uint8_t color){
	while(*text){
		OLED_DrawChar(x,y,*text,color);
		x+=8;
		text++;
	}
}

void OLED_DrawImage(uint8_t x, uint8_t y, uint8_t width, uint8_t length, const uint8_t *bitmap, uint8_t color){
	for(uint8_t j = 0; j<(length/8); j++){
		for(uint8_t i = 0; i<width; i++){
			for(uint8_t k = 0; k<8; k++){
				if((*(bitmap+j*width+i) & (0x1 << k))){
					OLED_DrawPixel(x+i,y+(8*j)+k, color);
				}
			}
		}
	}
}



