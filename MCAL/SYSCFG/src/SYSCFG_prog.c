/*
 * SYSCFG_prog.c
 *
 *  Created on: Sep 14, 2024
 *      Author: LENOVO
 */

#include <stdint.h>
#include "StmF401CCU6.h"
#include "ErrType.h"

#include "SYSCFG_priv.h"
#include "SYSCFG_interface.h"


uint8_t SYSCFG_u8SetEXTIPort(Line_t Line, SYSCFG_Port_t Port)
{
	uint8_t Local_u8ErrState = OK;
	if(Line <= EXTI_15 && Port <= SYSPORTH)
	{
		uint8_t Local_u8RegNum = Line / 4;
		uint8_t Local_u8BitNum = (Line % 4)*4;

		SYSCFG->EXTICR[Local_u8RegNum] &= ~(EXTI_MASK << Local_u8BitNum) ;
		SYSCFG->EXTICR[Local_u8RegNum] |= Port << Local_u8BitNum ;
	}
	else
	{
		Local_u8ErrState = NOK;
	}


	return Local_u8ErrState;
}
