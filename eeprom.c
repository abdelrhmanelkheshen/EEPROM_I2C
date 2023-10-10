/*
 * eeprom.c
 *
 *  Created on: May 12, 2023
 *      Author: Abdelrhman Hesham
 */
#include "eeprom.h"
#include "i2c.h"


uint8 EEPROM_writeByte(uint16 u16addr,uint8 u8data)
{
	TWI_start();
	if (TWI_getStatus() != TWI_START)
	{
		return ERROR;
	}
	TWI_writeByte((uint8)(0xA0 | ((u16addr & 0x0700)>>7)));
	TWI_writeByte((uint8)(u16addr));
	if(TWI_getStatus() != TWI_MT_DATA_ACK)
	{
		return ERROR;
	}
	TWI_writeByte(u8data);
	if(TWI_getStatus() != TWI_MT_DATA_ACK)
	{
		return ERROR;
	}
	TWI_stop();
	return SUCCESS;
}

uint8 EEPROM_readByte(uint16 u16addr,uint8 *u8data)
{
	TWI_start();
		if (TWI_getStatus() != TWI_START)
		{
			return ERROR;
		}
		TWI_writeByte((uint8)(0xA0 | ((u16addr & 0x0700)>>7)));
		TWI_writeByte((uint8)(u16addr));
		*u8data = TWI_readByteWithNACK();
		if(TWI_getStatus() != TWI_MR_DATA_NACK)
			{
				return ERROR;
			}
		return SUCCESS;
}
