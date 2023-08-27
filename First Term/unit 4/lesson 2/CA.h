#ifndef CA_H_
#define CA_H_

#include "state.h"
#include "stdio.h"
#include "stdlib.h"

//define states
enum
{
    CA_waiting,
    CA_driving
}CA_state_id;

//declare state functions
state_define(CA_waiting);
state_define(CA_driving);



#endif