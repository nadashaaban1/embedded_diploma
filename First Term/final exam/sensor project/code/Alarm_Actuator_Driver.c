#include "Alarm_Actuator_Driver.h"
#include "driver.h"

int alarmTimer=60;

state_define(alarm_off)
{
    //state name
    alarm_state_id=alarm_off;
    //state action
    Set_Alarm_actuator(1);
    AA_pState=state_(alarm_off);

}

state_define(alarm_on)
{
    //state name
    alarm_state_id=alarm_on;
    //state action
    Set_Alarm_actuator(0);
    AA_pState=state_(alarm_waiting);


}

state_define(alarm_waiting)
{
    //state name
    alarm_state_id=alarm_waiting;
    //state action
    Delay(alarmTimer);
    AA_pState=state_(alarm_off);
    
}
