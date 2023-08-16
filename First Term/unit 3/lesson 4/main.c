#include <stdint.h>
#include <Platform_Types.h>

#define SYSCTL_RCGC2_R     *((volatile unsigned long*)(0x400FE108))
#define GPIO_PORTF_DATA_R  *((volatile unsigned long*)(0x400253FC))
#define GPIO_PORTF_DIR_R   *((volatile unsigned long*)(0x40025400))
#define GPIO_PORTF_DEN_R   *((volatile unsigned long*)(0x4002551C))


//unsigned char gVar[3] = {1,2,3};
//unsigned char const constVar[3] = {1,2,3};

int main(void)
{
	SYSCTL_RCGC2_R = 0x00000020;
	GPIO_PORTF_DIR_R  |= 1<<3;
	GPIO_PORTF_DEN_R  |= 1<<3;
	volatile unsigned long count;
	while(1)
	{
		GPIO_PORTF_DATA_R |= 1<<3;
		for(count=0; count<200000; count++);
		GPIO_PORTF_DATA_R &= ~(1<<3);
		for(count=0; count<200000; count++);
	}

	return 0;
}
