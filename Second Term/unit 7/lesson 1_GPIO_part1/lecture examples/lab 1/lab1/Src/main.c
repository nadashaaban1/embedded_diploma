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


//RCC
#define RCC_BASE   0x40021000
#define RCC_APB2ENR *((volatile uint32_t *)(RCC_BASE + 0x18))

//GPIOA
#define GPIOA_BASE  0x40010800
#define GPIOA_CRH    *((volatile uint32_t *)(GPIOA_BASE + 0x4))
#define GPIOA_ODR    *((volatile uint32_t *)(GPIOA_BASE + 0x0C))
#define GPIOA_CRL    *((volatile uint32_t *)(GPIOA_BASE + 0x00))
#define GPIOA_IDR    *((volatile uint32_t *)(GPIOA_BASE + 0x08))

//GPIOB
#define GPIOB_BASE  0x40010C00
#define GPIOB_CRH    *((volatile uint32_t *)(GPIOB_BASE + 0x4))
#define GPIOB_ODR    *((volatile uint32_t *)(GPIOB_BASE + 0x0C))
#define GPIOB_CRL    *((volatile uint32_t *)(GPIOB_BASE + 0x00))
#define GPIOB_IDR    *((volatile uint32_t *)(GPIOB_BASE + 0x08))


void clock_init()
{
	//enable GPIOA clock
	RCC_APB2ENR  |= (1<<2);
	//enable GPIOB clock
	RCC_APB2ENR  |= (1<<3);
}

void GPIO_init()
{
	GPIOA_CRH=0;
	GPIOA_CRL=0;
	GPIOA_ODR=0;
	GPIOB_CRH=0;
	GPIOB_CRL=0;
	GPIOB_ODR=0;


	//PORTA1 input floating
	GPIOA_CRL &= ~(0b11<<4);
	GPIOA_CRL |= (0b01<<6);

	//PORTB1 output push pull
	GPIOB_CRL &= ~(0b11<<6);
	GPIOB_CRL |= (0b01<<4);

	//PORTA13 input floating
	GPIOA_CRH &= ~(0b11<<20);
	GPIOA_CRH |= (0b01<<22);

	//PORTB13 output push pull
	GPIOB_CRH |= (0b01<<20);
	GPIOB_CRH &= ~(0b11<<22);

}

void my_wait(int x)
{
	unsigned int i;
	for(i=0;i<x;i++);
}

int main(void)
{
	clock_init();
	GPIO_init();


	while(1)
	{
		//PORTA1 (pull up)
		if(((GPIOA_IDR & (1<<1)) >> 1) == 0) //single press
		{
			GPIOB_ODR ^= 1<<1;
			while(((GPIOA_IDR & (1<<1)) >> 1) == 0); //single press
		}

		//PORTA13 (pull down)
		if(((GPIOA_IDR & (1<<13)) >> 13) == 1)
		{
			GPIOB_ODR ^= 1<<13;

		}

		my_wait(500);
	}
	return 0;
}


