#include <stdio.h>
union job
{
    char name[32];
    float salary;
    int worker_no;
}u;
struct job1
{
    char name[32];
    float salary;
    int worker_no;
}s;

/*size of union is the size of the largest data type it has so, it should be = 32;
size of structure is the sum of all data types it has so, it should be = 32+4+4 = 40;*/

int main ()
{
    printf("size of union= %d",sizeof(u));
    printf("\nsize of structure= %d",sizeof(s));
    return 0;
}