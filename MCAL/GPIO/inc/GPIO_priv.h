/*
 * GPIO_priv.h
 *
 *  Created on: Sep 6, 2024
 *      Author: LENOVO
 */

#ifndef GPIO_PRIV_H
#define GPIO_PRIV_H

#define MODER_MASK			0b11
#define MODER_MUL			2

#define OTYPER_MASK			0b1

#define OSPEEDR_MASK		0b11
#define OSPEEDR_MUL			2

#define PUPDR_MASK			0b11
#define PUPDR_MUL			2

#define AFR_PIN_SHIFTING	8
#define AFR_MASK			0b1111
#define AFR_MUL				4

#define BSRR_MASK			1
#define BSRR_SHIFT			16

#define ODR_MASK			1
#define IDR_MASK			1


#endif /* GPIO_PRIV_H_ */
