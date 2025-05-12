/*
 * SSD1306_OLED.h
 *
 *  Created on: Apr 22, 2025
 *      Author: Mert
 */

#ifndef INC_SSD1306_OLED_H_
#define INC_SSD1306_OLED_H_

#include "main.h"
#include "FONT.h"
#include "string.h"

extern I2C_HandleTypeDef hi2c1;

/*
 * Device Address and Interface Definitions
 */
#define OLED_I2C		&hi2c1
#define OLED_ADDR		0x3C
#define OLED_ADDR_WRITE	(OLED_ADDR << 1)

#define I2C_MEM_ADDR_SIZE	0x01U

#define OLED_SCREEN_WIDTH	128

/*
 * Command and Data Identifier Definitions
 */
#define OLED_COMMAND_ID		0x00
#define OLED_DATA_ID		0x40

/*
 * Page Definitions
 */
#define SET_PAGE_0	0x00
#define SET_PAGE_1	0x01
#define SET_PAGE_2	0x02
#define SET_PAGE_3	0x03
#define SET_PAGE_4	0x04
#define SET_PAGE_5	0x05
#define SET_PAGE_6	0x06
#define SET_PAGE_7	0x07

/*
 * Column Definitions
 */
#define SET_COL_0	0x00
#define SET_COL_1	0x01
#define SET_COL_2	0x02
#define SET_COL_3	0x03
#define SET_COL_4	0x04
#define SET_COL_5	0x05
#define SET_COL_6	0x06
#define SET_COL_7	0x07
#define SET_COL_8	0x08
#define SET_COL_9	0x09
#define SET_COL_10	0x0A
#define SET_COL_11	0x0B
#define SET_COL_12	0x0C
#define SET_COL_13	0x0D
#define SET_COL_14	0x0E
#define SET_COL_15	0x0F
#define SET_COL_16	0x10
#define SET_COL_17	0x11
#define SET_COL_18	0x12
#define SET_COL_19	0x13
#define SET_COL_20	0x14
#define SET_COL_21	0x15
#define SET_COL_22	0x16
#define SET_COL_23	0x17
#define SET_COL_24	0x18
#define SET_COL_25	0x19
#define SET_COL_26	0x1A
#define SET_COL_27	0x1B
#define SET_COL_28	0x1C
#define SET_COL_29	0x1D
#define SET_COL_30	0x1E
#define SET_COL_31	0x1F
#define SET_COL_32	0x20
#define SET_COL_33	0x21
#define SET_COL_34	0x22
#define SET_COL_35	0x23
#define SET_COL_36	0x24
#define SET_COL_37	0x25
#define SET_COL_38	0x26
#define SET_COL_39	0x27
#define SET_COL_40	0x28
#define SET_COL_41	0x29
#define SET_COL_42	0x2A
#define SET_COL_43	0x2B
#define SET_COL_44	0x2C
#define SET_COL_45	0x2D
#define SET_COL_46	0x2E
#define SET_COL_47	0x2F
#define SET_COL_48	0x30
#define SET_COL_49	0x31
#define SET_COL_50	0x32
#define SET_COL_51	0x33
#define SET_COL_52	0x34
#define SET_COL_53	0x35
#define SET_COL_54	0x36
#define SET_COL_55	0x37
#define SET_COL_56	0x38
#define SET_COL_57	0x39
#define SET_COL_58	0x3A
#define SET_COL_59	0x3B
#define SET_COL_60	0x3C
#define SET_COL_61	0x3D
#define SET_COL_62	0x3E
#define SET_COL_63	0x3F
#define SET_COL_64	0x40
#define SET_COL_65	0x41
#define SET_COL_66	0x42
#define SET_COL_67	0x43
#define SET_COL_68	0x44
#define SET_COL_69	0x45
#define SET_COL_70	0x46
#define SET_COL_71	0x47
#define SET_COL_72	0x48
#define SET_COL_73	0x49
#define SET_COL_74	0x4A
#define SET_COL_75	0x4B
#define SET_COL_76	0x4C
#define SET_COL_77	0x4D
#define SET_COL_78	0x4E
#define SET_COL_79	0x4F
#define SET_COL_80	0x50
#define SET_COL_81	0x51
#define SET_COL_82	0x52
#define SET_COL_83	0x53
#define SET_COL_84	0x54
#define SET_COL_85	0x55
#define SET_COL_86	0x56
#define SET_COL_87	0x57
#define SET_COL_88	0x58
#define SET_COL_89	0x59
#define SET_COL_90	0x5A
#define SET_COL_91	0x5B
#define SET_COL_92	0x5C
#define SET_COL_93	0x5D
#define SET_COL_94	0x5E
#define SET_COL_95	0x5F
#define SET_COL_96	0x60
#define SET_COL_97	0x61
#define SET_COL_98	0x62
#define SET_COL_99	0x63
#define SET_COL_100	0x64
#define SET_COL_101	0x65
#define SET_COL_102 0x66
#define SET_COL_103	0x67
#define SET_COL_104	0x68
#define SET_COL_105	0x69
#define SET_COL_106	0x6A
#define SET_COL_107	0x6B
#define SET_COL_108	0x6C
#define SET_COL_109	0x6D
#define SET_COL_110	0x6E
#define SET_COL_111	0x6F
#define SET_COL_112	0x70
#define SET_COL_113	0x71
#define SET_COL_114	0x72
#define SET_COL_115	0x73
#define SET_COL_116	0x74
#define SET_COL_117	0x75
#define SET_COL_118	0x76
#define SET_COL_119	0x77
#define SET_COL_120	0x78
#define SET_COL_121	0x79
#define SET_COL_122	0x7A
#define SET_COL_123	0x7B
#define SET_COL_124	0x7C
#define SET_COL_125	0x7D
#define SET_COL_126	0x7E
#define SET_COL_127	0x7F

