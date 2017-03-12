/*
  usi_twi.h

  Adapted from TinyWireM.h
    TinyWireM.h - a wrapper(+) class for TWI/I2C Master library for the ATtiny on Arduino
    1/21/2011 BroHogan -  brohoganx10 at gmail dot com

  Thanks to 'jkl' for the gcc version of Atmel's USI_TWI_Master code
  http://www.cs.cmu.edu/~dst/ARTSI/Create/PC%20Comm/
  I added Atmel's original Device dependant defines section back into USI_TWI_Master.h


 NOTE! - It's very important to use pullups on the SDA & SCL lines! More so than with the Wire lib.

 USAGE is modeled after the standard Wire library . . .
  Put in setup():
	TinyWireM.begin(){                               // initialize I2C lib
  To Send:
	TinyWireM.beginTransmission(uint8_t slaveAddr){  // setup slave's address (7 bit address - same as Wire)
	TinyWireM.send(uint8_t data){                    // buffer up bytes to send - can be called multiple times
	someByte = TinyWireM.endTransmission(){          // actually send the bytes in the buffer
	                                                 // returns (optional) 0 = sucess or see USI_TWI_Master.h for error codes
  To Receive:
	someByte = TinyWireM.requestFrom(uint8_t slaveAddr, uint8_t numBytes){      // reads 'numBytes' from slave's address
	                                                 // (usage optional) returns 0= success or see USI_TWI_Master.h for error codes
	someByte = TinyWireM.receive(){                  // returns the next byte in the received buffer - called multiple times
	someByte = TinyWireM.available(){                // returns the number of unread bytes in the received buffer

	TODO:	(by others!)
	- merge this class with TinyWireS for master & slave support in one library

	This library is free software; you can redistribute it and/or modify it under the
  terms of the GNU General Public License as published by the Free Software
  Foundation; either version 2.1 of the License, or any later version.
  This program is distributed in the hope that it will be useful, but WITHOUT ANY
  WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
  PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/

#ifndef USI_TWI_H_
#define USI_TWI_H_

#include <inttypes.h>

#define USI_SEND         0              // indicates sending to TWI
#define USI_RCVE         1              // indicates receiving from TWI
#define USI_BUF_SIZE    16              // bytes in message buffer

void twi_init(void);
void twi_begin_transmission(uint8_t);
void twi_send(uint8_t);

uint8_t twi_end_transmission(void);
uint8_t twi_end_transmission_stop(uint8_t);
uint8_t twi_request_from(uint8_t, uint8_t);
uint8_t twi_receive(void);
uint8_t twi_available(void);

#endif

