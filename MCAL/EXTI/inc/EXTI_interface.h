/*
 * EXTI_interface.h
 *
 *  Created on: Sep 14, 2024
 *      Author: LENOVO
 */

#ifndef EXTI_INTERFACE_H
#define EXTI_INTERFACE_H

//void EXTI_EnableInterrupt(uint8_t Line);


typedef void (*pf)(void);

typedef enum
{
	EXT0,
	EXT1,
	EXT2,
	EXT3,
	EXT4,
	EXT5,
	EXT6,
	EXT7,
	EXT8,
	EXT9,
	EXT10,
	EXT11,
	EXT12,
	EXT13,
	EXT14,
	EXT15,
	EXT16,
	EXT17,
	EXT18,
	EXT19,
	EXT20,
	EXT21,
	EXT22
}EXTI_Line_t;

typedef enum
{
	RISING_EDGE,
	FALLING_EDGE,
	RISING_AND_FALLING_EDGE
}TriggerEdge_t;

typedef enum
{
	DISABLE,
	ENABLE
}EnConfig_t;


typedef struct
{
	EXTI_Line_t Line;
	TriggerEdge_t Trigger;
	EnConfig_t	  EnableState;
	pf Callback_Function;
}EXTI_Config_t;



uint8_t EXTI_u8Init(EXTI_Config_t* Config);
uint8_t EXTI_u8EnableInt(EXTI_Line_t Line);
uint8_t EXTI_u8DisableInt(EXTI_Line_t Line);
uint8_t EXTI_u8SetTrigger(EXTI_Line_t Line, TriggerEdge_t Trigger);
uint8_t EXTI_u8ClearPendingFlag(EXTI_Line_t Line);
uint8_t EXTI_u8ReadPendingFlag(EXTI_Line_t Line, uint8_t* Val);
uint8_t EXTI_SetCallback(EXTI_Line_t Line, pf pfCallback);


#endif /* EXTI_INTERFACE_H_ */
