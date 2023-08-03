/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Auto-generated by STM32CubeIDE
 * @brief          : Main program body
 ******************************************************************************
 * @attention
 *
 * <h2><center>&copy; Copyright (c) 2023 STMicroelectronics.
 * All rights reserved.</center></h2>
 *
 * This software component is licensed by ST under BSD 3-Clause license,
 * the "License"; You may not use this file except in compliance with the
 * License. You may obtain a copy of the License at:
 *                        opensource.org/licenses/BSD-3-Clause
 *
 ******************************************************************************
 */

#include <stdint.h>
#include <Platform_Types.h>

#define RCC_BASE   0x40021000
#define PortA_BASE 0x40010800

#define RCC_APB2ENR *((volatile uint32_t *)(RCC_BASE + 0x18))
#define GPIO_CRH    *((volatile uint32_t *)(PortA_BASE + 0x4))
#define GPIO_ODR    *((volatile uint32_t *)(PortA_BASE + 0x0c))

int main(void)
{
	RCC_APB2ENR  |= 1<<2;
	GPIO_CRH     &= 0xff0fffff; // reset imp bits 20-23 and maintaining the rest (calibration)
	GPIO_CRH     |= 0x00200000;
	while(1)
	{
		GPIO_ODR |= 1<<13; // set bit 13
		for(int i=0;i<5000;i++);
		GPIO_ODR &= ~(1<<13); // reset bit 13
		for(int i=0;i<5000;i++);
	}
	return 0;
}
