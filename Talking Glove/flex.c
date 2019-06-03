/*
 * flex.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#include "types.h"
#include "reg.h"
#include "flex.h"
#include "adc.h"

u8 Flex_GetResult(void)
{
	u8 x=ADC_GetRes();
	return x;
}

void StopReadingFlex(void)
{
	ADCSRA.ADEN=0;
}

void StartReadingFlex(u8 x)
{
	ADC_INIT(x);
}
