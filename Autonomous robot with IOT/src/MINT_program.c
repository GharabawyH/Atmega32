/*
 * MINT_program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */


#include "LSTD_TYPES.h"
#include "MINT_interface.h"
#include "MINT_private.h"
#include <avr/interrupt.h>

void(*MINT_CallBack)(void);

void MINT_Initialize(u8 InterruptNum , u8 Trigger)
{
		switch(InterruptNum)
		{
			case MINT0 :
			{
				switch(Trigger)
				{
					case RisingEdge		: MCUCR |= 0x3;break;
					case FallingEdge	: MCUCR |= 0x2;break;
					case LogicalChange	: MCUCR |= 0x1;break;
				}
				GICR |= 1 << 6;
				GIFR |= 1 << 6;
				break;
			}
			case INT1:
			{
				switch(Trigger)
				{
					case RisingEdge		: MCUCR |= 0xC;break;
					case FallingEdge	: MCUCR |= 0x8;break;
					case LogicalChange	: MCUCR |= 0x4;break;
				}
				GICR |= 1 << 7;
				GIFR |= 1 << 7;
				break;
			}
		}
		SREG |= 1<<7;
}

ISR(INT0_vect)
{
	MINT_CallBack();
}


void MINT0_SetCallBack(void(*ptr)(void))
{
	MINT_CallBack = ptr;
}
