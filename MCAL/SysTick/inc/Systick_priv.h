/*
 * Systick_prov.h
 *
 *  Created on: Sep 6, 2024
 *      Author: LENOVO
 */

#ifndef SYSTICK_PRIV_H
#define SYSTICK_PRIV_H

#define AHB_FREQ		16000000UL
#define ONE_MHZ			1000000UL
#define CLKSOURCE_SHIFT		2
#define CLKSOURCE_MASK		1

#define ENABLE_MASK			1
#define ENABLE_PIN_ACCESS	0

#define FLAG_PIN_ACCESS		16
#define FLAG_MASK			1

#define MS_TO_US			1000

#define SYSTICK_MAX_COUNT	16777216

#endif /* SYSTICK_PRIV_H_ */
