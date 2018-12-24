/*
 * HDHT_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#ifndef HDHT11_INTERFACE_H_
#define HDHT11_INTERFACE_H_

#define DHT11_Pin		DIO_u8Pin7
#define DHT11_PinDir	DIO_DDRD
#define DHT11_PinVal	DIO_PORTD
#define DHT11_PinRead	DIO_PIND

void HDHT11_Initialize(void);
u8 HDHT11_SetupForDataReceive(void);
u8 HDHT11_CalculateData(void);
u8 HDHT11_GetHumidity(void);
u8 HDHT11_GetTemp(void);

#endif /* HDHT11_INTERFACE_H_ */
