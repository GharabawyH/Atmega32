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
	TCCR0  = 0x0D ;/*Initialize Timer 0 with 1024 prescaler in CTC mode*/
	TIMSK |= 1 << 1;/*Enable Timer 0 Output Compare Match Interrupt*/
	TIFR  |= 1 << 1;/*Clear Timer 0 Output Compare Match Interrupt Flag*/
	OCR0   = 79;/*Set to reach TOP after ~ 10ms*/
	SREG  |= 1<<7;/*Enable global interrupt*/
}

ISR(TIMER0_COMP_vect)
{
	MTIM0_CallBack();
}

void MTIM0_SetCallBack(void(*ptr)(void))
{
	MTIM0_CallBack = ptr;
}
