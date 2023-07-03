#include <stdio.h>
int clear(int num, int pos)
{
    return (num & ~(1<<pos));
}
int main()
{
 int num,pos;
 scanf("%d",&num);
 scanf("%d",&pos);
 printf("result = %d",clear(num,pos));

}
