#ifndef PRESSURE_SENSOR_DRIVER_H_
#define PRESSURE_SENSOR_DRIVER_H_

#include "state.h"

void sendPressureVal(int pVal);

enum {
    sensor_waiting,
    sensor_reading

}sensor_state_id;

state_define(sensor_waiting);
state_define(sensor_reading);

extern void (*PS_pState)();
int generateRandom(int l, int r, int count);



#endif