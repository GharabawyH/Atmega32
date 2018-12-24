/*
 * MTIM0_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#ifndef MTIM0_PRIVATE_H_
#define MTIM0_PRIVATE_H_


#define SREG	 (*((volatile u8*)0x5F))
#define TCCR0	 (*((volatile u8*)0x53))
#define TCNT0	 (*((volatile u8*)0x52))
#define OCR0	 (*((volatile u8*)0x5C))
#define TIMSK	 (*((volatile u8*)0x59))
#define TIFR	 (*((volatile u8*)0x58))



#endif /* MTIM0_PRIVATE_H_ */
