#include "FIFO.h"

E_buff_status_t FIFO_init(sFIFO_buff_t* FIFO_buff,data_type* buff,data_type buff_length)
{
    //null check
    if(!buff)
    return FIFO_null;

    FIFO_buff->base = buff;
    FIFO_buff->head = buff;
    FIFO_buff->tail = buff;
    FIFO_buff->count = 0;
    FIFO_buff->length = buff_length;
}

E_buff_status_t FIFO_add(sFIFO_buff_t* FIFO_buff, data_type item)
{
    if(!FIFO_buff || !FIFO_buff->head || !FIFO_buff->base || !FIFO_buff->tail)
        return FIFO_null;   

    if(FIFO_buff->count == FIFO_buff->length)
        return FIFO_full;

    *(FIFO_buff->head)= item;
    if((FIFO_buff->head == FIFO_buff->base + FIFO_buff-> length) && (FIFO_buff->count < FIFO_buff->length))
        FIFO_buff->head = FIFO_buff->base;
    else
        FIFO_buff->head++;
    FIFO_buff->count++;
    return FIFO_no_error;

}

E_buff_status_t FIFO_get(sFIFO_buff_t* FIFO_buff, data_type item)
{
    if(!FIFO_buff || !FIFO_buff->head || !FIFO_buff->base || !FIFO_buff->tail)
        return FIFO_null; 

    if(!FIFO_buff->count)
        return FIFO_empty; 

    
    item=*(FIFO_buff->tail);
    FIFO_buff->tail++;
    FIFO_buff->count--;
    return FIFO_no_error;

}
E_buff_status_t FIFO_status(sFIFO_buff_t* FIFO_buff)
{
    if(!FIFO_buff->base || !FIFO_buff->head || !FIFO_buff->tail)
        return FIFO_null;

    if(FIFO_buff->count == FIFO_buff->length)
        return FIFO_full;

    return FIFO_no_error;

}

void FIFO_print(sFIFO_buff_t* FIFO_buff)
{
    data_type* temp;
    int i;

    if(FIFO_buff->count == 0)
    {
        printf("FIFO is empty\n");
    }
    
    temp=FIFO_buff->tail;

    printf("\n=====FIFO_print=====\n");
    for(i=0; i<FIFO_buff->count; i++)
    {
        printf("%d\n",*temp);
        temp++;
    }
    printf("\n==========\n");
}