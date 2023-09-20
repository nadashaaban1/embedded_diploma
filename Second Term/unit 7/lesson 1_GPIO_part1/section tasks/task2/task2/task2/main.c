/*
 * task2.c
 *
 * Created: 9/20/2023 9:31:43 PM
 * Author : Nada
 */ 

#include "MemoryMap.h"
#include "Utlis.h"


void GPIO_init()
{
	DDRA=0b11111111;
	PORTA=0;
	reset_bit(DDRC,0);
	set_bit(PORTC,0);

}

void my_delay(int x)
{
	int i,j;
	for (i = 0; i < x; i++)
	{
		for(j = 0; j < 1000; j++);
	}
	
}

int main(void)
{
	GPIO_init();
	int i=7;
	while(1)
	{
		if(read_bit(PINC,0)==0)
		{
			while(read_bit(PINC,0)==0)
				set_bit(PORTA, i);
				
			i--;
		}
		if(i == -2)
			{
				PORTA=0;
				i=7;
			}

	}
}

