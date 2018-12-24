#include "LSTD_TYPES.h"

#include "MTIM1_private.h"

#include "MTIM1_interface.h"

#include <avr/interrupt.h>

void (*MTIM1_CallBack)(void);

void MTIM1_Initialize(void)
{
	TCCR1A = 0x00;
	TCCR1B = 0x01;
//	OCR1A  = 1565;
//	OCR1B  = 25000;
//	TIMSK |= 0x10;
//	TIFR  |= 0x10;
	SREG  |= 1<<7;
	TCNT1 = 0;
}

ISR(TIMER1_COMPA_vect)
{
	MTIM1_CallBack();
}


void MTIM1_SetCallBack(void(*Ptr)(void))
{
	MTIM1_CallBack = Ptr;
}