/*
 * Frame Interval Definitions
 */
#define SET_FRAME_INT_2_FRAMES		0x07
#define SET_FRAME_INT_3_FRAMES		0x04
#define SET_FRAME_INT_4_FRAMES		0x05
#define SET_FRAME_INT_5_FRAMES		0x00
#define SET_FRAME_INT_25_FRAMES		0x06
#define SET_FRAME_INT_64_FRAMES		0x01
#define SET_FRAME_INT_128_FRAMES	0x02
#define SET_FRAME_INT_256_FRAMES	0x03

/*
 * Line Number Definitions
 */
#define SET_LINE_NO_0				0x00
#define SET_LINE_NO_1				0x01
#define SET_LINE_NO_2				0x02
#define SET_LINE_NO_3				0x03
#define SET_LINE_NO_4				0x04
#define SET_LINE_NO_5				0x05
#define SET_LINE_NO_6				0x06
#define SET_LINE_NO_7				0x07
#define SET_LINE_NO_8				0x08
#define SET_LINE_NO_9				0x09
#define SET_LINE_NO_10				0x0A
#define SET_LINE_NO_11				0x0B
#define SET_LINE_NO_12				0x0C
#define SET_LINE_NO_13				0x0D
#define SET_LINE_NO_14				0x0E
#define SET_LINE_NO_15				0x0F
#define SET_LINE_NO_16				0x10
#define SET_LINE_NO_17				0x11
#define SET_LINE_NO_18				0x12
#define SET_LINE_NO_19				0x13
#define SET_LINE_NO_20				0x14
#define SET_LINE_NO_21				0x15
#define SET_LINE_NO_22				0x16
#define SET_LINE_NO_23				0x17
#define SET_LINE_NO_24				0x18
#define SET_LINE_NO_25				0x19
#define SET_LINE_NO_26				0x1A
#define SET_LINE_NO_27				0x1B
#define SET_LINE_NO_28				0x1C
#define SET_LINE_NO_29				0x1D
#define SET_LINE_NO_30				0x1E
#define SET_LINE_NO_31				0x1F
#define SET_LINE_NO_32				0x20
#define SET_LINE_NO_33				0x21
#define SET_LINE_NO_34				0x22
#define SET_LINE_NO_35				0x23
#define SET_LINE_NO_36				0x24
#define SET_LINE_NO_37				0x25
#define SET_LINE_NO_38				0x26
#define SET_LINE_NO_39				0x27
#define SET_LINE_NO_40				0x28
#define SET_LINE_NO_41				0x29
#define SET_LINE_NO_42				0x2A
#define SET_LINE_NO_43				0x2B
#define SET_LINE_NO_44				0x2C
#define SET_LINE_NO_45				0x2D
#define SET_LINE_NO_46				0x2E
#define SET_LINE_NO_47				0x2F
#define SET_LINE_NO_48				0x30
#define SET_LINE_NO_49				0x31
#define SET_LINE_NO_50				0x32
#define SET_LINE_NO_51				0x33
#define SET_LINE_NO_52				0x34
#define SET_LINE_NO_53				0x35
#define SET_LINE_NO_54				0x36
#define SET_LINE_NO_55				0x37
#define SET_LINE_NO_56				0x38
#define SET_LINE_NO_57				0x39
#define SET_LINE_NO_58				0x3A
#define SET_LINE_NO_59				0x3B
#define SET_LINE_NO_60				0x3C
#define SET_LINE_NO_61				0x3D
#define SET_LINE_NO_62				0x3E
#define SET_LINE_NO_63				0x3F

