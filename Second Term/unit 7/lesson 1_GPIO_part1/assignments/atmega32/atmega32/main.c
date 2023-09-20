/*
 * main.c
 *
 * Created: 9/17/2023 10:36:11 PM
 *  Author: Nada
 */ 


#define set_bit(reg, bit) reg |= (1<<bit)
#define reset_bit(reg, bit) reg &= ~(1<<bit)

#define DDRD   *((volatile unsigned char *)(0x31))
#define PORTD   *((volatile unsigned char *)(0x32))

void GPIO_init()
{
	set_bit(DDRD,4);
	set_bit(DDRD,5);
	set_bit(DDRD,6);
	set_bit(DDRD,7);
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
        set_bit(PORTD,5);
        my_delay(200);
        reset_bit(PORTD,5);

        set_bit(PORTD,6);
        my_delay(200);
        reset_bit(PORTD,6);
		
        set_bit(PORTD,7);
        my_delay(200);
        reset_bit(PORTD,7);
		
        set_bit(PORTD,4);
        my_delay(200);
        reset_bit(PORTD,4);
    }
}

