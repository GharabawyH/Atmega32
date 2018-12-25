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
	UCSRA |= 0x2;/*Enable UART Double Speed*/
	UCSRB = 0x18;/*Enable UART Receive and Transmit*/
	UCSRC = 0x86;/*Asynchronous mode , Disabled Parity , 1 stop-bit , 8-bit character size*/
	UBRRH=0;
	UBRRL=8;/*Set the baude rate to 115200*/
}


u8 MUART_Recieve(void)
{
	while(!( UCSRA & ( 1 << 7 )));/*Wait for receive completion*/
	return UDR;
}

void MUART_Transmit(u8 data[])
{
	u8 i = 0;
	while(data[i] != '\0')
	{
	UDR = data[i];
	while(!( UCSRA & ( 1 << 5 )));/*Wait for transmit completion*/
	i++;
	}
}
