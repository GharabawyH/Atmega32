/*
 * MI2C_interface.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#ifndef MI2C_INTERFACE_H_
#define MI2C_INTERFACE_H_

/* defines the data direction (reading from I2C device) in i2c_start(),i2c_rep_start() */
#define I2C_READ    1

/* defines the data direction (writing to I2C device) in i2c_start(),i2c_rep_start() */
#define I2C_WRITE   0

extern void MI2C_init(void);
extern void MI2C_stop(void);
extern void MI2C_start(u8 addr);
extern void MI2C_rep_start(u8 addr);
extern void MI2C_write(u8 data);
extern u8 MI2C_readAck(void);
extern u8 MI2C_readNak(void);
extern u8 MI2C_read(u8 ack);

#endif /* MI2C_INTERFACE_H_ */
