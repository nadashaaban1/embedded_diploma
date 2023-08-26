#include "LIFO.h"
#include "LIFO.C"

int main()
{
    sLIFO_buff_t UART_LIFO;
    data_type i, item, size=5;
    data_type buffer1[size];
    
    LIFO_init(&UART_LIFO,buffer1,size);

    for(i=0; i<size; i++)
    {
        if(LIFO_add(&UART_LIFO,i)==LIFO_no_error)
            printf("Add %d to UART_LIFO\n",i);

        else
            printf("Error! Can't add %d to UART_LIFO\n",i);
    }

     for(i=0; i<size; i++)
    {
        if(LIFO_get(&UART_LIFO,item)==LIFO_no_error)
            printf("Get %d from UART_LIFO\n",i);

        else
            printf("Error! Can't get %d from UART_LIFO\n",i);
    }

return 0;
}