/*
 * Lower Or Higher Column Start Address Nibbles Definitions for Page Addressing Mode
 */
/*
#define SET_COLUMN_START_ADDR_LOW_NIB_00	0x00
#define SET_COLUMN_START_ADDR_LOW_NIB_01	0x01
#define SET_COLUMN_START_ADDR_LOW_NIB_02	0x02
#define SET_COLUMN_START_ADDR_LOW_NIB_03	0x03
#define SET_COLUMN_START_ADDR_LOW_NIB_04	0x04
#define SET_COLUMN_START_ADDR_LOW_NIB_05	0x05
#define SET_COLUMN_START_ADDR_LOW_NIB_06	0x06
#define SET_COLUMN_START_ADDR_LOW_NIB_07	0x07
#define SET_COLUMN_START_ADDR_LOW_NIB_08	0x08
#define SET_COLUMN_START_ADDR_LOW_NIB_09	0x09
#define SET_COLUMN_START_ADDR_LOW_NIB_0A	0x0A
#define SET_COLUMN_START_ADDR_LOW_NIB_0B	0x0B
#define SET_COLUMN_START_ADDR_LOW_NIB_0C	0x0C
#define SET_COLUMN_START_ADDR_LOW_NIB_0D	0x0D
#define SET_COLUMN_START_ADDR_LOW_NIB_0E	0x0E
#define SET_COLUMN_START_ADDR_LOW_NIB_0F	0x0F

#define SET_COLUMN_START_ADDR_HIGH_NIB_10	0x10
#define SET_COLUMN_START_ADDR_HIGH_NIB_11	0x11
#define SET_COLUMN_START_ADDR_HIGH_NIB_12	0x12
#define SET_COLUMN_START_ADDR_HIGH_NIB_13	0x13
#define SET_COLUMN_START_ADDR_HIGH_NIB_14	0x14
#define SET_COLUMN_START_ADDR_HIGH_NIB_15	0x15
#define SET_COLUMN_START_ADDR_HIGH_NIB_16	0x16
#define SET_COLUMN_START_ADDR_HIGH_NIB_17	0x17
#define SET_COLUMN_START_ADDR_HIGH_NIB_18	0x18
#define SET_COLUMN_START_ADDR_HIGH_NIB_19	0x19
#define SET_COLUMN_START_ADDR_HIGH_NIB_1A	0x1A
#define SET_COLUMN_START_ADDR_HIGH_NIB_1B	0x1B
#define SET_COLUMN_START_ADDR_HIGH_NIB_1C	0x1C
#define SET_COLUMN_START_ADDR_HIGH_NIB_1D	0x1D
#define SET_COLUMN_START_ADDR_HIGH_NIB_1E	0x1E
#define SET_COLUMN_START_ADDR_HIGH_NIB_1F	0x1F
*/


/*
 * Dummy Byte Definitions
 */
#define SET_DUMMY_BYTE_00			0x00
#define SET_DUMMY_BYTE_FF			0xFF

/*
 * COM Pins Hardware Configurations Definitions
 */
#define SET_COM_PINS_SEQUENTIAL_AND_DI_REMAP	0x00
#define SET_COM_PINS_SEQUENTIAL_AND_EN_REMAP	0x22
#define SET_COM_PINS_ALTERNATIVE_AND_DI_REMAP	0x12
#define SET_COM_PINS_ALTERNATIVE_AND_EN_REMAP	0x32

/*
 * Display Clock Divide Ration and Oscillator Frequency Definitions
 */
