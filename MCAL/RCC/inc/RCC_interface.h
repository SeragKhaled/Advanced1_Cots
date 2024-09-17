#ifndef RCC_INTERFACE_H
#define RCC_INTERFACE_H

typedef enum  	{HSI, HSE, PLL}ClkType;
typedef enum 	{ON, OFF}Status;
typedef enum	{DIV_1, DIV_2}HSEConfig;

typedef enum
{
	MUL_2, MUL_3, MUL_4, MUL_5, MUL_6,
	MUL_7, MUL_8, MUL_9, MUL_10, MUL_11,
	MUL_12, MUL_13, MUL_14, MUL_15, MUL_16
}PLLMUL;

typedef enum
{
	GPIO_PORTA,
	GPIO_PORTB,
	GPIO_PORTC,
	GPIO_PORTD,
	GPIO_PORTE,
	GPIO_PORTH = 7,
	LAST_AHB1_PERIPHERAL
}AHB1Peripheral_t;

typedef enum
{
	TIM1_CLK,
	USART1_CLK = 4,
	USART6_CLK,
	ADC1_CLK = 8,
	SDIO_CLK = 11,
	SPI1_CLK,
	SPI4EN_CLK,
	SYSCFG_EN,
	LAST_APB2_PERIPHERAL
}APB2Peripheral_t;



uint8_t RCC_SetClkSts(ClkType enuType_Cpy, Status enuSts_Cpy);
uint8_t RCC_SetSysClk(ClkType enuType_Cpy);
uint8_t RCC_HSEConfig(HSEConfig enuConfig_CPy);
uint8_t RCC_PLLConfig(PLLMUL enuMul_Cpy, ClkType enuType_Cpy);
uint8_t RCC_AHB1Enable(AHB1Peripheral_t Peripheral);
uint8_t RCC_AHB1Disable(AHB1Peripheral_t Peripheral);
uint8_t RCC_APB1Enable();
uint8_t RCC_APB1Disable();
uint8_t RCC_APB2Enable(APB2Peripheral_t Peripheral);
uint8_t RCC_APB2Disable();



#endif /*Guard*/
