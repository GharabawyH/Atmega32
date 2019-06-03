/*
 * ADC_isr.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#include <avr/interrupt.h>

void(*ptr)(void);




void SetCallBackADC_INT(void(*ptr1)(void))
{
	ptr=ptr1;
}



ISR(ADC_vect)
{
	ptr();
}
