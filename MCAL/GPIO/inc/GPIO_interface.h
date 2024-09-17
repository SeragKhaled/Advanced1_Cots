/*
 * GPIO_interface.h
 *
 *  Created on: Sep 6, 2024
 *      Author: LENOVO
 */

#ifndef GPIO_INTERFACE_H
#define GPIO_INTERFACE_H



typedef enum
{
    PORTA = 0,
    PORTB,
    PORTC,
    PORTD,
    PORTE,
    PORTF,
    PORTG,
	PORTH = 7
}Port_t;

typedef enum
{
    PIN0 = 0 ,
    PIN1 ,
    PIN2 ,
    PIN3 ,
    PIN4 ,
    PIN5 ,
    PIN6 ,
    PIN7 ,
    PIN8 ,
    PIN9 ,
    PIN10 ,
    PIN11 ,
    PIN12 ,
    PIN13 ,
    PIN14 ,
    PIN15
}Pin_t;

typedef enum
{
	INPUT = 0,
	OUTPUT,
	ALTERNATE_FUNCTION,
	ANALOG
}Mode_t;

typedef enum
{
	PUSH_PULL = 0,
	OPEN_DRAIN
}OutputMode_t;

typedef enum
{
	LOW_SPEED = 0,
	MEDIUM_SPEED,
	HIGH_SPEED,
	VERY_HIGH_SPEED
}OutputSpeed_t;

typedef enum
{
	NO_PULLUP_PULLDOWN = 0,
	PULL_UP,
	PULL_DOWN
}PullConfig_t;

typedef enum
{
	AF0 = 0,
	AF1,
	AF2,
	AF3,
	AF4,
	AF5,
	AF6,
	AF7,
	AF8,
	AF9,
	AF10,
	AF11,
	AF12,
	AF13,
	AF14,
	AF15
}AlternateFunction_t;



typedef struct
{
	Port_t				Port;
	Pin_t				PinNum;
	Mode_t				Mode;
	OutputMode_t 		Output_Mode;
	OutputSpeed_t		Output_Speed;
	PullConfig_t		Pull_Config;
	AlternateFunction_t Alternate_Function;
}GPIO_PinConfig_t;

typedef enum
{
	PIN_LOW = 0,
	PIN_HIGH
}PinVal_t;


uint8_t GPIO_u8PinInit(const GPIO_PinConfig_t* PinConfig);
uint8_t GPIO_u8SetPinValue(Port_t Port, Pin_t PinNum, PinVal_t PinVal);
uint8_t GPIO_u8TogglePinValue(Port_t Port, Pin_t PinNum);
uint8_t GPIO_u8ReadPinValue(Port_t Port, Pin_t PinNum, PinVal_t* PinVal);








#endif /* GPIO_INTERFACE_H_ */
