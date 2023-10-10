/*
 * i2c.c
 *
 *  Created on: May 12, 2023
 *      Author: Abdelrhman Hesham
 */

#include "avr/io.h"
#include "common_macros.h"

void I2C_init(void)
{
	TWCR = (1<<TWEN);
	TWBR = 2;
	TWSR = 0;
	TWAR = 0b00000010; // ADDRESS OF DEVICE USING I2C
}

void TWI_start(void)
{
	TWCR = (1<<TWSTA) | (1<<TWEN) | (1<<TWINT);//ashan ana awez dol bs set
	while(BIT_IS_CLEARED(TWCR,TWINT));
}

void TWI_stop(void)
{
	TWCR = (1<<TWSTA) | (1<<TWSTO) | (1<<TWINT);
}

void TWI_writeByte(uint8 data)
{
	TWDR = data;
	TWCR = (1<<TWINT) | (1<<TWEN); // CLEARING FLAG AT START OF ANY FUNCTION
	while(BIT_IS_CLEARED(TWCR,TWINT));
}

uint8 TWI_readByteWithACK(void)
{
	TWCR = (1<<TWEA) | (1<<TWEN) | (1<<TWINT);
	while(BIT_IS_CLEARED(TWCR,TWINT));
	return TWDR;
}

uint8 TWI_readByteWithNACK(void)
{
	TWCR = (1<<TWEN) | (1<<TWINT);
	while(BIT_IS_CLEARED(TWCR,TWINT));
	return TWDR;
}

uint8 TWI_getStatus(void)
{
	uint8 status;
	status = TWSR & 0xF8;
	return status;
}
