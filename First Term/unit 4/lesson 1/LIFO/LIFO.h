#include <stdio.h>
#include <stdint.h>

#ifndef LIFO_H_
#define LIFO_H_

// choose data type (uint8,uint16,uint32,...)
#define data_type uint32_t

typedef struct {
   data_type*  base;
   data_type* head;
   data_type length;
   data_type count;

}sLIFO_buff_t;

typedef enum 
{
    LIFO_no_error,
    LIFO_full,
    LIFO_empty,
    LIFO_null,
}E_buff_status_t;

//LIFO APIs
E_buff_status_t LIFO_init(sLIFO_buff_t* LIFO_buff,data_type* buff,data_type buff_length);
E_buff_status_t LIFO_add(sLIFO_buff_t* LIFO_buff, data_type item);
E_buff_status_t LIFO_get(sLIFO_buff_t* LIFO_buff, data_type item);
E_buff_status_t LIFO_status(sLIFO_buff_t* LIFO_buff);
void LIFO_print(sLIFO_buff_t* LIFO_buff);



#endif