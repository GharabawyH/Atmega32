/*
 * MI2C_private.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#ifndef MI2C_PRIVATE_H_
#define MI2C_PRIVATE_H_


#define i2c_read(ack)  (ack) ? i2c_readAck() : i2c_readNak();

#define SCL_CLOCK  10000L

#define	TWCR	 (*((volatile u8*)0x56))
#define	TWSR	 (*((volatile u8*)0x21))
#define	TWDR	 (*((volatile u8*)0x23))
#define	TWAR	 (*((volatile u8*)0x22))
#define TWBR	 (*((volatile u8*)0x20))

/* TWCR */
#define TWINT   7
#define TWEA    6
#define TWSTA   5
#define TWSTO   4
#define TWWC    3
#define TWEN    2
/* bit 1 reserved */
#define TWIE    0

/* TWAR */
#define TWA6    7
#define TWA5    6
#define TWA4    5
#define TWA3    4
#define TWA2    3
#define TWA1    2
#define TWA0    1
#define TWGCE   0

/* TWSR */
#define TWS7    7
#define TWS6    6
#define TWS5    5
#define TWS4    4
#define TWS3    3
/* bit 2 reserved */
#define TWPS1   1
#define TWPS0   0

#define TW_START		0x08

/*repeated start condition transmitted */
#define TW_REP_START		0x10


/* SLA+W transmitted, ACK received */
#define TW_MT_SLA_ACK		0x18

/* SLA+W transmitted, NACK received */
#define TW_MT_SLA_NACK		0x20

/* data transmitted, ACK received */
#define TW_MT_DATA_ACK		0x28

/* data transmitted, NACK received */
#define TW_MT_DATA_NACK		0x30

/* arbitration lost in SLA+W or data */
#define TW_MT_ARB_LOST		0x38

/* arbitration lost in SLA+R or NACK */
#define TW_MR_ARB_LOST		0x38

/* SLA+R transmitted, ACK received */
#define TW_MR_SLA_ACK		0x40

/* SLA+R transmitted, NACK received */
#define TW_MR_SLA_NACK		0x48

/* data received, ACK returned */
#define TW_MR_DATA_ACK		0x50

/* data received, NACK returned */
#define TW_MR_DATA_NACK		0x58

/* SLA+R received, ACK returned */
#define TW_ST_SLA_ACK		0xA8

/* arbitration lost in SLA+RW, SLA+R received, ACK returned */
#define TW_ST_ARB_LOST_SLA_ACK	0xB0

/* data transmitted, ACK received */
#define TW_ST_DATA_ACK		0xB8

/* data transmitted, NACK received */
#define TW_ST_DATA_NACK		0xC0

/* last data byte transmitted, ACK received */
#define TW_ST_LAST_DATA		0xC8

/* SLA+W received, ACK returned */
#define TW_SR_SLA_ACK		0x60

/* arbitration lost in SLA+RW, SLA+W received, ACK returned */
#define TW_SR_ARB_LOST_SLA_ACK	0x68

/* general call received, ACK returned */
#define TW_SR_GCALL_ACK		0x70

/* arbitration lost in SLA+RW, general call received, ACK returned */
#define TW_SR_ARB_LOST_GCALL_ACK 0x78

/* data received, ACK returned */
#define TW_SR_DATA_ACK		0x80

/* data received, NACK returned */
#define TW_SR_DATA_NACK		0x88

/* general call data received, ACK returned */
#define TW_SR_GCALL_DATA_ACK	0x90

/* general call data received, NACK returned */
#define TW_SR_GCALL_DATA_NACK	0x98

/* stop or repeated start condition received while selected */
#define TW_SR_STOP		0xA0

/* no state information available */
#define TW_NO_INFO		0xF8

/* illegal start or stop condition */
#define TW_BUS_ERROR		0x00

#define _BV(bit) (1 << (bit))


//#define TW_STATUS_MASK		((1<<TWS7)|(1<<TWS6)|(1<<TWS5)|(1<<TWS4)|(1<<TWS3))


//#define TW_STATUS		(TWSR & TW_STATUS_MASK)


#endif /* MI2C_PRIVATE_H_ */
