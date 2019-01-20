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

void MTIM1_PWM_Initialize(void)
{
	TCCR1A = 0xA2;
	TCCR1B = 0x19;
	ICR    = 0xFFFF;
}

void MTIM1_PWM_Output_ChannelA(u16 ChannelA)
{
	OCR1A = ChannelA;
}

void MTIM1_PWM_Output_ChannelB(u16 ChannelB)
{
	OCR1B = ChannelB;
}

ISR(TIMER1_COMPA_vect)
{
	MTIM1_CallBack();
}


void MTIM1_SetCallBack(void(*Ptr)(void))
{
	MTIM1_CallBack = Ptr;
}


