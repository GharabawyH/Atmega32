/*
 * HBMP180_program.c
 *
 *  Created on: ??‏/??‏/????
 *      Author: H
 */

#include "LSTD_TYPES.h"
#include <util/delay.h>
#include <math.h>
#include "HBMP180_private.h"
#include "HBMP180_interface.h"
#include "MI2C_interface.h"


volatile s16 HBMP180_AC1, HBMP180_AC2, HBMP180_AC3, HBMP180_B1, HBMP180_B2, HBMP180_MB, HBMP180_MC, HBMP180_MD;
volatile u16 HBMP180_AC4, HBMP180_AC5, HBMP180_AC6;
volatile s32 HBMP180_rawtemperature, HBMP180_rawpressure;


void HBMP180_writemem(u8 reg, u8 value)
{
	MI2C_start(HBMP180_ADDR | I2C_WRITE);
	MI2C_write(reg);
	MI2C_write(value);
	MI2C_stop();
}


void HBMP180_readmem(u8 reg, u8 buff[], u8 bytes)
{
	u8 i =0;
	MI2C_start(HBMP180_ADDR | I2C_WRITE);
	MI2C_write(reg);
	MI2C_rep_start(HBMP180_ADDR | I2C_READ);
	for(i=0; i<bytes; i++)
	{
		if(i==bytes-1)
			buff[i] = MI2C_readNak();
		else
			buff[i] = MI2C_readAck();
	}
	MI2C_stop();
}


#if HBMP180_FILTERPRESSURE == 1
static s32 k[HBMP180_AVERAGECOEF];
s32 HBMP180_avaragefilter(s32 input)
{
	u8 i=0;
	s32 sum=0;
	for (i=0; i<HBMP180_AVERAGECOEF; i++)
	{
		k[i] = k[i+1];
	}
	k[HBMP180_AVERAGECOEF-1] = input;
	for (i=0; i<HBMP180_AVERAGECOEF; i++)
	{
		sum += k[i];
	}
	return (sum /HBMP180_AVERAGECOEF) ;
}
#endif

/*
 * read calibration registers
 */
void HBMP180_getcalibration()
{
	u8 buff[2];

	HBMP180_readmem(HBMP180_REGAC1, buff, 2);
	HBMP180_AC1 = ((s16)buff[0] <<8 | ((s16)buff[1]));
	HBMP180_readmem(HBMP180_REGAC2, buff, 2);
	HBMP180_AC2 = ((s16)buff[0] <<8 | ((s16)buff[1]));
	HBMP180_readmem(HBMP180_REGAC3, buff, 2);
	HBMP180_AC3 = ((s16)buff[0] <<8 | ((s16)buff[1]));
	HBMP180_readmem(HBMP180_REGAC4, buff, 2);
	HBMP180_AC4 = ((u16)buff[0] <<8 | ((u16)buff[1]));
	HBMP180_readmem(HBMP180_REGAC5, buff, 2);
	HBMP180_AC5 = ((u16)buff[0] <<8 | ((u16)buff[1]));
	HBMP180_readmem(HBMP180_REGAC6, buff, 2);
	HBMP180_AC6 = ((u16)buff[0] <<8 | ((u16)buff[1]));
	HBMP180_readmem(HBMP180_REGB1, buff, 2);
	HBMP180_B1 = ((s16)buff[0] <<8 | ((s16)buff[1]));
	HBMP180_readmem(HBMP180_REGB2, buff, 2);
	HBMP180_B2 = ((s16)buff[0] <<8 | ((s16)buff[1]));
	HBMP180_readmem(HBMP180_REGMB, buff, 2);
	HBMP180_MB = ((s16)buff[0] <<8 | ((s16)buff[1]));
	HBMP180_readmem(HBMP180_REGMC, buff, 2);
	HBMP180_MC = ((s16)buff[0] <<8 | ((s16)buff[1]));
	HBMP180_readmem(HBMP180_REGMD, buff, 2);
	HBMP180_MD = ((s16)buff[0] <<8 | ((s16)buff[1]));
}

/*
 * get raw temperature as read by registers, and do some calculation to convert it
 */
