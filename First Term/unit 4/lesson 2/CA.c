#include "CA.h"
#include "state.h"

int CA_speed=0;
int CA_distance=0;
int CA_threshold=50;

void (*CA_state)();

int generateRandom(int l, int r, int count)
{
	int i;
	for(i=0;i<count;i++)
	{
		int num=(rand()%(r-l+1))+ l;
		return num;
	}
}

state_define(CA_waiting)
{
    //state name
    CA_state_id=CA_waiting;
    //state action
    CA_speed=0;
    //event check
    CA_distance=generateRandom(45,55,1);
    if(CA_distance<=CA_threshold)
        CA_state=state_(CA_waiting);
    else
        CA_state=state_(CA_driving);

    printf("CA_waiting state: distance = %d , speed = %d \n",CA_distance,CA_speed);
}

state_define(CA_driving)
{
    //state name
    CA_state_id=CA_driving;
    //state action
    CA_speed=30;
    //event check
    CA_distance=generateRandom(45,55,1);
    if(CA_distance<=CA_threshold)
        CA_state=state_(CA_waiting);
    else
        CA_state=state_(CA_driving);

    printf("CA_driving state: distance = %d , speed = %d \n",CA_distance,CA_speed);
}