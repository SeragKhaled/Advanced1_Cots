/*
 * SCB_interface.h
 *
 *  Created on: Sep 12, 2024
 *      Author: LENOVO
 */

#ifndef SCB_INTERFACE_H
#define SCB_INTERFACE_H

typedef enum
{
	NO_SUBPRIORITY_BIT = 0b011,
	ONE_SUBPRIORITY_BIT,
	TWO_SUBPRIORITY_BITS,
	THREE_SUBPRIORITY_BITS,
	FOUR_SUBPRIORITY_BITS
}PRIGROUP_t;

typedef enum
{
	MEM_MANAGE = 4,
	BUS_FAULT,
	USAGE_FAULT,
	SVCALL = 11,
	PENDSV = 14,
	SYSTICK_EXCEPTION

}Fault_t;

uint8_t SCB_u8SetGroupPriority(PRIGROUP_t   PriorityGroupBits);
uint8_t SCV_u8SetFaultPriority(Fault_t FaultID);

#endif /* SCB_INTERFACE_H_ */