void HBMP180_getrawtemperature()
{
	u8 buff[2];

	s32 ut,x1,x2;

	//read raw temperature
	HBMP180_writemem(HBMP180_REGCONTROL, HBMP180_REGREADTEMPERATURE);
	_delay_ms(5); // min. 4.5ms read Temp delay
	HBMP180_readmem(HBMP180_REGCONTROLOUTPUT, buff, 2);
	ut = ((s32)buff[0] << 8 | ((s32)buff[1])); //uncompensated temperature value

	//calculate raw temperature
	x1 = ((s32)ut - HBMP180_AC6) * HBMP180_AC5 >> 15;
	x2 = ((s32)HBMP180_MC << 11) / (x1 + HBMP180_MD);
	HBMP180_rawtemperature = x1 + x2;
}

/*
 * get raw pressure as read by registers, and do some calculation to convert it
 */
void HBMP180_getrawpressure()
{
	u8 buff[3];

	s32 up,x1,x2,x3,b3,b6,p;
	u32 b4,b7;

#if HBMP180_AUTOUPDATETEMP == 1
	HBMP180_getrawtemperature();
#endif

	//read raw pressure
	HBMP180_writemem(HBMP180_REGCONTROL, HBMP180_REGREADPRESSURE+(HBMP180_MODE << 6));
	_delay_ms(2 + (3<<HBMP180_MODE));
	HBMP180_readmem(HBMP180_REGCONTROLOUTPUT, buff, 3);
	up = ((((s32)buff[0] <<16) | ((s32)buff[1] <<8) | ((s32)buff[2])) >> (8-HBMP180_MODE)); // uncompensated pressure value

	//calculate raw pressure
	b6 = HBMP180_rawtemperature - 4000;
	x1 = (HBMP180_B2* (b6 * b6) >> 12) >> 11;
	x2 = (HBMP180_AC2 * b6) >> 11;
	x3 = x1 + x2;
	b3 = (((((s32)HBMP180_AC1) * 4 + x3) << HBMP180_MODE) + 2) >> 2;
	x1 = (HBMP180_AC3 * b6) >> 13;
	x2 = (HBMP180_B1 * ((b6 * b6) >> 12)) >> 16;
	x3 = ((x1 + x2) + 2) >> 2;
	b4 = (HBMP180_AC4 * (u32)(x3 + 32768)) >> 15;
	b7 = ((u32)up - b3) * (50000 >> HBMP180_MODE);
	p = b7 < 0x80000000 ? (b7 << 1) / b4 : (b7 / b4) << 1;
	x1 = (p >> 8) * (p >> 8);
	x1 = (x1 * 3038) >> 16;
	x2 = (-7357 * p) >> 16;
	HBMP180_rawpressure = p + ((x1 + x2 + 3791) >> 4);

#if HBMP180_FILTERPRESSURE == 1
	HBMP180_rawpressure = HBMP180_avaragefilter(HBMP180_rawpressure);
#endif
}

/*get celsius temperature*/
f64 HBMP180_gettemperature()
{
	HBMP180_getrawtemperature();
	f64 temperature = ((HBMP180_rawtemperature + 8)>>4);
	temperature = temperature /10;
	return temperature;
}

/*get pressure*/
s32 HBMP180_getpressure()
{
	HBMP180_getrawpressure();
	return (HBMP180_rawpressure)/100;
}

/*get altitude*/
f64 HBMP180_getaltitude()
{
	HBMP180_getrawpressure();
	return (((1 - pow(HBMP180_rawpressure/(f64)101938, 0.1903 )) / 0.0000225577));
}

/*init HBMP180*/
void HBMP180_Initialize()
{
	MI2C_init();
	_delay_us(10);

	HBMP180_getcalibration(); //get calibration data
	HBMP180_getrawtemperature(); //update raw temperature, at least the first time

#if HBMP180_FILTERPRESSURE == 1
	/*Average filter initialize*/
	u8 i=0;
	for (i=0; i<HBMP180_AVERAGECOEF; i++) 
	{
		HBMP180_getrawpressure();
	}
#endif
}
