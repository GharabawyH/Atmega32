/*
 * lcd.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#include "types.h"
#include "reg.h"
#include "lcd.h"
#include "lcd_cfg.h"
#include "dio.h"
#include "dio_cfg.h"
#include <avr/delay.h>


void LCD_WriteNum(u32 data)
{
	u8 arr[10]={'0','1','2','3','4','5','6','7','8','9'};
	u8 temp[1000];
	u8 i=0;
	if(data<10)
	{
		LCD_WriteCharacter(arr[data]);
	}
	if(data>=10)
	{
		while(data>0)
		{
			temp[i]=data%10;
			data/=10;
			i++;
		}

		while(i>0)
		{
			i--;
			LCD_WriteCharacter(arr[temp[i]]);
		}
	}
}

void LCD_WriteString(u8 arr[])
{
	int i=0;
	while(arr[i]!='\0')
	{
		LCD_WriteCharacter(arr[i]);
		i++;
	}
}


void LCD_WriteCharacter(u8 data)
{
	//	DataPort.value=data;
	DIO_WritePortValue(DataPort,data);
	//	ControlPort.BitValue.RS=1;
	//	ControlPort.BitValue.RW=0;
	//	ControlPort.BitValue.Enable=1;
	DIO_WritePinValue(ControlPort,RS,DIO_HIGH);
	DIO_WritePinValue(ControlPort,RW,DIO_LOW);
	DIO_WritePinValue(ControlPort,Enable,DIO_HIGH);
	_delay_ms(1);
	//	ControlPort.BitValue.Enable=0;
	DIO_WritePinValue(ControlPort,Enable,DIO_LOW);
	_delay_ms(20);
}


void LCD_WriteCommand(u8 command)
{
	//	DataPort.value=command;
	//	ControlPort.BitValue.RS=0;
	//	ControlPort.BitValue.RW=0;
	//	ControlPort.BitValue.Enable=1;
	DIO_WritePortValue(DataPort,command);
	DIO_WritePinValue(ControlPort,RS,DIO_LOW);
	DIO_WritePinValue(ControlPort,RW,DIO_LOW);
	DIO_WritePinValue(ControlPort,Enable,DIO_HIGH);
	_delay_ms(1);
	//	ControlPort.BitValue.Enable=0;
	DIO_WritePinValue(ControlPort,Enable,DIO_LOW);
	_delay_ms(20);
}


void Init_LCD(lcd_cfg*ptr)
{
	//	DataPortDir.value=0xff;
	//	ControlPortDir.BitValue.RS=1;
	//	ControlPortDir.BitValue.RW=1;
	//	ControlPortDir.BitValue.Enable=1;

	DIO_SetPortDirection(DataPort,DIO_PORT_HIGH);
	DIO_SetPinDirection(ControlPort,RS,DIO_HIGH);
	DIO_SetPinDirection(ControlPort,RW,DIO_HIGH);
	DIO_SetPinDirection(ControlPort,Enable,DIO_HIGH);

	_delay_ms(50);
	u8 FnSet=0b00100000;
	u8 DspOnOffCtrl=0b00001100;
	u8 clear=1;
	FnSet|=(ptr->datalength)<<4;
	FnSet|=(ptr->lines)<<3;
	FnSet|=(ptr->font)<<2;
	LCD_WriteCommand(FnSet);
	_delay_ms(1);
	DspOnOffCtrl|=(ptr->cursor)<<1;
	DspOnOffCtrl|=(ptr->blinking);
	LCD_WriteCommand(DspOnOffCtrl);
	_delay_ms(1);
	LCD_WriteCommand(clear);
	_delay_ms(10);
}


void LCD_SetPosition(u8 line,u8 column)
{
	switch (line)
	{
	case 1:LCD_WriteCommand(128+column);break;
	case 2:LCD_WriteCommand(128+64+column);break;
	}
}
