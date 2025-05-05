/*
 * FONT.h
 *
 *  Created on: May 4, 2025
 *      Author: Mert
 */

#ifndef INC_FONT_H_
#define INC_FONT_H_

#include "stm32f0xx_hal.h"
#include "main.h"

/* One characters bitmap size is 6x8 pixels.
 * The configuration is in row order from top to bottom *
 *
 *
 * 	 Width 6 pixels
 * -------------------
 * |0,0| |	|  |  |	 |
   -------------------
 * |  |  |	|  |  |	 |
   -------------------
 * |  |  |	|  |  |	 |
   -------------------
 * |  |  |	|  |  |	 |	Height 7 pixels
   -------------------
 * |  |  |	|  |  |	 |
   -------------------
 * |  |  |	|  |  |	 |
   -------------------
 * |  |  |	|  |  |5,6|
   -------------------
 */



#define FONT_WIDTH	6
#define FONT_HEIGHT	7

#endif /* INC_FONT_H_ */
