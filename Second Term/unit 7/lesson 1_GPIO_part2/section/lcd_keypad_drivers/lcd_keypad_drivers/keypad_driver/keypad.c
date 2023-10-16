/*
 * keypad.c
 *
 * Created: 9/21/2023 1:43:38 AM
 *  Author: Nada
 */ 

#include "keypad.h"

int keypad_rows[]={R0,R1,R2,R3};
int keypad_cols[]={C0,C1,C2,C3};

void KEYPAD_INIT()
{
	dataDIR_KEYPAD_PORT &= ~((1<<R0) | (1<<R1) | (1<<R2) | (1<<R3)); //making the rows as outputs
	dataDIR_KEYPAD_PORT |= ((1<<C0) | (1<<C1) | (1<<C2) | (1<<C3)); //making the columns as inputs
	KEYPAD_PORT = 0xFF;
}

char KEYPAD_GET_CHAR()
{
	int i,j;
	for(i=0; i<4; i++)
	{
		KEYPAD_PORT |= ((1<<keypad_cols[0]) | (1<<keypad_cols[1]) | (1<<keypad_cols[2]) | (1<<keypad_cols[3]));
		KEYPAD_PORT &= ~(1<<keypad_cols[i]);
		for(j=0; j<4; j++)
		{
			if(!(KEYPAD_PIN & (1<<keypad_rows[j])))
			{
				while(!(KEYPAD_PIN & (1<<keypad_rows[j])));
				switch(i)
				{
					case(0):
					{
						if(j==0) return '7';
						else if(j==1) return '4';
						else if(j==2) return '1';
						else if(j==3) return '?';
						break;
					}
					case(1):
					{
						if(j==0) return '8';
						else if(j==1) return '5';
						else if(j==2) return '2';
						else if(j==3) return '0';
						break;
					}
					case(2):
					{
						if(j==0) return '9';
						else if(j==1) return '6';
						else if(j==2) return '3';
						else if(j==3) return '=';
						break;
					}
					case(3):
					{
						if(j==0) return '/';
						else if(j==1) return '*';
						else if(j==2) return '-';
						else if(j==3) return '+';
						break;
					}
				}
			}
		}
	}
	return 'N';
}

float KEYPAD_CALC(int x, int y, char op)
{
	float val=0;
	switch(op)
	{
		case '+':
			val= x+y;	
			break;
		case '-':
			val= x-y;
			break;
		case '*':
			val= x*y;
			break;
		case '/':
			if(y != 0)
				val= (float)x/(float)y;
			break;
		case '$':
			break;
		default:
			return 0;
	}	
	return val;
}