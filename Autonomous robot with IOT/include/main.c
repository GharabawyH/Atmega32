
#define F_CPU 8000000UL
#include <util/delay.h>

#include "LSTD_TYPES.h"
#include "HULTRASONIC_interface.h"
#include "HESP_interface.h"
#include "RTOS_interface.h"
#include "HBMP180_interface.h"
#include "HDCMOTOR_interface.h"

volatile u32 Pressure;
volatile f64 Temp;
volatile f64 Altitude;
volatile u8 S , S1;
volatile u8 Humidity;
volatile u64 Pulse;
volatile u64 Distance;

void Task1(void)
{
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
	Pulse = HULTRASONIC_CalculateDistance();
	Distance = ((Pulse*214375)/(100000000));
	if(Distance > 10)
	{
		HMOTOR_Start(LEFT_MOTOR , Dir1);
		HMOTOR_Start(RIGHT_MOTOR , Dir1);
	}
	else
	{
		HMOTOR_Start(LEFT_MOTOR , Dir2);
	}
}

void main(void)
{
	HDHT11_Initialize();
	HBMP180_init();
	HESP_INIT();
	MINT0_SetCallBack(HULTRASONIC_Decision);
	HULTRASONIC_Initialize();
	HMOTOR_Initialize();
	HMOTOR_Enable(LEFT_MOTOR);
	HMOTOR_Enable(RIGHT_MOTOR);
	RTOS_Initialize();
	RTOS_CreateTask(0,50,Task2);
	RTOS_CreateTask(1,500,Task1);
	while (1)
	{

	}
}
