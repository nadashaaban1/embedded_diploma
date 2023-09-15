/*
 * main.c
 *
 * Created: 9/15/2023 10:16:55 PM
 *  Author: Nada
 */ 

#define F_CPU 8000000UL

#include "avr/interrupt.h"
#include "avr/io.h"
#include "util/delay.h"


void setup(void)
{
	//enable bit 5&6&7 in GICR to enable external interrupt pin
	GICR |= (7<<5);

	//enable bit 5&6&7 in GIFR && GICR >> ISR is called
	GIFR |= (7<<5);

	//set bit 7 in SREG for the interrupt to be enabled
	//SREG |= (1<<7);
	sei();
	
	//enable any logical change for INT0 & rising edge for INT1
	MCUCR |= (1<<0);
	MCUCR |= (3<<2);
	
	//falling edge for INT2 by default
}

int main(void)
{
	setup();
	PORTD &= ~(1<<PD5);
	PORTD &= ~(1<<PD6);
	PORTD &= ~(1<<PD7);
	DDRD |= (7<<5) ; 
	while(1)
	{
		
	}
}

ISR(INT0_vect)
{
	PORTD |= (1<<PD5);
	_delay_ms(100);
	PORTD &= ~(1<<PD5);
	
}

ISR(INT1_vect)
{
	PORTD |= (1<<PD6);
	_delay_ms(100);
	PORTD &= ~(1<<PD6);
	
}

ISR(INT2_vect)
{
	PORTD |= (1<<PD7);
	_delay_ms(100);
	PORTD &= ~(1<<PD7);
}