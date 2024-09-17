/*
 * SCB.c
 *
 *  Created on: Sep 12, 2024
 *      Author: Serag Khaled
 */
#include <stdint.h>
#include "StmF401CCU6.h"
#include "ErrType.h"
#include "SCB_priv.h"
#include "SCB_interface.h"

uint8_t SCB_u8SetGroupPriority(PRIGROUP_t   PriorityGroupBits)
{
	uint8_t Local_u8ErrState = OK;
	if(PriorityGroupBits >= NO_SUBPRIORITY_BIT && PriorityGroupBits <= FOUR_SUBPRIORITY_BITS)
	{
		uint32_t u32AIRCR_Reg = VECTKEY_PASS << AIRCR_SHIFT;
		u32AIRCR_Reg |= PriorityGroupBits << PRIGORUP_SHIFT;
		SCB->AIRCR = u32AIRCR_Reg;
	}
	else
	{
		Local_u8ErrState = NOK;
	}

	return Local_u8ErrState;
}

uint8_t SCV_u8SetFaultPriority(Fault_t FaultID)
{
	uint8_t Local_u8ErrState = OK;

	if(FaultID >= SYSTICK_EXCEPTION && FaultID <= MEM_MANAGE)
	{
		uint8_t Local_u8RegNum = FaultID / PRI_FIELD_SIZE;
		uint8_t Local_u8BitNum = (FaultID % PRI_FIELD_SIZE) * PRI_FIELD_SIZE;

		SCB->SHPR[Local_u8RegNum] &= ~(PRI_MASK << Local_u8BitNum);
		SCB->SHPR[Local_u8RegNum] |= (FaultID << Local_u8BitNum);
	}
	else
	{
		Local_u8ErrState = NOK;
	}

	return Local_u8ErrState;
}
