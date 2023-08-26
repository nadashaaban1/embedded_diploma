#include "FIFO.h"
#include "FIFO.c"

int main()
{
    sFIFO_buff_t UART_FIFO;
    data_type i, item, size=5;
    data_type buffer1[size];
    
    FIFO_init(&UART_FIFO,buffer1,size);

    for(i=0; i<size; i++)
    {
        if(FIFO_add(&UART_FIFO,i)==FIFO_no_error)
            printf("Add %d to UART_FIFO\n",i);

        else
            printf("Error! Can't add %d to UART_FIFO\n",i);
    }

    FIFO_print(&UART_FIFO);

     for(i=0; i<2; i++)
    {
        if(FIFO_get(&UART_FIFO,item)==FIFO_no_error)
            printf("Get %d from UART_FIFO\n",i);

        else
            printf("Error! Can't get %d from UART_FIFO\n",i);
    }

    FIFO_print(&UART_FIFO);

return 0;
}