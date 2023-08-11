#include <stdint.h>
#include <Platform_Types.h>
//typedef volatile unsigned int vuint32_t;

#define RCC_BASE   0x40021000
#define PortA_BASE 0x40010800

#define RCC_APB2ENR *((volatile uint32_t *)(RCC_BASE + 0x18))
#define GPIO_CRH    *((volatile uint32_t *)(PortA_BASE + 0x4))
#define GPIO_ODR    *((volatile uint32_t *)(PortA_BASE + 0x0c))

unsigned char gVar[3] = {1,2,3};
unsigned char const constVar[3] = {1,2,3};

int main(void)
{
	RCC_APB2ENR  |= 1<<2;
	GPIO_CRH     &= 0xff0fffff; // reset imp bits 20-23 and maintaining the rest (calibration)
	GPIO_CRH     |= 0x00200000;
	while(1)
	{
		GPIO_ODR |= 1<<13; // set bit 13
        int i;
		for(i=0;i<5000;i++);
		GPIO_ODR &= ~(1<<13); // reset bit 13
		for(i=0;i<5000;i++);
	}
	return 0;
}
