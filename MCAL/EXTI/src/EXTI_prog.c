/*
 * EXTI_prog.c
 *
 *  Created on: Sep 14, 2024
 *      Author: LENOVO
 */

#include <stdint.h>
#include "StmF401CCU6.h"
#include "ErrType.h"

#include "EXTI_priv.h"
#include "EXTI_interface.h"

void (*Callbacks[23]) (void); //Array of Pointers to the callback functions


uint8_t EXTI_u8Init(EXTI_Config_t* Config)
{
	uint8_t Local_u8ErrState = OK;
	if(Config != NULL && Config->Callback_Function != NULL)
	{
		if(Config->Line <= EXT22 && Config->Line >= EXT0)
		{
			if(Config->EnableState == ENABLE || Config->EnableState == DISABLE)
			{
				EXTI->IMR &= ~(IMR_MASK << Config->Line);
				EXTI->IMR |= (Config->EnableState << Config->Line);
				if(Config->Trigger == RISING_EDGE)
				{
					EXTI->RTSR |= (TRIGGER_MASK << Config->Line);
					EXTI->FTSR &= ~(TRIGGER_MASK << Config->Line);
				}
				else if(Config->Trigger == FALLING_EDGE)
				{
					EXTI->FTSR |= (TRIGGER_MASK << Config->Line);
					EXTI->RTSR &= ~(TRIGGER_MASK << Config->Line);
				}
				else if(Config->Trigger == RISING_AND_FALLING_EDGE)
				{
					EXTI->FTSR |= (TRIGGER_MASK << Config->Line);
					EXTI->RTSR |= (TRIGGER_MASK << Config->Line);
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
		}
		else
		{
			Local_u8ErrState = NOK;
		}

		EXTI_SetCallback(Config->Line, Config->Callback_Function);
	}
	else
	{
		Local_u8ErrState = NULL_PTR_ERR;
	}

	return Local_u8ErrState;
}

uint8_t EXTI_u8EnableInt(EXTI_Line_t Line)
{
	uint8_t Local_u8ErrState = OK;

	if(Line <= EXT22 && Line >= EXT0)
	{
		EXTI->IMR |= IMR_MASK << Line;
	}
	else
	{
		Local_u8ErrState = NOK;
	}

	return Local_u8ErrState;
}

uint8_t EXTI_u8DisableInt(EXTI_Line_t Line)
{
	uint8_t Local_u8ErrState = OK;

	if(Line <= EXT22 && Line >= EXT0)
	{
		EXTI->IMR &= ~(IMR_MASK << Line);
	}
	else
	{
		Local_u8ErrState = NOK;
	}

	return Local_u8ErrState;
}

uint8_t EXTI_u8SetTrigger(EXTI_Line_t Line, TriggerEdge_t Trigger)
{
	uint8_t Local_u8ErrState = OK;
	if(Line <= EXT22 && Line >= EXT0)
	{
		if(Trigger == RISING_EDGE)
		{
			EXTI->RTSR |= (TRIGGER_MASK << Line);
			EXTI->FTSR &= ~(TRIGGER_MASK << Line);
		}
		else if(Trigger == FALLING_EDGE)
		{
			EXTI->FTSR |= (TRIGGER_MASK << Line);
			EXTI->RTSR &= ~(TRIGGER_MASK << Line);
		}
		else if(Trigger == RISING_AND_FALLING_EDGE)
		{
			EXTI->FTSR |= (TRIGGER_MASK << Line);
			EXTI->RTSR |= (TRIGGER_MASK << Line);
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

uint8_t EXTI_u8ClearPendingFlag(EXTI_Line_t Line)
{
	uint8_t Local_u8ErrState = OK;

	if(Line <= EXT22 && Line >= EXT0)
	{
		EXTI->PR = PR_MASK << Line;
	}
	else
	{
		Local_u8ErrState = NOK;
	}

	return Local_u8ErrState;
}

uint8_t EXTI_u8ReadPendingFlag(EXTI_Line_t Line, uint8_t* Val)
{
	uint8_t Local_u8ErrState = OK;
	if(Val != NULL)
	{
		if(Line <= EXT22 && Line >= EXT0)
		{
			*Val = ((EXTI->PR >> Line) & PR_MASK);
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

uint8_t EXTI_SetCallback(EXTI_Line_t Line, pf pfCallback)
{
	uint8_t Local_u8ErrState =  OK;

	if(pfCallback != NULL)
	{
		if(Line <= EXT22 && Line >= EXT0 && Line != EXT19 && Line != EXT20)
		{
			Callbacks[Line] = pfCallback;
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

void EXTI0_IRQHandler(void)
{
	Callbacks[EXT0]();
	EXTI->PR = PR_MASK << EXT0;
}

void EXTI1_IRQHandler(void)
{
	Callbacks[EXT1]();
	EXTI->PR = PR_MASK << EXT1;
}

void EXTI2_IRQHandler(void)
{
	Callbacks[EXT2]();
	EXTI->PR = PR_MASK << EXT2;
}

void EXTI3_IRQHandler(void)
{
	Callbacks[EXT3]();
	EXTI->PR = PR_MASK << EXT3;
}

void EXTI4_IRQHandler(void)
{
	Callbacks[EXT4]();
	EXTI->PR = PR_MASK << EXT4;
}
void EXTI9_5_IRQHandler(void)
{

}

void EXTI15_10_IRQHandler(void)
{

}

void EXTI16_PVD_IRQHandler(void)
{
	Callbacks[EXT16]();
	EXTI->PR = PR_MASK << EXT16;
}

void EXTI17_RTC_Alarm_IRQHandler(void)
{
	Callbacks[EXT17]();
	EXTI->PR = PR_MASK << EXT17;
}

void EXTI18_OTG_FS_WKUP_IRQHandler(void)
{
	Callbacks[EXT18]();
	EXTI->PR = PR_MASK << EXT18;
}

void TAMP_STAMP_IRQHandler(void)
{
	Callbacks[EXT21]();
	EXTI->PR = PR_MASK << EXT21;
}

void EXTI22_RTC_WKUP_IRQHandler(void)
{
	Callbacks[EXT22]();
	EXTI->PR = PR_MASK << EXT22;
}