#define SET_DISP_CLK_DIV_0		0x00
#define SET_DISP_CLK_DIV_1		0x01
#define SET_DISP_CLK_DIV_2		0x02
#define SET_DISP_CLK_DIV_3		0x03
#define SET_DISP_CLK_DIV_4		0x04
#define SET_DISP_CLK_DIV_5		0x05
#define SET_DISP_CLK_DIV_6		0x06
#define SET_DISP_CLK_DIV_7		0x07
#define SET_DISP_CLK_DIV_8		0x08
#define SET_DISP_CLK_DIV_9		0x09
#define SET_DISP_CLK_DIV_10		0x0A
#define SET_DISP_CLK_DIV_11		0x0B
#define SET_DISP_CLK_DIV_12		0x0C
#define SET_DISP_CLK_DIV_13		0x0D
#define SET_DISP_CLK_DIV_14		0x0E
#define SET_DISP_CLK_DIV_15		0x0F

#define SET_DISP_OSC_FREQ_0		0x00
#define SET_DISP_OSC_FREQ_1		0x01
#define SET_DISP_OSC_FREQ_2		0x02
#define SET_DISP_OSC_FREQ_3		0x03
#define SET_DISP_OSC_FREQ_4		0x04
#define SET_DISP_OSC_FREQ_5		0x05
#define SET_DISP_OSC_FREQ_6		0x06
#define SET_DISP_OSC_FREQ_7		0x07
#define SET_DISP_OSC_FREQ_8		0x08
#define SET_DISP_OSC_FREQ_9		0x09
#define SET_DISP_OSC_FREQ_10	0x0A
#define SET_DISP_OSC_FREQ_11	0x0B
#define SET_DISP_OSC_FREQ_12	0x0C
#define SET_DISP_OSC_FREQ_13	0x0D
#define SET_DISP_OSC_FREQ_14	0x0E
#define SET_DISP_OSC_FREQ_15	0x0F

/*
 * Pre-Charge Phase-1 & Phase-2 Period Definitions
 */
#define SET_PRE_CHARGE_PHASE_1_0	0x00
#define SET_PRE_CHARGE_PHASE_1_1	0x01
#define SET_PRE_CHARGE_PHASE_1_2	0x02
#define SET_PRE_CHARGE_PHASE_1_3	0x03
#define SET_PRE_CHARGE_PHASE_1_4	0x04
#define SET_PRE_CHARGE_PHASE_1_5	0x05
#define SET_PRE_CHARGE_PHASE_1_6	0x06
#define SET_PRE_CHARGE_PHASE_1_7	0x07
#define SET_PRE_CHARGE_PHASE_1_8	0x08
#define SET_PRE_CHARGE_PHASE_1_9	0x09
#define SET_PRE_CHARGE_PHASE_1_10	0x0A
#define SET_PRE_CHARGE_PHASE_1_11	0x0B
#define SET_PRE_CHARGE_PHASE_1_12	0x0C
#define SET_PRE_CHARGE_PHASE_1_13	0x0D
#define SET_PRE_CHARGE_PHASE_1_14	0x0E
#define SET_PRE_CHARGE_PHASE_1_15	0x0F

#define SET_PRE_CHARGE_PHASE_2_0	0x00
#define SET_PRE_CHARGE_PHASE_2_1	0x01
#define SET_PRE_CHARGE_PHASE_2_2	0x02
#define SET_PRE_CHARGE_PHASE_2_3	0x03
#define SET_PRE_CHARGE_PHASE_2_4	0x04
#define SET_PRE_CHARGE_PHASE_2_5	0x05
#define SET_PRE_CHARGE_PHASE_2_6	0x06
#define SET_PRE_CHARGE_PHASE_2_7	0x07
#define SET_PRE_CHARGE_PHASE_2_8	0x08
#define SET_PRE_CHARGE_PHASE_2_9	0x09
#define SET_PRE_CHARGE_PHASE_2_10	0x0A
#define SET_PRE_CHARGE_PHASE_2_11	0x0B
#define SET_PRE_CHARGE_PHASE_2_12	0x0C
#define SET_PRE_CHARGE_PHASE_2_13	0x0D
#define SET_PRE_CHARGE_PHASE_2_14	0x0E
#define SET_PRE_CHARGE_PHASE_2_15	0x0F

/*
 * VCOMH Deselect Level Definitions
 */
#define SET_VCOMH_0_65_VCC			0x00
#define SET_VCOMH_0_77_VCC			0x20
#define SET_VCOMH_0_83_VCC			0x30

/*
 * Fundamental Commands Definitions
 */
