/*
 * HDCMOTOR_program.c
 *
 *  Created on: ??‏/??‏/????
 *      Author: H
 */

#include "LSTD_TYPES.h"
#include "HDCMOTOR_interface.h"
#include "HDCMOTOR_private.h"
#include "MDIO_interface.h"
#include "MTIM1_interface.h"


void HMOTOR_Initialize(void)
{
	MDIO_SetPinDirection(DIO_DDRD,DIO_u8Pin4,DIO_HIGH);
	MDIO_SetPinDirection(DIO_DDRD,DIO_u8Pin5,DIO_HIGH);
	MTIM1_PWM_Initialize();
	MDIO_SetPortDirection(HMOTOR_IN_PORT , DIO_PORT_HIGH);
}

void HMOTOR_NonPWM_Enable(u8 Motor)
{
	switch(Motor)
	{
	case LEFT_MOTOR:MDIO_WritePinValue(HMOTOR_IN_PORT , LEFT_MOTOR_EN_PIN , DIO_HIGH);break;
	case RIGHT_MOTOR:MDIO_WritePinValue(HMOTOR_IN_PORT , RIGHT_MOTOR_EN_PIN , DIO_HIGH);break;
	}
}

void HMOTOR_PWM_Output(u8 Motor , u16 Speed)
{
	switch(Motor)
	{
	case LEFT_MOTOR:MTIM1_PWM_Output_ChannelB(Speed);break;
	case RIGHT_MOTOR:MTIM1_PWM_Output_ChannelA(Speed);break;
	}
}



void HMOTOR_Start(u8 Motor , u8 Direction)
{
	switch(Motor)
	{
	case LEFT_MOTOR:
	{
		switch(Direction)
		{
		case Dir1:MDIO_WritePinValue(HMOTOR_IN_PORT , LEFT_MOTOR_IN1_PIN , DIO_HIGH);
		MDIO_WritePinValue(HMOTOR_IN_PORT , LEFT_MOTOR_IN2_PIN , DIO_LOW);
		break;
		case Dir2:MDIO_WritePinValue(HMOTOR_IN_PORT , LEFT_MOTOR_IN1_PIN , DIO_LOW);
		MDIO_WritePinValue(HMOTOR_IN_PORT , LEFT_MOTOR_IN2_PIN , DIO_HIGH);
		break;
		}
		break;
	}
	case RIGHT_MOTOR:
	{
		switch(Direction)
		{
		case Dir1:MDIO_WritePinValue(HMOTOR_IN_PORT , RIGHT_MOTOR_IN3_PIN , DIO_HIGH);
		MDIO_WritePinValue(HMOTOR_IN_PORT , RIGHT_MOTOR_IN4_PIN , DIO_LOW);
		break;
		case Dir2:MDIO_WritePinValue(HMOTOR_IN_PORT , RIGHT_MOTOR_IN3_PIN , DIO_LOW);
		MDIO_WritePinValue(HMOTOR_IN_PORT , RIGHT_MOTOR_IN4_PIN , DIO_HIGH);
		break;
		}
		break;
	}
	}
}

void HMOTOR_Stop(u8 Motor)
{
	switch(Motor)
	{
	case LEFT_MOTOR:MDIO_WritePinValue(HMOTOR_IN_PORT , LEFT_MOTOR_IN1_PIN , DIO_LOW);
	MDIO_WritePinValue(HMOTOR_IN_PORT , LEFT_MOTOR_IN2_PIN , DIO_LOW);break;
	case RIGHT_MOTOR:MDIO_WritePinValue(HMOTOR_IN_PORT , RIGHT_MOTOR_IN3_PIN , DIO_LOW);
	MDIO_WritePinValue(HMOTOR_IN_PORT , RIGHT_MOTOR_IN4_PIN , DIO_LOW);break;
	}
}
