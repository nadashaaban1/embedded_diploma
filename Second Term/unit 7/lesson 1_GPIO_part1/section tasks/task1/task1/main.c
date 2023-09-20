/*
 * task1.c
 *
 * Created: 9/20/2023 8:20:55 PM
 * Author : Nada
 */ 

#include "MemoryMap.h"
#include "Utlis.h"

void GPIO_init()
{
	DDRA=0b11111111;

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
	
	while(1)
	{
		for(int i=7;i>=0;i--)
		{
			set_bit(PORTA,i);
			my_delay(20);
			
		}
		for(int i=0;i<8;i++)
		{
			reset_bit(PORTA,i);
			my_delay(20);
					
		}

	}
}



