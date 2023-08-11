#include <stdint.h>
extern int main(void);

void default_handler()
{
	reset_handler();
}

void reset_handler();
void NMI_handler() __attribute__((weak, alias ("default_handler")));
void HFault_handler() __attribute__((weak, alias ("default_handler")));

extern unsigned int stack_top;

uint32_t vectors[] __attribute__((section(".vectors"))) ={
	(uint32_t) &stack_top,
	(uint32_t) &reset_handler,
	(uint32_t) &NMI_handler,
	(uint32_t) &HFault_handler

};
extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void reset_handler()
{
	// copying data section from flash to ram
	unsigned int dataSize= (unsigned char*) &_E_data - (unsigned char*) &_S_data;
	unsigned char* pSrc= (unsigned char*) &_E_text;
	unsigned char* pDst= (unsigned char*) &_S_data;
	int i;
	for(i=0; i<dataSize; i++)
	{
		*((unsigned char*)pDst++) = *((unsigned char*)pSrc++);
	}

	// initialize .bss section with zeros in SRAM
	unsigned int bssSize= (unsigned char*) &_E_bss - (unsigned char*) &_S_bss;
	pDst= (unsigned char*) &_S_bss;
		for(i=0; i<bssSize; i++)
	{
		*((unsigned char*)pDst++) = (unsigned char) 0;
	}
	//done

	main();
}

