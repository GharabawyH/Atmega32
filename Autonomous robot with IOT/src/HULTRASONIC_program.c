/*
 * HULTRASONIC_program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#include "LSTD_TYPES.h"
#define F_CPU 8000000UL
#include <util/delay.h>
#include "HULTRASONIC_interface.h"
#include "MINT_interface.h"
#include "MDIO_interface.h"
#include "MTIM1_private.h"

void HULTRASONIC_Initialize(void)
{
	MTIM1_Initialize();
	MDIO_SetPinDirection(DIO_DDRD , DIO_u8Pin2 , DIO_LOW);
	MDIO_SetPinDirection(DIO_DDRB , DIO_u8Pin0 , DIO_HIGH);
	MINT_Initialize(MINT0 , RisingEdge);
}

void HULTRASONIC_SendTrigger(void)
{
	MDIO_WritePinValue(DIO_PORTB , DIO_u8Pin0 , DIO_HIGH);
	_delay_us(10);
	MDIO_WritePinValue(DIO_PORTB , DIO_u8Pin0 , DIO_LOW);
}

u16 HULTRASONIC_CalculateDistance(void)
{
	u8 Count = 0;
	u64 OverFlow = 0;
	TCNT1 = 0;
	while(MDIO_ReadPinValue(DIO_PIND , DIO_u8Pin2))
	{
		if(TCNT1 == 65535)
		{
			Count ++;
		}
	}
	if(Count > 0)
	{
		OverFlow = ((Count*65535)+TCNT1);
		return OverFlow;
	}
	else
	{
		return TCNT1;
	}
}
