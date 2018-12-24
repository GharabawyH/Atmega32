/*
 * HBMP180_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#ifndef HBMP180_PRIVATE_H_
#define HBMP180_PRIVATE_H_

#define HBMP180_ADDR (0x77<<1) //0x77 default I2C address

#define HBMP180_I2CINIT 1 //init i2c

//registers
#define HBMP180_REGAC1 0xAA
#define HBMP180_REGAC2 0xAC
#define HBMP180_REGAC3 0xAE
#define HBMP180_REGAC4 0xB0
#define HBMP180_REGAC5 0xB2
#define HBMP180_REGAC6 0xB4
#define HBMP180_REGB1 0xB6
#define HBMP180_REGB2 0xB8
#define HBMP180_REGMB 0xBA
#define HBMP180_REGMC 0xBC
#define HBMP180_REGMD 0xBE
#define HBMP180_REGCONTROL 0xF4 //control
#define HBMP180_REGCONTROLOUTPUT 0xF6 //output 0xF6=MSB, 0xF7=LSB, 0xF8=XLSB
#define HBMP180_REGREADTEMPERATURE 0x2E //read temperature
#define HBMP180_REGREADPRESSURE 0x34 //read pressure

//modes
#define HBMP180_MODEULTRALOWPOWER 0 //oversampling=0, internalsamples=1, maxconvtimepressure=4.5ms, avgcurrent=3uA, RMSnoise_hPA=0.06, RMSnoise_m=0.5
#define HBMP180_MODESTANDARD 1 //oversampling=1, internalsamples=2, maxconvtimepressure=7.5ms, avgcurrent=5uA, RMSnoise_hPA=0.05, RMSnoise_m=0.4
#define HBMP180_MODEHIGHRES 2 //oversampling=2, internalsamples=4, maxconvtimepressure=13.5ms, avgcurrent=7uA, RMSnoise_hPA=0.04, RMSnoise_m=0.3
#define HBMP180_MODEULTRAHIGHRES 3 //oversampling=3, internalsamples=8, maxconvtimepressure=25.5ms, avgcurrent=12uA, RMSnoise_hPA=0.03, RMSnoise_m=0.25

//autoupdate temperature enabled
#define HBMP180_AUTOUPDATETEMP 1 //autoupdate temperature every read

//setup parameters
#define HBMP180_MODE HBMP180_MODEULTRAHIGHRES //define a mode
#define HBMP180_UNITPAOFFSET 0 //define a unit offset (pa)
#define HBMP180_UNITMOFFSET 0 //define a unit offset (m)

//avarage filter
#define HBMP180_FILTERPRESSURE 1 //avarage filter for pressure


#define HBMP180_AVARAGECOEF 21
//variables
s16 HBMP180_regac1, HBMP180_regac2, HBMP180_regac3, HBMP180_regb1, HBMP180_regb2, HBMP180_regmb, HBMP180_regmc, HBMP180_regmd;
u16 HBMP180_regac4, HBMP180_regac5, HBMP180_regac6;
s32 HBMP180_rawtemperature, HBMP180_rawpressure;

#endif /* HBMP180_PRIVATE_H_ */
