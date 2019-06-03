/*
 * dio.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#ifndef DIO_H_
#define DIO_H_


void DIO_SetPortDirection(u8 DIO_PortNum,u8 DIO_PortValue);
void DIO_WritePortValue(u8 DIO_PortNum,u8 DIO_PortValue);
u8 DIO_ReadPortValue(u8 DIO_PortNum);
void DIO_SetPinDirection(u8 DIO_PortNum,u8 DIO_PinNum,u8 DIO_PinValue);
void DIO_WritePinValue(u8 DIO_PortNum,u8 DIO_PinNum,u8 DIO_PinValue);
u8 DIO_ReadPinValue(u8 DIO_PortNum,u8 DIO_PinNum);



#endif /* DIO_H_ */
