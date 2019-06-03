/*
 * dio.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#include "types.h"
#include "reg.h"
#include "dio.h"



void DIO_SetPortDirection(u8 DIO_PortNum,u8 DIO_PortValue)
{
	switch(DIO_PortNum)
	{
	case 0:DDRA|=DIO_PortValue;break;
	case 1:DDRB|=DIO_PortValue;break;
	case 2:DDRC|=DIO_PortValue;break;
	case 3:DDRD|=DIO_PortValue;break;
	}
}

void DIO_WritePortValue(u8 DIO_PortNum,u8 DIO_PortValue)
{
	switch(DIO_PortNum)
	{
	case 0:PORTA=DIO_PortValue;break;
	case 1:PORTB=DIO_PortValue;break;
	case 2:PORTC=DIO_PortValue;break;
	case 3:PORTD=DIO_PortValue;break;
	}
}

u8 DIO_ReadPortValue(u8 DIO_PortNum)
{
	u8 tmp;
	switch(DIO_PortNum)
	{
	case 0:tmp=PINA;break;
	case 1:tmp=PINB;break;
	case 2:tmp=PINC;break;
	case 3:tmp=PIND;break;
	}
	return tmp;
}

void DIO_SetPinDirection(u8 DIO_PortNum,u8 DIO_PinNum,u8 DIO_PinValue)
{
	switch(DIO_PortNum)
	{
	case 0:
	{
		switch(DIO_PinValue)
		{
		case 0:DDRA&=~(1<<DIO_PinNum);break;
		case 1:DDRA|=(1<<DIO_PinNum);break;
		}
		break;
	}
	case 1:
	{
		switch(DIO_PinValue)
		{
		case 0:DDRB&=~(1<<DIO_PinNum);break;
		case 1:DDRB|=(1<<DIO_PinNum);break;
		}
		break;
	}
	case 2:
	{
		switch(DIO_PinValue)
		{
		case 0:DDRC&=~(1<<DIO_PinNum);break;
		case 1:DDRC|=(1<<DIO_PinNum);break;
		}
		break;
	}
	case 3:
	{
		switch(DIO_PinValue)
		{
		case 0:DDRD&=~(1<<DIO_PinNum);break;
		case 1:DDRD|=(1<<DIO_PinNum);break;
		}
		break;
	}
	}
}

void DIO_WritePinValue(u8 DIO_PortNum,u8 DIO_PinNum,u8 DIO_PinValue)
{
	switch(DIO_PortNum)
	{
	case 0:
	{
		switch(DIO_PinValue)
		{
		case 0:PORTA&=~(1<<DIO_PinNum);break;
		case 1:PORTA|=(1<<DIO_PinNum);break;
		}
		break;
	}
	case 1:
	{
		switch(DIO_PinValue)
		{
		case 0:PORTB&=~(1<<DIO_PinNum);break;
		case 1:PORTB|=(1<<DIO_PinNum);break;
		}
		break;
	}
	case 2:
	{
		switch(DIO_PinValue)
		{
		case 0:PORTC&=~(1<<DIO_PinNum);break;
		case 1:PORTC|=(1<<DIO_PinNum);break;
		}
		break;
	}
	case 3:
	{
		switch(DIO_PinValue)
		{
		case 0:PORTD&=~(1<<DIO_PinNum);break;
		case 1:PORTD|=(1<<DIO_PinNum);break;
		}
		break;
	}
	}
}

u8 DIO_ReadPinValue(u8 DIO_PortNum,u8 DIO_PinNum)
{
	u8 tmp;
	switch(DIO_PortNum)
	{
	case 0:tmp=1&(PINA>>DIO_PinNum);break;
	case 1:tmp=1&(PINB>>DIO_PinNum);break;
	case 2:tmp=1&(PINC>>DIO_PinNum);break;
	case 3:tmp=1&(PIND>>DIO_PinNum);break;
	}
	return tmp;
}
