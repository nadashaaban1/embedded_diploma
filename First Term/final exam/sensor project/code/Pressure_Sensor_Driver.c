#include "Pressure_Sensor_Driver.h"
#include "driver.h"
#include "stdlib.h"
int sensorTimer=10;
int pVal=0;
int threshold=20;

state_define(sensor_waiting)
{
    //state name
    sensor_state_id=sensor_waiting;
    //state action
    Delay(sensorTimer);
    PS_pState=state_(sensor_reading);

}

state_define(sensor_reading)
{
    //state name
    sensor_state_id=sensor_reading;
    //state action
    pVal=getPressureVal();
    sendPressureVal(pVal);
    PS_pState=state_(sensor_waiting);
}
