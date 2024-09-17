/*
 * NVIC.c
 *
 *  Created on: Sep 10, 2024
 *      Author: LENOVO
 */


#include <stdint.h>
#include "StmF401CCU6.h"
#include "ErrType.h"

#include "NVIC_priv.h"
#include "NVIC_interface.h"



uint8_t NVIC_u8Enable(IRQ_t IRQNum)
{
	uint8_t Local_u8ErrState = OK;
	uint8_t Local_u8RegNum = IRQNum/NVIC_REG_SIZE;
	uint8_t Local_u8PinNum = IRQNum%NVIC_REG_SIZE;

	if(IRQNum < LAST_ELEMENT && IRQNum > FIRST_ELEMENT)
	{
		NVIC->ISER[Local_u8RegNum] = PIN_MASK << Local_u8PinNum;
	}
	else
	{
		Local_u8ErrState = NOK;
	}


	return Local_u8ErrState;
}

uint8_t NVIC_u8Disable(IRQ_t IRQNum)
{
	uint8_t Local_u8ErrState = OK;
	uint8_t Local_u8RegNum = IRQNum/NVIC_REG_SIZE;
	uint8_t Local_u8PinNum = IRQNum%NVIC_REG_SIZE;

	if(IRQNum < LAST_ELEMENT && IRQNum > FIRST_ELEMENT)
	{
		NVIC->ICER[Local_u8RegNum] = PIN_MASK << Local_u8PinNum;
	}
	else
	{
		Local_u8ErrState = NOK;
	}


	return Local_u8ErrState;
}

uint8_t NVIC_u8SetPendingFlag(IRQ_t IRQNum)
{
	uint8_t Local_u8ErrState = OK;
	uint8_t Local_u8RegNum = IRQNum/NVIC_REG_SIZE;
	uint8_t Local_u8PinNum = IRQNum%NVIC_REG_SIZE;

	if(IRQNum < LAST_ELEMENT && IRQNum > FIRST_ELEMENT)
	{
		NVIC->ISPR[Local_u8RegNum] = PIN_MASK << Local_u8PinNum;
	}
	else
	{
		Local_u8ErrState = NOK;
	}


	return Local_u8ErrState;
}

uint8_t NVIC_u8ClearPendingFlag(IRQ_t IRQNum)
{
	uint8_t Local_u8ErrState = OK;
	uint8_t Local_u8RegNum = IRQNum/NVIC_REG_SIZE;
	uint8_t Local_u8PinNum = IRQNum%NVIC_REG_SIZE;

	if(IRQNum < LAST_ELEMENT && IRQNum > FIRST_ELEMENT)
	{
		NVIC->ICPR[Local_u8RegNum] = PIN_MASK << Local_u8PinNum;
	}
	else
	{
		Local_u8ErrState = NOK;
	}


	return Local_u8ErrState;
}

uint8_t NVIC_GetActiveFlag(IRQ_t IRQNum, uint8_t* Val)
{
	uint8_t Local_u8ErrState = OK;
	uint8_t Local_u8RegNum = IRQNum/NVIC_REG_SIZE;
	uint8_t Local_u8PinNum = IRQNum%NVIC_REG_SIZE;
	if(Val != NULL)
	{
		if(IRQNum < LAST_ELEMENT && IRQNum > FIRST_ELEMENT)
		{
			*Val = PIN_MASK & NVIC->IABR[Local_u8RegNum] >> Local_u8PinNum;
		}
		else
		{
			Local_u8ErrState = NOK;
		}

	}
	else
	{
		Local_u8ErrState = NULL_PTR_ERR;
	}
	return Local_u8ErrState;
}

uint8_t NVIC_SetPriority(IRQ_t IRQNum, uint8_t Priority)
{
	uint8_t Local_u8ErrState = OK;


	if(Priority <= MIN_PRIORITY && Priority >= MAX_PRIORITY)
	{
		if(IRQNum > FIRST_ELEMENT && IRQNum < LAST_ELEMENT)
		{
			uint8_t Local_u8BitShift = (IRQNum % PRI_MOD)*PRI_MUL;
			NVIC->IPR[IRQNum] = Priority << Local_u8BitShift;
		}
		else
		{
			Local_u8ErrState = NOK;
		}
	}
	else
	{
		Local_u8ErrState = NOK;
	}


	return Local_u8ErrState;
}

