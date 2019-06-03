/*
 * lcd_cfg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "types.h"
#include "reg.h"


#define DataPort		2
#define ControlPort		1
#define RS				0
#define RW				1
#define Enable			2


typedef struct
{
	u8 datalength;
	u8 lines;
	u8 font;
	u8 cursor;
	u8 blinking;
}lcd_cfg;

#endif /* LCD_CFG_H_ */
