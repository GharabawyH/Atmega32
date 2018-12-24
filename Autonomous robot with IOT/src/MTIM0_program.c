/*
 * MTIM0_program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#include "LSTD_TYPES.h"
#include "MTIM0_private.h"
#include "MTIM0_interface.h"
#include <avr/interrupt.h>

void (*MTIM0_CallBack)(void);

void MTIM0_Initialize(void)
{
	TCCR0  = 0x0D ;
	TIMSK |= 1 << 1;
	TIFR  |= 1 << 1;
	OCR0   = 79;
	SREG  |= 1<<7;
}

ISR(TIMER0_COMP_vect)
{
	MTIM0_CallBack();
}

void MTIM0_SetCallBack(void(*ptr)(void))
{
	MTIM0_CallBack = ptr;
}
