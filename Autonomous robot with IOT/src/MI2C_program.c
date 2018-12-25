/*
 * MI2C_program.c
 *
 *  Created on: ??ţ/??ţ/????
 *      Author: H
 */

#include "LSTD_TYPES.h"

#include "MI2C_interface.h"

#include "MI2C_private.h"




void MI2C_init(void)
{
  /* initialize TWI clock: 100 kHz clock, TWPS = 0 => prescaler = 1 */
  TWSR = 0;                         /* no prescaler */
  TWBR = 32;  				/* must be > 10 for stable operation */
}


/* Issues a start condition and sends address and transfer direction.
   return 0 = device accessible, 1= failed to access device*/
void MI2C_start(u8 address)
{
    u8   twst;
	// send START condition
	TWCR = (1<<TWINT) | (1<<TWSTA) | (1<<TWEN);
	// wait until transmission completed
	while(!(TWCR & (1<<TWINT)));
	// check value of TWI Status Register. Mask prescaler bits.
	twst = TWSR & 0xF8;
	while ( (twst != TW_START) && (twst != TW_REP_START));
	// send device address
	TWDR = address;
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wail until transmission completed and ACK/NACK has been received
	while(!(TWCR & (1<<TWINT)));
	// check value of TWI Status Register. Mask prescaler bits.
	twst = TWSR & 0xF8;
	while ( (twst != TW_MT_SLA_ACK) && (twst != TW_MR_SLA_ACK) );

}
/*Issues a repeated start condition and sends address and transfer direction
 Input:   address and transfer direction of I2C device*/
void MI2C_rep_start(u8 address)
{
     MI2C_start( address );
}
/*Terminates the data transfer and releases the I2C bus*/
void MI2C_stop(void)
{
    /* send stop condition */
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
	// wait until stop condition is executed and bus released
	while(TWCR & (1<<TWSTO));
}
/*Send one byte to I2C device
  Input:byte to be transfered*/
void MI2C_write( u8 data )
{	
    u8  twst;
	// send data to the previously addressed device
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN);
	// wait until transmission completed
	while(!(TWCR & (1<<TWINT)));
	// check value of TWI Status Register. Mask prescaler bits
	twst = TWSR & 0xF8;
	while( twst != TW_MT_DATA_ACK);
}


/*Read one byte from the I2C device, request more data from device
 Return:  byte read from I2C device*/
u8 MI2C_readAck(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while(!(TWCR & (1<<TWINT)));    
    return TWDR;
}
/*Read one byte from the I2C device, read is followed by a stop condition
 Return:  byte read from I2C device*/
u8 MI2C_readNak(void)
{
	TWCR = (1<<TWINT) | (1<<TWEN);
	while(!(TWCR & (1<<TWINT)));
    return TWDR;
}
