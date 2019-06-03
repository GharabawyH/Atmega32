/*
 * intrpt.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */


#include "types.h"
#include "reg.h"
#include "intrpt.h"
#include "dio.h"
#include "dio_cfg.h"

void INIT_INT0(void)
{
	DIO_SetPinDirection(DIO_DDRD,DIO_u8Pin2,DIO_LOW);
	DIO_WritePinValue(DIO_PORTD,DIO_u8Pin2,DIO_HIGH);
	MCUCR.ISC00=0;
	MCUCR.ISC01=1;//Activate Interrupt 0 at falling edge
	GICR.INT0=1;//Enables Interrupt 0
	SREG.I=1;
}

void INIT_INT1(void)
{
	MCUCR.ISC10=1;
	MCUCR.ISC11=1;//Activate Interrupt 1 at rising edge
	GICR.INT1=1;//Enables Interrupt 1
	SREG.I=1;
}
