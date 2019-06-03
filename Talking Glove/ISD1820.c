/*
 * ISD1820.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#include "types.h"
#include "reg.h"
#include "dio.h"
#include "dio_cfg.h"

void ISD1820_Enable(void)
{
	DIO_SetPinDirection(DIO_DDRD,DIO_u8Pin0,DIO_HIGH);
}

void ISD1820_StartMessage(void)
{
	DIO_WritePinValue(DIO_PORTD,DIO_u8Pin0,DIO_HIGH);
	DIO_WritePinValue(DIO_PORTD,DIO_u8Pin0,DIO_LOW);
}
