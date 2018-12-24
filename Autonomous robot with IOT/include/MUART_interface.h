/*
 * uart.h
 *
 *  Created on: ??þ/??þ/????
 *      Author: H
 */

#ifndef UART_H_
#define UART_H_


void MUART_INIT(void);
u8 MUART_Recieve(void);
void MUART_Transmit(u8 data[]);

#endif /* UART_H_ */
