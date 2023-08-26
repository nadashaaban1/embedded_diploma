#include "LIFO.h"

E_buff_status_t LIFO_init(sLIFO_buff_t* LIFO_buff,data_type* buff,data_type buff_length)
{
    //null check
    if(!buff)
    return LIFO_null;

    LIFO_buff->base = buff;
    LIFO_buff->head = buff;
    LIFO_buff->count = 0;
    LIFO_buff->length = buff_length;
}

E_buff_status_t LIFO_add(sLIFO_buff_t* LIFO_buff, data_type item)
{
    if(!LIFO_buff || !LIFO_buff->head || !LIFO_buff->base)
        return LIFO_null;   

    if(LIFO_buff->count == LIFO_buff->length)
        return LIFO_full;

    *(LIFO_buff->head)= item;
    LIFO_buff->head++;
    LIFO_buff->count++;
    return LIFO_no_error;

}

E_buff_status_t LIFO_get(sLIFO_buff_t* LIFO_buff, data_type item)
{
    if(!LIFO_buff || !LIFO_buff->head || !LIFO_buff->base)
        return LIFO_null; 

    if(!LIFO_buff->count)
        return LIFO_empty; 

    LIFO_buff->head--;
    item=*(LIFO_buff->head);
    LIFO_buff->count--;
    return LIFO_no_error;

}
E_buff_status_t LIFO_status(sLIFO_buff_t* LIFO_buff)
{
    if(!LIFO_buff->base || !LIFO_buff->head)
        return LIFO_null;

    if(LIFO_buff->count == LIFO_buff->length)
        return LIFO_full;

    return LIFO_no_error;

}

void LIFO_print(sLIFO_buff_t* LIFO_buff)
{
    data_type* temp;
    int i;

    if(LIFO_buff->count == 0)
    {
        printf("LIFO is empty\n");
    }
    
    LIFO_buff->head--;
    temp=LIFO_buff->head;

    printf("\n=====LIFO_print=====\n");
    for(i=0; i<LIFO_buff->count; i++)
    {
        printf("%d",*temp);
        temp--;
    }
    printf("\n==========\n");
}