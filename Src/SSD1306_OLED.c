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
 *	Bitmap konfigürasyonunu 8x8 olacak şekilde yeniden düzenle!
 *
 */

extern uint8_t Char_Bitmap[27][8];


void OLED_WriteCommand(uint8_t Command)
{
	uint8_t data[2] = {0};
	data[0] = OLED_COMMAND_ID;
	data[1] = Command;

	HAL_I2C_Master_Transmit(OLED_I2C, OLED_ADDR_WRITE, data, 2, HAL_MAX_DELAY);
}

void OLED_WriteData(uint8_t* data) {
    uint8_t Data[2] = {0, 0}; // Co = 0, D/C# = 1 (veri)
    Data[0] = OLED_DATA_ID;
    Data[1] = *data;

    HAL_I2C_Master_Transmit(OLED_I2C, OLED_ADDR_WRITE, Data, 2, HAL_MAX_DELAY);
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

/*
 * Display initialization function
 */
void OLED_DisplayInit(void)
{
		HAL_Delay(100);
	    OLED_WriteCommand(0xAE); // Display OFF

	    OLED_WriteCommand(0x20); // Set Memory Addressing Mode
	    OLED_WriteCommand(0x00); // Horizontal Addressing Mode

	    OLED_WriteCommand(0x21); // Set Column Address
	    OLED_WriteCommand(0x00); // Column start
	    OLED_WriteCommand(0x7F); // Column end

	    OLED_WriteCommand(0x22); //Set page start address
	    OLED_WriteCommand(0x00); // Start address
	    OLED_WriteCommand(0x07); // End address

	    OLED_WriteCommand(0xC8); // COM Output Scan Direction
	    OLED_WriteCommand(0x00); // Low column address
	    OLED_WriteCommand(0x10); // High column address

	    OLED_WriteCommand(0x40); // Set start line address

	    OLED_WriteCommand(0x81); // Set contrast control
	    OLED_WriteCommand(0x7F);

	    OLED_WriteCommand(0xA1); // Set segment re-mapped 0 to 127
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

/*
 * Screen black/white pixel filling function
 */
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

/*
 * Getting Current Column Information Function
 */
uint8_t OLED_GetRemainingColumns(uint8_t current_col)
{
	if(!(current_col <= OLED_SCREEN_WIDTH))
	{
		Error_Handler();
	}
	return (OLED_SCREEN_WIDTH - current_col);
}

/*
 * Character writing function
 */
void OLED_WriteChar(char character)
{
	uint8_t index = 0;
	uint8_t B_let_col_size = 1;
	uint8_t S_let_col_size = 1;
	uint8_t current_col = 0;
	uint8_t rem_col = 0;
	uint8_t data = 0x00;


	//Geçerli karakter olup olmadığı kontrolü yapılır ve indeks yazılabilir karakterden başlar
	if(character >= 32 && character <= 126)
	{
		index = character - 32;
	}
	else
	{
		Error_Handler();
	}

	if(character != '"')
	{
		for(uint8_t i=0; i<8; i++)
		{
		  	OLED_WriteData(&Char_Bitmap[index][i]);					   // Bulunulan noktadan itibaren ekrana veri yazılır

		  	if(character != ' ')
		  	{
			  	if(Char_Bitmap[index][i] == 0x00) break;
		  	}
		}
	}

  	if(character == '"')
  	{
  		for(uint8_t i=0; i<4; i++)
  		{
  		  	OLED_WriteData(&Char_Bitmap[index][i]);
  		}
  	}
}

/*
 * String writing function
 */
void OLED_WriteScreen(char* str, uint8_t str_size)
{
	char letter = *str;

	for(uint8_t i = 0; i<str_size; i++)
	{
		letter = *(str + i);
		OLED_WriteChar(letter);
	}
}

void OLED_SetCursor(uint8_t page_no, uint8_t column_no)
{
	OLED_SetColumnAddr(column_no, SET_COL_127);
	OLED_SetPageAddr(page_no, SET_PAGE_7);
}
