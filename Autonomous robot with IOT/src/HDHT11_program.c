/*
 * HDHT11_program.c
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#define F_CPU 8000000UL
#include "LSTD_TYPES.h"
#include "HDHT11_interface.h"
#include "HDHT11_private.h"
#include "MDIO_interface.h"
#include <util/delay.h>



volatile u8 Temp;
volatile u8 Humidity;


void HDHT11_Initialize(void)
{
	_delay_ms(1000);
}

u8 HDHT11_SetupForDataReceive(void)
{
	MDIO_SetPinDirection(DHT11_PinDir,DHT11_Pin,DIO_HIGH);
	MDIO_WritePinValue(DHT11_PinVal,DHT11_Pin,DIO_LOW);
	_delay_ms(18);
	MDIO_SetPinDirection(DHT11_PinDir,DHT11_Pin,DIO_LOW);
	_delay_us(40);
	if(MDIO_ReadPinValue(DHT11_PinRead,DHT11_Pin))
	{
		return 1;
	}
	_delay_us(80);
	if(!(MDIO_ReadPinValue(DHT11_PinRead,DHT11_Pin)))
	{
		return 2;
	}
	_delay_us(80);

	return 0;
}

u8 HDHT11_CalculateData(void)
{
	u8 tmp;
	u8 Data[5]={0,0,0,0,0};
	u8 i=0;
	u8 j=0;
	for( j = 0 ; j < 5 ; j++)
	{
		tmp = 0;
		for( i = 0 ; i < 8 ; i++)
		{
			while(!(MDIO_ReadPinValue(DHT11_PinRead,DHT11_Pin)));/*Wait for High signal*/
			_delay_us(30);
			if(MDIO_ReadPinValue(DHT11_PinRead,DHT11_Pin))
			{
				Data[j] |= (1 << ( 7 - i ));
				while(MDIO_ReadPinValue(DHT11_PinRead,DHT11_Pin));/*Wait for Low signal*/
			}
		}

	}
	if ((u8)(Data[0] + Data[1] + Data[2] + Data[3]) == Data[4])
	{
		Humidity = Data[0];
		Temp	 = Data[2];
	}
	else
	{
		return 3;
	}
	return 0;
}

u8 HDHT11_GetHumidity(void)
{
	return Humidity;
}

u8 HDHT11_GetTemp(void)
{
	return Temp;
}
