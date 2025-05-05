/*
 * SSD1306_OLED.c
 *
 *  Created on: Apr 22, 2025
 *      Author: Mert
 */

#include "SSD1306_OLED.h"
#include "FONT.h"

extern uint8_t Char_Bitmap[26][6];


void OLED_WriteCommand(uint8_t Command)
{
	uint8_t data[2] = {0};
	data[0] = COMMAND_ID;
	data[1] = Command;

	HAL_I2C_Master_Transmit(OLED_I2C, OLED_ADDR_WRITE, data, 2, HAL_MAX_DELAY);
}

void SSD1306_WriteData(uint8_t* data, uint16_t size) {
    uint8_t control = DATA_ID; // Co = 0, D/C# = 1 (veri)
    HAL_I2C_Mem_Write(&hi2c1, OLED_ADDR_WRITE, control, I2C_MEMADD_SIZE_8BIT, data, size, HAL_MAX_DELAY);
}

void OLED_Display_Init(void)
{
	//Display OFF
	OLED_WriteCommand(0xAE);

	//Set Contrast Control
	OLED_WriteCommand(0x81);
	OLED_WriteCommand(0xFF);

	//Set Normal/Inverse Display
	OLED_WriteCommand(0xA6);

	//Set Memory Addressing Mode
	OLED_WriteCommand(0x20);
	OLED_WriteCommand(0x10);	//Page addressing mode


/*	//Set Page Start Address for Page Addressing Mode
	OLED_WriteCommand(0xB0);
*/

	//Set Display Start Line
	OLED_WriteCommand(0x7F);

	//Set Segment Re-map
	OLED_WriteCommand(0xA0);

	//Set Multiplex Ratio
	OLED_WriteCommand(0xA8);
	OLED_WriteCommand(0x3F);

	//Set COM Output Scan Direction
	OLED_WriteCommand(0xC0);

	//Set Display Offset
	OLED_WriteCommand(0xD3);
	OLED_WriteCommand(0x00);

	//Set COM Pins Hardware Configuration
	OLED_WriteCommand(0xDA);
	OLED_WriteCommand(0x00);

	//Set Display Clock Divide Ration/Oscillator Frequency
	OLED_WriteCommand(0xD5);
	OLED_WriteCommand(0x00);

	//Display ON
	OLED_WriteCommand(0xAF);
}

void OLED_FillScreen(uint8_t color)
{
    for(uint8_t page = 0; page < 8; page++)
    {
        OLED_WriteCommand(0xB0 + page);   // Set page address
        OLED_WriteCommand(0x00);          // Set lower column address
        OLED_WriteCommand(0x10);          // Set higher column address

        for(uint8_t col = 0; col < 128; col++)
        {
            uint8_t data[2];
            data[0] = 0x40;                  // Data mode
            data[1] = color;                 // Pixel data (0xFF = beyaz, 0x00 = siyah)

            HAL_I2C_Master_Transmit(OLED_I2C, OLED_ADDR_WRITE, data, 2, HAL_MAX_DELAY);
        }
    }
}

void SSD1306_WriteChar(char Char)
{
//	if((Char != 32) || Char < 65 || Char > 90) return;

	uint8_t index = 0;

	if(Char != 32)
	{
		index = Char - 64;
	}

	else if(Char == 32)
	{
		index = Char - 32;
	}

	for(uint8_t i = 0; i<6; i++)
	{
		SSD1306_WriteData(&Char_Bitmap[index][i], sizeof(Char_Bitmap[index][i]));
	}

}
