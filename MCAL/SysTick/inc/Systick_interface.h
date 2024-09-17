/*
 * Systick.h
 *
 *  Created on: Sep 6, 2024
 *      Author: LENOVO
 */

#ifndef SYSTICK_INTERFACE_H
#define SYSTICK_INTERFACE_H


typedef enum
{
	AHB_8 = 0,
	AHB_1
}ClkType_t;



uint8_t SysTick_SetClkSrc(ClkType_t ClkType);
uint8_t SysTick_Delay_ms(uint32_t u32delay);
uint8_t	SysTick_Delay_us(uint32_t u32delay);



#endif /* SYSTICK_H_ */
