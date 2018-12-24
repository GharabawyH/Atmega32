/*
 * MINT_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#ifndef MINT_INTERFACE_H_
#define MINT_INTERFACE_H_


#define MINT0 5
#define MINT1 4
#define RisingEdge 6
#define FallingEdge 7
#define LogicalChange 8

void MINT_Initialize(u8 InterruptNum , u8 Trigger);
void MINT0_SetCallBack(void(*ptr)(void));


#endif /* MINT_INTERFACE_H_ */
