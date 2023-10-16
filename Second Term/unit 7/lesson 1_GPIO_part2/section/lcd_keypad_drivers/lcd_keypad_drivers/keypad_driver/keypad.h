/*
 * keypad.h
 *
 * Created: 9/21/2023 1:43:50 AM
 *  Author: Nada
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <stdlib.h>

#define KEYPAD_PORT PORTD
#define dataDIR_KEYPAD_PORT DDRD
#define KEYPAD_PIN PIND

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

void KEYPAD_INIT();
char KEYPAD_GET_CHAR();
float KEYPAD_CALC(int x,int y, char op);
 



#endif /* KEYPAD_H_ */