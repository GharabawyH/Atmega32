/*
 * isr.c
 *
 *  Created on: ??þ/??þ/????
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
