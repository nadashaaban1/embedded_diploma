#include "Alarm_Monitor.h"
#include "Alarm_Actuator_Driver.h"
#include "driver.h"

int monitorTimer=10;

state_define(monitor_off)
{
    //state name 
    monitor_state_id=monitor_off;
    //state action
    ST_alarm_off();
    AM_pState=state_(monitor_off);

}

state_define(monitor_on)
{
    //state name
    monitor_state_id=monitor_on;
    //state action
    ST_alarm_on();
    AM_pState=state_(monitor_waiting);
    

}

state_define(monitor_waiting)
{
    //state name
    monitor_state_id=monitor_waiting;
    //state action
    Delay(monitorTimer);
    AM_pState=state_(monitor_off);

}
