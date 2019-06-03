/*
 * lcd.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#ifndef LCD_H_
#define LCD_H_

#include "lcd_cfg.h"

void LCD_WriteCharacter(u8 data);
void LCD_WriteCommand(u8 command);
void Init_LCD(lcd_cfg*ptr);
void LCD_SetPosition(u8 line,u8 column);
void LCD_WriteString(u8 arr[]);
void LCD_WriteNum(u32 data);

#endif /* LCD_H_ */
