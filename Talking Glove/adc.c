/*
 * adc.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#include "types.h"
#include "reg.h"
#include "dio.h"
#include "dio_cfg.h"

void ADC_INIT(u8 u)
{
	ADMUX.REFS1=0;
	ADMUX.REFS0=1;
	ADMUX.ADLAR=1;

	switch(u)
	{
	case 0:
	{
		ADMUX.MUX0=0;
		ADMUX.MUX1=0;
		ADMUX.MUX2=0;
		ADMUX.MUX3=0;
		ADMUX.MUX4=0;
		break;
	}
	case 1:
	{
		ADMUX.MUX0=1;
		ADMUX.MUX1=0;
		ADMUX.MUX2=0;
		ADMUX.MUX3=0;
		ADMUX.MUX4=0;
		break;
	}
	case 2:
	{
		ADMUX.MUX0=0;
		ADMUX.MUX1=1;
		ADMUX.MUX2=0;
		ADMUX.MUX3=0;
		ADMUX.MUX4=0;
		break;
	}
	case 3:
	{
		ADMUX.MUX0=1;
		ADMUX.MUX1=1;
		ADMUX.MUX2=0;
		ADMUX.MUX3=0;
		ADMUX.MUX4=0;
		break;
	}
	case 4:
	{
		ADMUX.MUX0=0;
		ADMUX.MUX1=0;
		ADMUX.MUX2=1;
		ADMUX.MUX3=0;
		ADMUX.MUX4=0;
		break;
	}

	}
	ADCSRA.ADEN=1;
	ADCSRA.ADATE=1;
	ADCSRA.ADIF=1;
	ADCSRA.ADIE=1;
	ADCSRA.ADPS2=1;
	ADCSRA.ADPS1=1;
	ADCSRA.ADPS0=1;
	ADCSRA.ADSC=1;
	SFIOR.ADTS0=0;
	SFIOR.ADTS1=0;
	SFIOR.ADTS2=0;
	SREG.I=1;
}


u8 ADC_GetRes(void)
{
	//	ADCSRA.ADSC=1;
	while(ADCSRA.ADIF==0);
	ADCSRA.ADIF=1;
	return ADCH;
}
