/*
 * dio.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#ifndef DIO_H_
#define DIO_H_


void MDIO_SetPortDirection(u8 DIO_PortNum,u8 DIO_PortValue);
void MDIO_WritePortValue(u8 DIO_PortNum,u8 DIO_PortValue);
u8 MDIO_ReadPortValue(u8 DIO_PortNum);
void MDIO_SetPinDirection(u8 DIO_PortNum,u8 DIO_PinNum,u8 DIO_PinValue);
void MDIO_WritePinValue(u8 DIO_PortNum,u8 DIO_PinNum,u8 DIO_PinValue);
u8 MDIO_ReadPinValue(u8 DIO_PortNum,u8 DIO_PinNum);

#define DIO_HIGH		1
#define DIO_LOW			0
#define DIO_PORT_HIGH	255

#define DIO_u8Pin0 0
#define DIO_u8Pin1 1
#define DIO_u8Pin2 2
#define DIO_u8Pin3 3
#define DIO_u8Pin4 4
#define DIO_u8Pin5 5
#define DIO_u8Pin6 6
#define DIO_u8Pin7 7



#define DIO_PORTA	0
#define	DIO_PORTB	1
#define DIO_PORTC	2
#define DIO_PORTD	3

#define DIO_DDRA	0
#define	DIO_DDRB	1
#define DIO_DDRC	2
#define DIO_DDRD	3

#define DIO_PINA	0
#define	DIO_PINB	1
#define DIO_PINC	2
#define DIO_PIND	3

#endif /* DIO_H_ */
