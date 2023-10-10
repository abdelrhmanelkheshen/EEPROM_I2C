/*
 * common_macros.h
 *
 *  Created on: Apr 27, 2023
 *      Author: Abdelrhman Hesham
 */

#ifndef COMMON_MACROS_H_
#define COMMON_MACROS_H_


/*Set a certain bit in any register*/
#define SET_BIT(REG,BIT) ( REG |=  (1<<BIT) )

/*Clear a certain bit in any register*/
#define CLEAR_BIT(REG,BIT) ( REG &= (~(1<<BIT)) )

/*Toggle a certain bit in any register*/
#define TOGGLE_BIT(REG,BIT) ( REG ^= (1<<BIT) )

/*ROTATE A BIT TO THE RIGHT*/
#define ROR(REG,BIT) ( REG = (REG >> BIT) | (REG << (8-BIT)) )

/*ROTATE A BIT TO THE LEFT*/
#define ROL(REG,BIT) ( REG = (REG << BIT) | (REG >> (8-BIT)) )

/*CHECK WHETHER A BIT IS SET*/
#define BIT_IS_SET(REG,BIT) ( REG & (1<<BIT) )

/*CHECK WHETHER A BIT IS CLEARED*/
#define BIT_IS_CLEARED(REG,BIT) ( !(REG & (1<<BIT)) )

/*GET BIT FROM ANY REGISTER*/
#define GET_BIT(REG,BIT) ( ((REG & (1<<BIT)) >> BIT ) )

#endif /* COMMON_MACROS_H_ */
