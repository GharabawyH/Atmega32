/*
 * MINT_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#ifndef MINT_PRIVATE_H_
#define MINT_PRIVATE_H_


#define MCUCR	(*((volatile u8*)0x55))
#define MCUCSR	(*((volatile u8*)0x54))
#define GICR	(*((volatile u8*)0x5B))
#define GIFR	(*((volatile u8*)0x5A))
#define SREG	(*((volatile u8*)0x5F))



#endif /* MINT_PRIVATE_H_ */
