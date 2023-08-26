#include <stdio.h>
#include <stdint.h>

#ifndef FIFO_H_
#define FIFO_H_

// choose data type (uint8,uint16,uint32,...)
#define data_type uint32_t

typedef struct {
   data_type*  base;
   data_type* head;
   data_type* tail;
   data_type length;
   data_type count;

}sFIFO_buff_t;

typedef enum 
{
    FIFO_no_error,
    FIFO_full,
    FIFO_empty,
    FIFO_null,
}E_buff_status_t;

//LIFO APIs
E_buff_status_t FIFO_init(sFIFO_buff_t* FIFO_buff,data_type* buff,data_type buff_length);
E_buff_status_t FIFO_add(sFIFO_buff_t* FIFO_buff, data_type item);
E_buff_status_t FIFO_get(sFIFO_buff_t* FIFO_buff, data_type item);
E_buff_status_t FIFO_status(sFIFO_buff_t* FIFO_buff);
void FIFO_print(sFIFO_buff_t* FIFO_buff);



#endif