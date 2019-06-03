/*
 * reg.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */


#ifndef REG_H_
#define REG_H_

#include "types.h"

typedef union
{
	u8 value;
	u16 value1;
	struct
	{
		u8 ISC00:1;
		u8 ISC01:1;
		u8 ISC10:1;
		u8 ISC11:1;
		u8 SM0:1;
		u8 SM1:1;
		u8 SM2:1;
		u8 SE:1;
	};
}MCUCR_uni;

typedef union
{
	u8 value;
	u16 value1;
	struct
	{
		u8 IVCE:1;
		u8 IVSEL:1;
		u8 Res1:1;
		u8 Res2:1;
		u8 Res3:1;
		u8 INT2:1;
		u8 INT0:1;
		u8 INT1:1;
	};
}GICR_uni;

typedef union
{
	u8 value;
	u16 value1;
	struct
	{
		u8 C:1;
		u8 Z:1;
		u8 N:1;
		u8 V:1;
		u8 S:1;
		u8 H:1;
		u8 T:1;
		u8 I:1;
	};
}SREG_uni;


typedef union
{
	u8 value;
	u16 value1;
	struct
	{
		u8 MUX0:1;
		u8 MUX1:1;
		u8 MUX2:1;
		u8 MUX3:1;
		u8 MUX4:1;
		u8 ADLAR:1;
		u8 REFS0:1;
		u8 REFS1:1;
	};
}ADMUX_uni;

typedef union
{
	u8 value;
	u16 value1;
	struct
	{
		u8 ADPS0:1;
		u8 ADPS1:1;
		u8 ADPS2:1;
		u8 ADIE:1;
		u8 ADIF:1;
		u8 ADATE:1;
		u8 ADSC:1;
		u8 ADEN:1;
	};
}ADCSRA_uni;

typedef union
{
	u8 value;
	u16 value1;
	struct
	{
		u8 PSR10:1;
		u8 PSR2:1;
		u8 PUD:1;
		u8 ACME:1;
		u8 Reserved:1;
		u8 ADTS0:1;
		u8 ADTS1:1;
		u8 ADTS2:1;
	};
}SFIOR_uni;

#define PORTA	(*((volatile u8*)0x3B))
#define DDRA	(*((volatile u8*)0x3A))
#define PINA	(*((volatile u8*)0x39))

#define PORTB	(*((volatile u8*)0x38))
#define DDRB	(*((volatile u8*)0x37))
#define PINB	(*((volatile u8*)0x36))

#define PORTC	(*((volatile u8*)0x35))
#define DDRC	(*((volatile u8*)0x34))
#define PINC	(*((volatile u8*)0x33))

#define PORTD	(*((volatile u8*)0x32))
#define DDRD	(*((volatile u8*)0x31))
#define PIND	(*((volatile u8*)0x30))

#define MCUCR	(*((volatile MCUCR_uni*)0X55))
#define GICR	(*((volatile GICR_uni*)0X5B))
#define SREG	(*((volatile SREG_uni*)0X5F))

#define ADMUX	(*((volatile ADMUX_uni*)0x27))
#define ADCSRA	(*((volatile ADCSRA_uni*)0x26))
#define ADCH	(*((volatile u8*)0x25))
#define SFIOR	(*((volatile SFIOR_uni*)0x50))

#endif /* REG_H_ */
