/*
 * Systick.c
 *
 *  Created on: Sep 6, 2024
 *      Author: LENOVO
 */
#include <stdint.h>
#include "StmF401CCU6.h"
#include "ErrType.h"

#include "Systick_interface.h"
#include "Systick_priv.h"

static uint8_t SysTick_AHB_DIV = 8;

uint8_t SysTick_SetClkSrc(ClkType_t ClkType)
{
	uint8_t Local_u8ErrState = OK;

	if(ClkType == AHB_1)
	{
		SysTick->CTRL |= (CLKSOURCE_MASK << CLKSOURCE_SHIFT);
		SysTick_AHB_DIV = 1;
	}
	else if(ClkType == AHB_8)
	{
		SysTick->CTRL &= ~(CLKSOURCE_MASK << CLKSOURCE_SHIFT);
		SysTick_AHB_DIV = 8;
	}
	else
	{
		Local_u8ErrState = NOK;
	}

	return Local_u8ErrState;
}
uint8_t SysTick_Delay_ms(uint32_t u32delay)
{
	uint8_t  Local_u8ErrState = OK;
	uint32_t Local_u32LoadVal = (u32delay/SysTick_AHB_DIV)*(AHB_FREQ/ONE_MHZ) * MS_TO_US;
	if(Local_u32LoadVal <= SYSTICK_MAX_COUNT)
	{
		SysTick->LOAD = Local_u32LoadVal;
		SysTick->CTRL |= (ENABLE_MASK << ENABLE_PIN_ACCESS); //Enable SysTick
		while(!((SysTick->CTRL >> FLAG_PIN_ACCESS) & FLAG_MASK));

	}
	return Local_u8ErrState;
}
uint8_t	SysTick_Delay_us(uint32_t u32delay)
{
	uint8_t  Local_u8ErrState = OK;
	uint32_t Local_u32LoadVal = (u32delay/SysTick_AHB_DIV)*(AHB_FREQ/ONE_MHZ);
	if(Local_u32LoadVal <= SYSTICK_MAX_COUNT)
	{
		SysTick->LOAD = Local_u32LoadVal;
		SysTick->CTRL |= (ENABLE_MASK << ENABLE_PIN_ACCESS); //Enable SysTick
		while(!((SysTick->CTRL >> FLAG_PIN_ACCESS) & FLAG_MASK));

	}
	return Local_u8ErrState;
}






