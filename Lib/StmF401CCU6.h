#ifndef STMF401CCU6_H
#define STMF401CCU6_H


/***************************            Various Memories Base Addresses          *****************************/

#define FLASH_BASE_ADDRESS                  	0x08000000UL
#define SRAM_BASE_ADDRESS                   	0x20000000UL
#define ROM_BASE_ADDRESS                    	0x1FFF0000UL


/***************************            Core Peripheral Base Addresses          *****************************/

#define NVIC_BASE_ADDRESS						0xE000E100UL
#define SYSTICK_BASE_ADDRESS					0xE000E010UL
/***************************            AHB1 Peripheral Base Addresses          *****************************/

#define RCC_BASE_ADDRESS                       	0x40023800UL


#define GPIOA_BASE_ADDRESS                     	0x40020000UL
#define GPIOB_BASE_ADDRESS                     	0x40020400UL
#define GPIOC_BASE_ADDRESS                     	0x40020800UL
#define GPIOD_BASE_ADDRESS                     	0x40020C00UL
#define GPIOE_BASE_ADDRESS                     	0x40021000UL
//#define GPIOF_BASE_ADDRESS                   	0x4002UL
//#define GPIOG_BASE_ADDRESS                    0x4002UL
#define GPIOH_BASE_ADDRESS						0x40021C00UL



/***************************            AHB2 Peripheral Base Addresses          *****************************/




/***************************            APB1 Peripheral Base Addresses          *****************************/




/***************************            APB2 Peripheral Base Addresses          *****************************/


/***************************            NVIC Register Definition Structure           *****************************/

typedef struct
{
	volatile uint32_t ISER[8];
	volatile uint32_t Reserved0[24];
	volatile uint32_t ICER[8];
	volatile uint32_t Reserved1[24];
	volatile uint32_t ISPR[8];
	volatile uint32_t Reserved2[24];
	volatile uint32_t ICPR[8];
	volatile uint32_t Reserved3[24];
	volatile uint32_t IABR[8];
	volatile uint32_t Reserved4[24];
	volatile uint8_t IPR[240];
	volatile uint32_t Reserved5[644];
	volatile uint32_t STIR;
}NVIC_RegDef_t;

/***************************            SysTick Register Definition Structure           *****************************/

typedef struct
{
	volatile uint32_t CTRL;					/*SysTick Control and Status Register*/
	volatile uint32_t LOAD;					/*SysTick Reload Value Register*/
	volatile uint32_t VAL;					/*SysTick Current Value Register*/
	volatile uint32_t CALIB;				/*SysTick Calibration Value Register*/

}SysTick_RegDef_t;


/***************************            GPIO Register Definition Structure           *****************************/

typedef struct
{
	volatile uint32_t  MODER	;				/*GPIO PORT MODE REGISTER*/
	volatile uint32_t  OTYPER	;				/*GPIO PORT OUTPUT TYPE REGISTER*/
	volatile uint32_t  OSPEEDR	;				/*GPIO PORT OUTPUT SPEED REGISTER*/
	volatile uint32_t  PUPDR	;				/*GPIO PORT PULLUP/PULLDOWN REGISTER*/
	volatile uint32_t  IDR     	;            	/*GPIO PORT Input Data REGISTER*/
	volatile uint32_t  ODR     	;            	/*GPIO PORT Output Data REGISTER*/
	volatile uint32_t  BSRR    	;            	/*GPIO PORT Bit Set/Reset REGISTER*/
	volatile uint32_t  LCKR    	;            	/*GPIO PORT Configuration Lock REGISTER*/
	volatile uint32_t  AFR[2]	;				/*GPIO PORT Alternate Function High and Low Registers*/
}GPIO_RegDef_t;

/***************************            RCC Register Definition Structure           *****************************/

