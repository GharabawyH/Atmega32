
#define F_CPU 8000000UL
#include <util/delay.h>

#include "LSTD_TYPES.h"
#include "HULTRASONIC_interface.h"
#include "HESP_interface.h"
#include "RTOS_interface.h"
#include "HBMP180_interface.h"
#include "HDHT11_interface.h"
#include "HDCMOTOR_interface.h"

volatile u32 Pressure;
volatile f64 Temp;
volatile f64 Altitude;
volatile u8  S , S1;
volatile u8  Humidity;
volatile u64 Pulse;
volatile u64 Distance;
volatile u8  flag;
volatile u8* Buffer;

void Task1(void)
{
	HMOTOR_Stop(LEFT_MOTOR);
	HMOTOR_Stop(RIGHT_MOTOR);
	HDHT11_SetupForDataReceive();
	HDHT11_CalculateData();
	Humidity = HDHT11_GetHumidity();
	Temp 	 = HBMP180_gettemperature();
	Pressure = HBMP180_getpressure();
	Altitude = HBMP180_getaltitude();
	HESP_ConnectToHost();
	HESP_SendData(Temp , Pressure , Altitude , Humidity);
}

void Task2(void)
{
	HULTRASONIC_SendTrigger();
}

void HULTRASONIC_Decision(void)
{
	flag++;
	if(flag == 3)
	{
		flag = 0;
		/*Pulse = HULTRASONIC_CalculateDistance();
		Buffer = IntegerToAscii(Pulse);
		MUART_Transmit(Buffer);
		MUART_Transmit("\r");*/
		Distance = ((Pulse*214375)/(100000000));
		/*Buffer = IntegerToAscii(Distance);
		MUART_Transmit(Buffer);
		MUART_Transmit("\r");*/
		if((Distance > 25) || (Distance < 8))
		{
			HMOTOR_Start(LEFT_MOTOR , Dir2);
			HMOTOR_Start(RIGHT_MOTOR , Dir2);
			HMOTOR_PWM_Output(LEFT_MOTOR , 20000);
			HMOTOR_PWM_Output(RIGHT_MOTOR , 20000);
		}
		else
		{
			HMOTOR_Start(LEFT_MOTOR , Dir2);
			HMOTOR_Start(RIGHT_MOTOR , Dir1);
			HMOTOR_PWM_Output(LEFT_MOTOR , 20000);
			HMOTOR_PWM_Output(RIGHT_MOTOR , 20000);
		}
	}
}

void main(void)
{
	HDHT11_Initialize();
	HBMP180_Initialize();
	HESP_Initialize();
	MINT0_SetCallBack(HULTRASONIC_Decision);
	HULTRASONIC_Initialize();
	HMOTOR_Initialize();
	RTOS_Initialize();
	RTOS_CreateTask(0,5,Task2);
	RTOS_CreateTask(1,500,Task1);
	while (1)
	{

	}
}
