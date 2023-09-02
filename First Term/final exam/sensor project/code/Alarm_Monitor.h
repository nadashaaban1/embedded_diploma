#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_
#include "state.h"

enum {
    monitor_off,
    monitor_on,
    monitor_waiting

}monitor_state_id;

state_define(monitor_off);
state_define(monitor_on);
state_define(monitor_waiting);


extern void (*AM_pState)();



#endif