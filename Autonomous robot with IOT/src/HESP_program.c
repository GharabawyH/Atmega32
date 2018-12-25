#include "LSTD_TYPES.h"

#include "HESP_interface.h"

#define F_CPU	8000000

#include <avr/delay.h>

#include "HESP_private.h"

#include "MUART_interface.h"

#include "LASCII_CONVERT.h"


volatile u8*Temperature;
volatile u8*Altitude;
volatile u8*Pressure;
volatile u8*Humidity;



void HESP_INIT(void)
{
	MUART_INIT();
	MUART_Transmit("AT+RST\r\n");
	_delay_ms(500);
	MUART_Transmit("AT+CWQAP\r\n");
	_delay_ms(1000);
	MUART_Transmit("AT+CWJAP=\"your ssid\",\"your ssid password\"\r\n");
	_delay_ms(5000);
}

void HESP_ConnectToHost(void)
{
	MUART_Transmit("AT+CIPSTART=\"TCP\",\"your host\",80\r\n");
	_delay_ms(500);
}

void HESP_SendData(f64 Temp , u16 Press , f64 Alt , u8 Hum)
{
	MUART_Transmit("AT+CIPSEND=the no of characters you're going to send\r\n");
	_delay_ms(500);
	MUART_Transmit("POST /file.php HTTP/1.1\r\nHost: your host\r\nContent-Type: application/x-www-form-urlencoded\r\nContent-Length: 72\r\n\r\nTemperature=");
	Temperature = FloatToAscii(Temp);
	MUART_Transmit(Temperature);
	MUART_Transmit("C&Pressure=");
	Pressure = IntegerToAscii(Press);
	MUART_Transmit(Pressure);
	MUART_Transmit("hPa&Altitude=");
	Altitude = FloatToAscii(Alt);
	MUART_Transmit(Altitude);
	MUART_Transmit("meters&Humidity=");
	Humidity = IntegerToAscii(Hum);
	MUART_Transmit(Humidity);
	MUART_Transmit("\%RH\r\n\r\n");
	_delay_ms(5000);
}

void HESP_DisconnectFromHost(void)
{
	MUART_Transmit("AT+CIPCLOSE\r\n");
	_delay_ms(500);
}
