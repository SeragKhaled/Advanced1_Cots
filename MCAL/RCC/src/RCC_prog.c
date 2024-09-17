#include <stdint.h>
#include "StmF401CCU6.h"
#include "ErrType.h"

#include "RCC_priv.h"
#include "RCC_interface.h"



uint8_t RCC_SetClkSts(ClkType enuType_Cpy, Status enuSts_Cpy)
{
	uint8_t Local_u8ErrState = OK;
	switch(enuType_Cpy)
	{
	case HSI:
		if(enuSts_Cpy == ON)
		{
			RCC->CR |= (CR_HSI_MASK << HSI_ON);
			while(!((RCC->CR >> HSI_RDY) & 0x01));
		}
		else if(enuSts_Cpy == OFF)
		{
			RCC->CR &= ~(CR_HSI_MASK << HSI_ON);
		}
		else
		{
			Local_u8ErrState = NOK;
		}
		break;
	case HSE:
		if(enuSts_Cpy == ON)
		{
			RCC->CR |= (CR_HSE_MASK << HSE_ON);
			while(!((RCC->CR >> HSE_RDY) & 0x01));
		}
		else if(enuSts_Cpy == OFF)
		{
			RCC->CR &= ~(CR_HSE_MASK << HSE_ON);
		}
		else
		{
			Local_u8ErrState = NOK;
		}
		break;
	case PLL:
		if(enuSts_Cpy == ON)
		{
			RCC->CR |= (CR_PLL_MASK << PLL_ON);
			while(!((RCC->CR >> PLL_RDY) & 0x01));
		}
		else if(enuSts_Cpy == OFF)
		{
			RCC->CR &= ~(CR_PLL_MASK << PLL_ON);
		}
		else
		{
			Local_u8ErrState = NOK;
		}
		break;
	default:
		Local_u8ErrState = NOK;
		break;
	}

	return Local_u8ErrState;
}
uint8_t RCC_SetSysClk(ClkType enuType_Cpy)
{

}
uint8_t RCC_HSEConfig(HSEConfig enuConfig_CPy)
{

}
uint8_t RCC_PLLConfig(PLLMUL enuMul_Cpy, ClkType enuType_Cpy)
{

}
uint8_t RCC_AHB1Enable(AHB1Peripheral_t Peripheral)
{
	uint8_t Local_u8ErrState = OK;
	if(Peripheral < LAST_AHB1_PERIPHERAL && Peripheral >= GPIO_PORTA)
	{
		RCC->AHB1ENR |= (ENABLE << Peripheral);
	}
	else
	{
		Local_u8ErrState = NOK;
	}

	return Local_u8ErrState;
}
uint8_t RCC_AHBDisable()
{

}
uint8_t RCC_APB1Enable()
{

}
uint8_t RCC_APB1Disable()
{

}
uint8_t RCC_APB2Enable()
{

}
uint8_t RCC_APB2Disable()
{

}
