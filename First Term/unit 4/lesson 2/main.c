#include "CA.h"
#include "CA.c"

void setup()
{
    //motor init
    //SoC modules init
    CA_state=state_(CA_waiting);
}

int main()
{
volatile int i;
setup();
while(1)
{
    CA_state();
    for(i=0;i<1000;i++);
}

return 0;
}