typedef struct											
{											
	volatile uint32_t CR;							/*RCC Clock Control Register*/
	volatile uint32_t PLLCFGR;						/*RCC PLL Configuration Register*/
	volatile uint32_t CFGR;							/*RCC Clock Configuration Register*/
	volatile uint32_t CIR;							/*RCC Clock Interrupt Register*/
	volatile uint32_t AHB1RSTR;						/*RCC AHB1 Peripheral Reset Register*/
	volatile uint32_t AHB2RSTR;						/*RCC AHB2 Peripheral Reset Register*/
	volatile uint32_t Reserved0;					/*RCC Reserved Register*/
	volatile uint32_t Reserved1;					/*RCC Reserved Register*/
	volatile uint32_t APB1RSTR;						/*RCC APB1 Peripheral Reset Register*/
	volatile uint32_t APB2RSTR;						/*RCC APB2 Peripheral Reset Register*/
	volatile uint32_t Reserved2;					/*RCC Reserved Register*/
	volatile uint32_t Reserved3;					/*RCC Reserved Register*/
	volatile uint32_t AHB1ENR;						/*RCC AHB1 Peripheral Clock Enable Register*/
	volatile uint32_t AHB2ENR;						/*RCC AHB2 Peripheral Clock Enable Register*/
	volatile uint32_t Reserved4;					/*RCC Reserved Register*/
	volatile uint32_t Reserved5;					/*RCC Reserved Register*/
	volatile uint32_t APB1ENR;						/*RCC APB1 Peripheral Clock Enable Register*/
	volatile uint32_t APB2ENR;						/*RCC APB2 Peripheral Clock Enable Register*/
	volatile uint32_t Reserved6;					/*RCC Reserved Register*/
	volatile uint32_t Reserved7;					/*RCC Reserved Register*/
	volatile uint32_t AHB1LPENR;					/*RCC AHB1 Peripheral Clock Enable In Low Power Mode Register*/
	volatile uint32_t AHB2LPENR;					/*RCC AHB2 Peripheral Clock Enable In Low Power Mode Register*/
	volatile uint32_t Reserved8;					/*RCC Reserved Register*/
	volatile uint32_t Reserved9;					/*RCC Reserved Register*/
	volatile uint32_t APB1LPENR;					/*RCC APB1 Peripheral Clock Enable In Low Power Mode Register*/
	volatile uint32_t APB2LPENR;					/*RCC APB2 Peripheral Clock Enable In Low Power Mode Register*/
	volatile uint32_t Reserved10;					/*RCC Reserved Register*/
	volatile uint32_t Reserved11;					/*RCC Reserved Register*/
	volatile uint32_t BDCR;							/*RCC Backup Domain Control Register*/
	volatile uint32_t CSR;							/*RCC Control and Status Register*/
	volatile uint32_t Reserved12;					/*RCC Reserved Register*/
	volatile uint32_t Reserved13;					/*RCC Reserved Register*/
	volatile uint32_t SSCGR;						/*RCC Spread Spectrum Clock Generation Register*/
	volatile uint32_t PLLI2SCFGR;					/*RCC PLLI2S Configuration Register*/
	volatile uint32_t Reserved14;					/*RCC Reserved Register*/
	volatile uint32_t DCKCFGR;						/*RCC Dedicated Clocks Configuration Register*/

}RCC_RegDef_t;

/***************************            NVIC Peripheral Definitions           *****************************/
#define NVIC						((NVIC_RegDef_t*) NVIC_BASE_ADDRESS)

/***************************            SysTick Peripheral Definitions           *****************************/

#define SysTick						((SysTick_RegDef_t*) SYSTICK_BASE_ADDRESS)

/***************************            GPIO Peripheral Definitions           *****************************/

#define GPIOA                    ((GPIO_RegDef_t*) GPIOA_BASE_ADDRESS)
#define GPIOB                    ((GPIO_RegDef_t*) GPIOB_BASE_ADDRESS)
#define GPIOC                    ((GPIO_RegDef_t*) GPIOC_BASE_ADDRESS)
#define GPIOD                    ((GPIO_RegDef_t*) GPIOD_BASE_ADDRESS)
#define GPIOE                    ((GPIO_RegDef_t*) GPIOE_BASE_ADDRESS)
//#define GPIOF                    ((GPIO_RegDef_t*) GPIOF_BASE_ADDRESS)
//#define GPIOG                    ((GPIO_RegDef_t*) GPIOG_BASE_ADDRESS)
#define GPIOH                    ((GPIO_RegDef_t*) GPIOH_BASE_ADDRESS)

/***************************            RCC Peripheral Definitions           *****************************/

#define RCC                      ((RCC_RegDef_t*) RCC_BASE_ADDRESS)


#endif /*Guard*/
