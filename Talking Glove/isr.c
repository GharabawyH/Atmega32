/*
 * isr.c
 *
 *  Created on: ??�/??�/????
 *      Author: H
 */

#include "types.h"
#include "isr.h"
#include <avr/interrupt.h>

void(*ptr)(void);

void SetCallBackINT0(void(*ptr1)(void))
{
	ptr=ptr1;
}

ISR(INT0_vect)
{
	ptr();
}