#define CMD_CONTRAST_CTRL		0x81
#define CMD_DISP_ON				0xAF
#define CMD_DISP_OFF			0xAE
#define CMD_ENTIRE_DISP_NOT_ON	0xA4
#define CMD_ENTIRE_DISP_ON		0xA5
#define CMD_NOT_INV_DISP		0xA6
#define CMD_INV_DISP			0xA7


/*
 * Scrolling Commands Definitions
 */
#define CMD_CTNS_HOR_SCRLL_RIGHT			0x26
#define CMD_CTNS_HOR_SCRLL_LEFT				0x27

#define CMD_CTNS_VER_HOR_SCRLL_VER_RIGHT	0x29
#define CMD_CTNS_VER_HOR_SCRLL_VER_LEFT		0x2A

#define CMD_SCRLL_DEACTIVATE				0x2E
#define CMD_SCRLL_ACTIVATE					0x2F

#define CMD_VERTICAL_SCRLL_AREA				0xA3

/*
 * Addressing Commands Definitions
 */
#define CMD_MEMORY_ADDRESSING_MODE			0x20

#define CMD_COLUMN_ADDRESS_SET				0x21

#define CMD_PAGE_ADDRESS_SET				0x22

#define CMD_PAGE_STRT_ADDR_0				0xB0
#define CMD_PAGE_STRT_ADDR_1				0xB1
#define CMD_PAGE_STRT_ADDR_2				0xB2
#define CMD_PAGE_STRT_ADDR_3				0xB3
#define CMD_PAGE_STRT_ADDR_4				0xB4
#define CMD_PAGE_STRT_ADDR_5				0xB5
#define CMD_PAGE_STRT_ADDR_6				0xB6
#define CMD_PAGE_STRT_ADDR_7				0xB7

/*
 * Hardware Configuration Commands Definitions
 */
#define CMD_DISPLAY_START_LINE_SET_0		0x40
#define CMD_DISPLAY_START_LINE_SET_1		0x41
#define CMD_DISPLAY_START_LINE_SET_2		0x42
#define CMD_DISPLAY_START_LINE_SET_3		0x43
#define CMD_DISPLAY_START_LINE_SET_4		0x44
#define CMD_DISPLAY_START_LINE_SET_5		0x45
#define CMD_DISPLAY_START_LINE_SET_6		0x46
#define CMD_DISPLAY_START_LINE_SET_7		0x47
#define CMD_DISPLAY_START_LINE_SET_8		0x48
#define CMD_DISPLAY_START_LINE_SET_9		0x49
#define CMD_DISPLAY_START_LINE_SET_10		0x4A
#define CMD_DISPLAY_START_LINE_SET_11		0x4B
#define CMD_DISPLAY_START_LINE_SET_12		0x4C
#define CMD_DISPLAY_START_LINE_SET_13		0x4D
#define CMD_DISPLAY_START_LINE_SET_14		0x4E
#define CMD_DISPLAY_START_LINE_SET_15		0x4F
#define CMD_DISPLAY_START_LINE_SET_16		0x50
#define CMD_DISPLAY_START_LINE_SET_17		0x51
#define CMD_DISPLAY_START_LINE_SET_18		0x52
#define CMD_DISPLAY_START_LINE_SET_19		0x53
#define CMD_DISPLAY_START_LINE_SET_20		0x54
#define CMD_DISPLAY_START_LINE_SET_21		0x55
#define CMD_DISPLAY_START_LINE_SET_22		0x56
#define CMD_DISPLAY_START_LINE_SET_23		0x57
#define CMD_DISPLAY_START_LINE_SET_24		0x58
#define CMD_DISPLAY_START_LINE_SET_25		0x59
#define CMD_DISPLAY_START_LINE_SET_26		0x5A
#define CMD_DISPLAY_START_LINE_SET_27		0x5B
#define CMD_DISPLAY_START_LINE_SET_28		0x5C
#define CMD_DISPLAY_START_LINE_SET_29		0x5D
#define CMD_DISPLAY_START_LINE_SET_30		0x5E
#define CMD_DISPLAY_START_LINE_SET_31		0x5F
#define CMD_DISPLAY_START_LINE_SET_32		0x60
#define CMD_DISPLAY_START_LINE_SET_33		0x61
#define CMD_DISPLAY_START_LINE_SET_34		0x62
#define CMD_DISPLAY_START_LINE_SET_35		0x63
#define CMD_DISPLAY_START_LINE_SET_36		0x64
#define CMD_DISPLAY_START_LINE_SET_37		0x65
#define CMD_DISPLAY_START_LINE_SET_38		0x66
#define CMD_DISPLAY_START_LINE_SET_39		0x67
#define CMD_DISPLAY_START_LINE_SET_40		0x68
#define CMD_DISPLAY_START_LINE_SET_41		0x69
#define CMD_DISPLAY_START_LINE_SET_42		0x6A
#define CMD_DISPLAY_START_LINE_SET_43		0x6B
#define CMD_DISPLAY_START_LINE_SET_44		0x6C
#define CMD_DISPLAY_START_LINE_SET_45		0x6D
#define CMD_DISPLAY_START_LINE_SET_46		0x6E
#define CMD_DISPLAY_START_LINE_SET_47		0x6F
#define CMD_DISPLAY_START_LINE_SET_48		0x70
#define CMD_DISPLAY_START_LINE_SET_49		0x71
#define CMD_DISPLAY_START_LINE_SET_50		0x72
#define CMD_DISPLAY_START_LINE_SET_51		0x73
#define CMD_DISPLAY_START_LINE_SET_52		0x74
#define CMD_DISPLAY_START_LINE_SET_53		0x75
#define CMD_DISPLAY_START_LINE_SET_54		0x76
#define CMD_DISPLAY_START_LINE_SET_55		0x77
#define CMD_DISPLAY_START_LINE_SET_56		0x78
#define CMD_DISPLAY_START_LINE_SET_57		0x79
#define CMD_DISPLAY_START_LINE_SET_58		0x7A
#define CMD_DISPLAY_START_LINE_SET_59		0x7B
#define CMD_DISPLAY_START_LINE_SET_60		0x7C
#define CMD_DISPLAY_START_LINE_SET_61		0x7D
#define CMD_DISPLAY_START_LINE_SET_62		0x7E
#define CMD_DISPLAY_START_LINE_SET_63		0X7F

