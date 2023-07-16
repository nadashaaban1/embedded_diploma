#include <stdio.h>

#define function(name,a) int fun_##name(int x) {return (a)*x;}
function(quadruple,4)
function(double,2)
int main()
{
    printf("quadruple(13): %d\n",fun_quadruple(13));
    printf("double(21): %d\n",fun_double(21));
    return 0;
}