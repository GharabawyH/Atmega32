/*
 * MINT_program.c
 *
 *  Created on: ??ţ/??ţ/????
 *      Author: H
 */


#include "LSTD_TYPES.h"
#include "MINT_interface.h"
#include "MINT_private.h"
#include <avr/interrupt.h>

void(*MINT0_CallBack)(void);

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
				GICR |= 1 << 6;/*Enable External interrupt 0 request*/
				GIFR |= 1 << 6;/*Clear External interrupt 0 flag*/
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
				GICR |= 1 << 7;/*Enable External interrupt 1 request*/
				GIFR |= 1 << 7;/*Clear External interrupt 1 flag*/
				break;
			}
		}
		SREG |= 1<<7;/*Enable global interrupt*/
}

ISR(INT0_vect)
{
	MINT0_CallBack();
}


void MINT0_SetCallBack(void(*ptr)(void))
{
	MINT0_CallBack = ptr;
}
