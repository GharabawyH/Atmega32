/*
 * HULTRASONIC_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#ifndef HULTRASONIC_INTERFACE_H_
#define HULTRASONIC_INTERFACE_H_



void HULTRASONIC_Initialize(void);
void HULTRASONIC_SendTrigger(void);
u16 HULTRASONIC_CalculateDistance(void);


#endif /* HULTRASONIC_INTERFACE_H_ */
