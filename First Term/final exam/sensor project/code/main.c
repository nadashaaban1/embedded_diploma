#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "Pressure_Sensor_Driver.h"
#include "Alarm_Actuator_Driver.h"
#include "Alarm_Monitor.h"


extern int threshold;


void (*PS_pState)() = state_(sensor_waiting);
void (*AM_pState)() = state_(monitor_off);
void (*AA_pState)() = state_(alarm_off);


int main (){
	GPIO_INITIALIZATION();
	Set_Alarm_actuator(1);

	while (1)
	{
		//AM_pState();
		//AA_pState();
		PS_pState();
		AM_pState();
		AA_pState();

	}


return 0;
}

void sendPressureVal(int value)
{
	if(value > threshold)
		AM_pState=state_(monitor_on);
		
	else
		AM_pState=state_(monitor_off);
		
}
