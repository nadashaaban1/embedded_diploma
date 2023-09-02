#include "stdint.h"

void reset_handler();
void default_handler()
{
	reset_handler();
}

void NMI_handler() __attribute__((weak, alias ("default_handler")));
void HFault_handler() __attribute__((weak, alias ("default_handler")));

extern unsigned int stack_top;
extern int main();

uint32_t vectors[] __attribute__((section(".vectors")))= {
  (uint32_t)  &stack_top,
  (uint32_t)  &reset_handler,
  (uint32_t)  &NMI_handler,
  (uint32_t)  &HFault_handler
};

extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void reset_handler()
{
    //copying data from flash to ram
    uint32_t dataSize = (unsigned char*)&_E_data - (unsigned char*)&_S_data;
    unsigned char* pSrc= (unsigned char*) &_E_text;
	unsigned char* pDst= (unsigned char*) &_S_data;
	int i;
    for(i=0; i<dataSize; i++)
    {
        *(pDst)=*(pSrc);
        pDst++; pSrc++;
    }

    //initializing bss section in ram =0
	unsigned int bssSize= (unsigned char*) &_E_bss - (unsigned char*) &_S_bss;
    for(i=0; i<dataSize; i++)
    {
        *(pDst)=(unsigned char)0;
        pDst++; 
    }

    //calling main function
    main();
}