#include <stdint.h>
extern int main(void);

void reset_handler();
void default_handler()
{
	reset_handler();
}

void NMI_handler() __attribute__((weak, alias ("default_handler")));
void HFault_handler() __attribute__((weak, alias ("default_handler")));

static unsigned long stack_top[256];

void (*const g_p_fn_vect[])() __attribute__((section(".vectors"))) ={
	(void (*)()) ((unsigned long)stack_top + sizeof(stack_top)),
	             &reset_handler,
	             &NMI_handler,
	             &HFault_handler
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

