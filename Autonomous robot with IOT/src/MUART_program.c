/*
 * uart.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#include "LSTD_TYPES.h"
#include "MUART_private.h"
#include "MUART_interface.h"



void MUART_INIT(void)
{
	UCSRA |= 0x2;
	UCSRB = 0x18;
	UCSRC = 0x86;
	UBRRH=0;
	UBRRL=8;
}


u8 MUART_Recieve(void)
{
	while(!( UCSRA & ( 1 << 7 )));
	return UDR;
}

void MUART_Transmit(u8 data[])
{
	u8 i = 0;
	while(data[i] != '\0')
	{
	UDR = data[i];
	while(!( UCSRA & ( 1 << 5 )));
	i++;
	}
}
