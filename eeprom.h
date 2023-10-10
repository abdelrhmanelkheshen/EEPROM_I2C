/*
 * eeprom.h
 *
 *  Created on: May 12, 2023
 *      Author: Abdelrhman Hesham
 */

#ifndef EEPROM_H_
#define EEPROM_H_

#define ERROR 0
#define SUCCESS 1

#include "std_types.h"

uint8 EEPROM_writeByte(uint16 u16addr,uint8 u8data);
uint8 EEPROM_readByte(uint16 u16addr,uint8 *u8data);

#endif /* EEPROM_H_ */