#define CMD_SEGMENT_REMAP_TO_RIGHT			0xA0
#define CMD_SEGMENT_REMAP_TO_LEFT			0xA1

#define CMD_MULTIPLEX_RATIO					0xA8

#define CMD_COM_OPUT_SCAN_DIR_TO_DOWN		0xC0
#define CMD_COM_OPUT_SCAN_DIR_TO_UP			0xC8

#define CMD_DISPLAY_OFFSET					0xD3

#define CMD_COM_PINS_HW_CONFIG				0xDA

/*
 * Timing and Driving Scheme Settings Commands Definitions
 */
#define CMD_DISP_CLK_DIV_RATIO_OSC_FREQ		0xD5

#define CMD_PRE_CHARGE_PERIOD_SET			0xD9

#define CMD_VCOMH_DESELECT_LEVEL			0xDB

#define CMD_NOP								0xE3

/*
 * Function Prototypes
 */
void OLED_DisplayInit(void);
void OLED_WriteCommand(uint8_t data);
void OLED_FillScreen(uint8_t color);
void OLED_WriteData(uint8_t* data);
void OLED_WriteChar(char character);
void OLED_WriteScreen(char* str, uint8_t str_size);
void OLED_DisplayOFF(void);
void OLED_DisplayON(void);
void OLED_SetMemAddrMode(uint8_t mem_addr_mode);
void OLED_SetPageAddrMode(uint8_t page_no, uint8_t column_no);
void OLED_SetColumnAddr(uint8_t start_col, uint8_t end_col);
void OLED_SetPageAddr(uint8_t page_start_addr, uint8_t page_end_addr);
void OLED_SetDispStartLine(uint8_t disp_start_line);
void OLED_SetContrast(uint8_t eight_bit_cont_val);
void OLED_SetSegmentRemap(uint8_t secreen_refresh_direction);
void OLED_SetEntireDisp(uint8_t entire_disp_on_or_not);
void OLED_SetNormInvDisp(uint8_t disp_norm_or_inv);
void OLED_SetDataLineNo(uint8_t line_no);
void OLED_SetCOMOutScanDir(uint8_t com_scan_direction);
void OLED_SetDisplayOffset(uint8_t set_line_no);
void OLED_SetCursor(uint8_t page_no, uint8_t column_no);
uint8_t OLED_GetRemainingColumns(uint8_t current_col);

/*
 * Generic Macros
 */
#define TRIALS	3
#define TIMEOUT	100

#endif /* INC_SSD1306_OLED_H_ */
