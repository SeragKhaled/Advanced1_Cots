/*
 * GPIO_prog.c
 *
 *  Created on: Sep 6, 2024
 *      Author: LENOVO
 */

#include <stdint.h>
#include "StmF401CCU6.h"
#include "ErrType.h"

#include "GPIO_priv.h"
#include "GPIO_interface.h"


GPIO_RegDef_t* GPIO[8] = {GPIOA, GPIOB, GPIOC, GPIOD, GPIOE, NULL, NULL, GPIOH};

uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t* PinConfig)
{
	uint8_t Local_u8ErrState = OK;
	if(PinConfig != NULL)
	{

		if(PinConfig->Port != PORTF && PinConfig->Port != PORTG && PinConfig->Port >= PORTA && PinConfig->Port <= PORTH)
		{
			if(PinConfig->PinNum >= PIN0 && PinConfig->PinNum <= PIN15)
			{
				GPIO[PinConfig->Port]->MODER &= ~(MODER_MASK << ((PinConfig->PinNum)*MODER_MUL));
				GPIO[PinConfig->Port]->MODER |= (PinConfig->Mode << ((PinConfig->PinNum)*MODER_MUL));

				GPIO[PinConfig->Port]->PUPDR &= ~(PUPDR_MASK << ((PinConfig->PinNum)*PUPDR_MUL));
				GPIO[PinConfig->Port]->PUPDR &= ~(PinConfig->Pull_Config << ((PinConfig->PinNum)*PUPDR_MUL));

				if(PinConfig->Mode == OUTPUT || PinConfig->Mode == ALTERNATE_FUNCTION)
				{
					GPIO[PinConfig->Port]->OTYPER &= ~(OTYPER_MASK << PinConfig->PinNum);
					GPIO[PinConfig->Port]->OTYPER |= (PinConfig->Output_Mode << PinConfig->PinNum);

					GPIO[PinConfig->Port]->OSPEEDR &= ~(OSPEEDR_MASK << (PinConfig->PinNum * OSPEEDR_MUL));
					GPIO[PinConfig->Port]->OSPEEDR |= (PinConfig->Output_Speed << (PinConfig->PinNum * OSPEEDR_MUL));

					if(PinConfig->Mode == ALTERNATE_FUNCTION)
					{
						uint8_t Local_u8RegNum = (PinConfig->PinNum) / AFR_PIN_SHIFTING;
						uint8_t Local_u8BitNum = (PinConfig->PinNum) % AFR_PIN_SHIFTING;

						GPIO[PinConfig->Port]->AFR[Local_u8RegNum] &= ~(AFR_MASK << (Local_u8BitNum * AFR_MUL));
						GPIO[PinConfig->Port]->AFR[Local_u8RegNum] |=  (PinConfig->Alternate_Function << (Local_u8BitNum * AFR_MUL));

					}
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
	}
	else
	{
		Local_u8ErrState = NULL_PTR_ERR;
	}
	return Local_u8ErrState;
}

uint8_t GPIO_u8SetPinValue(Port_t Port, Pin_t PinNum, PinVal_t PinVal)
{
	uint8_t Local_u8ErrState = OK;

	if(Port >= PORTA && Port <= PORTH && Port != PORTF && Port != PORTG)
	{
		if(PinVal == PIN_LOW)
		{
			GPIO[Port]->BSRR = (BSRR_MASK << (PinNum + BSRR_SHIFT));
		}
		else if(PinVal == PIN_HIGH)
		{
			GPIO[Port]->BSRR = (BSRR_MASK << PinNum);
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

uint8_t GPIO_u8TogglePinValue(Port_t Port, Pin_t PinNum)
{
	uint8_t Local_u8ErrState = OK;
	if(Port >= PORTA && Port <= PORTH && Port != PORTF && Port != PORTG)
	{
		GPIO[Port]->ODR ^= (ODR_MASK << PinNum);
	}
	else
	{
		Local_u8ErrState = NOK;
	}

	return Local_u8ErrState;
}

uint8_t GPIO_u8ReadPinValue(Port_t Port, Pin_t PinNum, PinVal_t* PinVal)
{
	uint8_t Local_u8ErrState = OK;
	if(PinVal != NULL)
	{
		if(Port >= PORTA && Port <= PORTH && Port != PORTF && Port != PORTG)
		{
			*PinVal = ((GPIO[Port]->IDR >> PinNum) & IDR_MASK);
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
