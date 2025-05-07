/*
 * SSD1306_OLED.c
 *
 *  Created on: Apr 22, 2025
 *      Author: Mert
 */

#include "SSD1306_OLED.h"
#include "FONT.h"

/*
 * Init fonksiyonu içerisinde ki her ayarlama için ayrı fonksiyonlar oluştur.
 * Kütüphaneyi daha modüler hale getir.
 *
 *	Ekranın sol üst köşesinden yazı yazdırmaya başlamak için scan direction
 *	ve segment re-map ayarları değiştirilmeli
 *
 */

extern uint8_t Char_Bitmap[26][6];


void OLED_WriteCommand(uint8_t Command)
{
	uint8_t data[2] = {0};
	data[0] = OLED_COMMAND_ID;
	data[1] = Command;

	HAL_I2C_Master_Transmit(OLED_I2C, OLED_ADDR_WRITE, data, 2, HAL_MAX_DELAY);
}

void OLED_WriteData(uint8_t* data, uint16_t size) {
    uint8_t control_reg = OLED_DATA_ID; // Co = 0, D/C# = 1 (veri)
    HAL_I2C_Mem_Write(OLED_I2C, OLED_ADDR_WRITE, control_reg, I2C_MEM_ADDR_SIZE, data, size, HAL_MAX_DELAY);
}

void OLED_DisplayOFF(void)
{
	OLED_WriteCommand(0xAE); //OLED Screen OFF
}

void OLED_DisplayON(void)
{
    OLED_WriteCommand(0xAF); //OLED Screen ON
}

void OLED_SetMemAddrMode(uint8_t mem_addr_mode)
{
	uint8_t MemAddr = CMD_MEMORY_ADDRESSING_MODE;
	uint8_t mode = mem_addr_mode;
    OLED_WriteCommand(MemAddr); 	// Switch to memory addressing mode
    OLED_WriteCommand(mode);  		// Configure the addressing mode
}

void OLED_SetPageAddrMode(uint8_t page_no, uint8_t column_no)
{
	uint8_t page = page_no | 0xB0;	//Device page number

	uint8_t Low_Nib = column_no & (0x0F);
	uint8_t Up_Nib = ((column_no >> 4) & (0x0F)) | 0x10;

    OLED_WriteCommand(page);  	//Set page start address

    OLED_WriteCommand(Low_Nib);  //Set lower nibble of colomn start address
    OLED_WriteCommand(Up_Nib);   //Set upper nibble of colomn start address
}

void OLED_SetColumnAddr(uint8_t start_col, uint8_t end_col)
{
	uint8_t cmd = CMD_COLUMN_ADDRESS_SET;
	uint8_t col_start = start_col;
	uint8_t col_end = end_col;
	OLED_WriteCommand(cmd);			//Command sent
	OLED_WriteCommand(col_start);	//Column start address sent
	OLED_WriteCommand(col_end);		//Column end address sent
}


void OLED_SetPageAddr(uint8_t page_start_addr, uint8_t page_end_addr)
{
	uint8_t page_addr_mode = CMD_PAGE_ADDRESS_SET;
	uint8_t pg_strt = page_start_addr;
	uint8_t pg_end = page_end_addr;

	OLED_WriteCommand(page_addr_mode);		//Command sent
	OLED_WriteCommand(pg_strt);				//Page start address sent
	OLED_WriteCommand(pg_end);				//Page end address sent
}


void OLED_SetDispStartLine(uint8_t disp_start_line)
{
	uint8_t disp_start = disp_start_line;

	OLED_WriteCommand(disp_start);
}


void OLED_SetContrast(uint8_t eight_bit_cont_val)
{
	uint8_t cmd = CMD_CONTRAST_CTRL;
	uint8_t contrast = eight_bit_cont_val;

	OLED_WriteCommand(cmd);			//Command sent
	OLED_WriteCommand(contrast);	//Contrast value sent
}

void OLED_SetSegmentRemap(uint8_t screen_refresh_direction)
{
	uint8_t direction = screen_refresh_direction;

	OLED_WriteCommand(direction);		//Command sent
}

void OLED_SetEntireDisp(uint8_t entire_disp_on_or_not)
{
	uint8_t entire_disp = entire_disp_on_or_not;

	OLED_WriteCommand(entire_disp);	//Command sent
}

void OLED_SetNormInvDisp(uint8_t disp_norm_or_inv)
{
	uint8_t norm_inv_disp = disp_norm_or_inv;

	OLED_WriteCommand(norm_inv_disp);
}

void OLED_SetDataLineNo(uint8_t line_no)
{
	uint8_t mux_val = CMD_MULTIPLEX_RATIO;
	uint8_t line = line_no;

	OLED_WriteCommand(mux_val);		//Command sent
	OLED_WriteCommand(line);		//Line number sent
}

void OLED_SetCOMOutScanDir(uint8_t com_scan_direction)
{
	uint8_t scan_dir = com_scan_direction;

	OLED_WriteCommand(scan_dir);		//Command sent
}

void OLED_SetDisplayOffset(uint8_t set_line_no)
{
	uint8_t disp_offs = CMD_DISPLAY_OFFSET;
	uint8_t line_no = set_line_no;

	OLED_WriteCommand(disp_offs);		//Command sent
	OLED_WriteCommand(line_no);			//Configuration sent
}

void OLED_DisplayInit(void)
{
    OLED_WriteCommand(0xAE); // Display OFF

    OLED_WriteCommand(0x20); // Set Memory Addressing Mode
    OLED_WriteCommand(0x00); // Horizontal Addressing Mode

    OLED_WriteCommand(0xB0); // Set Page Start Address for Page Addressing Mode

    OLED_WriteCommand(0xC8); // COM Output Scan Direction changed
    OLED_WriteCommand(0x00); // Low column address
    OLED_WriteCommand(0x10); // High column address

    OLED_WriteCommand(0x40); // Set start line address

    OLED_WriteCommand(0x81); // Set contrast control
    OLED_WriteCommand(0x7F);

    OLED_WriteCommand(0xA1); // Segment re-mapped
    OLED_WriteCommand(0xA6); // Normal display

    OLED_WriteCommand(0xA8); // Set multiplex ratio(1 to 64)
    OLED_WriteCommand(0x3F);

    OLED_WriteCommand(0xA4); // Output follows RAM content

    OLED_WriteCommand(0xD3); // Set display offset
    OLED_WriteCommand(0x00); // No offset

    OLED_WriteCommand(0xD5); // Set display clock divide ratio/oscillator frequency
    OLED_WriteCommand(0xF0); // Set divide ratio

    OLED_WriteCommand(0xD9); // Set pre-charge period
    OLED_WriteCommand(0x22);

    OLED_WriteCommand(0xDA); // Set com pins hardware configuration
    OLED_WriteCommand(0x12);

    OLED_WriteCommand(0xA6); //The pixels in the ram content are not inverted (normal mode)

    OLED_WriteCommand(0xDB); // Set vcomh
    OLED_WriteCommand(0x20);

    OLED_WriteCommand(0x8D); // Enable charge pump regulator
    OLED_WriteCommand(0x14);

    OLED_WriteCommand(0xAF); // Display ON
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

void OLED_WriteChar(char character)
{
//	if((Char != 32) || Char < 65 || Char > 90) return;

	uint8_t index = 0;

	if(character != 32)
	{
		index = character - 64;
	}

	else if(character == 32)
	{
		index = character - 32;
	}

	for(uint8_t i = 0; i<6; i++)
	{
		OLED_WriteData(&Char_Bitmap[index][i], sizeof(Char_Bitmap[index][i]));
	}

}
