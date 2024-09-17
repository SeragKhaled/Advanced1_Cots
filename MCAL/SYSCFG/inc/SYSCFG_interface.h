/*
 * SYSCFG_interface.h
 *
 *  Created on: Sep 14, 2024
 *      Author: LENOVO
 */

#ifndef SYSCFG_INTERFACE_H
#define SYSCFG_INTERFACE_H


typedef enum
{
	EXTI_0,
	EXTI_1,
	EXTI_2,
	EXTI_3,
	EXTI_4,
	EXTI_5,
	EXTI_6,
	EXTI_7,
	EXTI_8,
	EXTI_9,
	EXTI_10,
	EXTI_11,
	EXTI_12,
	EXTI_13,
	EXTI_14,
	EXTI_15,
}Line_t;

typedef enum
{
	SYSPORTA,
	SYSPORTB,
	SYSPORTC,
	SYSPORTD,
	SYSPORTE,
	SYSPORTF,
	SYSPORTG,
	SYSPORTH
}SYSCFG_Port_t;

uint8_t SYSCFG_u8SetEXTIPort(Line_t Line, SYSCFG_Port_t Port);




#endif /* SYSCFG_INTERFACE_H_ */
