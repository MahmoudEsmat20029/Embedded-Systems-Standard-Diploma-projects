/************************************************************************************
 * Module		: Common - Macros
 * File Name	: common_macros.h
 * Author		: Mahmoud 3smat
 * Created on	: 25/9/2024
 * Description	: Commonly used Macros
 ************************************************************************************/
#ifndef LIB_COMMON_MACROS_H_
#define LIB_COMMON_MACROS_H_

/* Set a certain bit in any register */
#define SET_BIT(REG, BIT_NUM) (REG |= (1<<BIT_NUM))

/* Clear a certain bit in any register */
#define CLEAR_BIT(REG, BIT_NUM) (REG &= (~(1<<BIT_NUM)))

/* Get bit high or low */
#define GET_BIT(REG, BIT_NUM) ((REG >> BIT_NUM) & 0x01)

/* Toggle a certain bit in any register */
#define TOGGLE_BIT(REG, BIT_NUM) (REG ^= (1<<BIT_NUM))

/* Rotate right the register value with specific number of rotates */
#define ROR(REG, NUM) (REG = (REG>>NUM) | (REG<<(8-NUM)))

/* Rotate left the register value with specific number of rotates */
#define ROL(REG, NUM) (REG = (REG<<NUM) | (REG>>(8-NUM)))

/* Check if a specific bit is set in any register and return true if yes */
#define BIT_IS_SET(REG,BIT_NUM) (REG & (1<<BIT_NUM))

/* Check if a specific bit is cleared in any register and return true if yes */
#define BIT_IS_CLEAR(REG,BIT_NUM) (!(REG & (1<<BIT_NUM)))

#endif /* LIB_COMMON_MACROS_H_ */
