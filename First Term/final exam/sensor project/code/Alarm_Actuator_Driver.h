#ifndef ALARM_ACTUATOR_DRIVER_H_
#define ALARM_ACTUATOR_DRIVER_H_

#include "state.h"


enum {
    alarm_off,
    alarm_on,
    alarm_waiting

}alarm_state_id;

state_define(alarm_off);
state_define(alarm_on);
state_define(alarm_waiting);

extern void (*AA_pState)();

#endif