/*
 * HDCMOTOR_interface.h
 *
 *  Created on: ??‏/??‏/????
 *      Author: H
 */

#ifndef HDCMOTOR_INTERFACE_H_
#define HDCMOTOR_INTERFACE_H_

void HMOTOR_Initialize(void);
void HMOTOR_Start(u8 Motor , u8 Direction);
void HMOTOR_NonPWM_Enable(u8 Motor);
void HMOTOR_Stop(u8 Motor);
void HMOTOR_PWM_Output(u8 Motor , u16 Speed);

#define LEFT_MOTOR	1
#define RIGHT_MOTOR	2
#define Dir1		3
#define Dir2		4

#endif /* HDCMOTOR_INTERFACE_H_ */
