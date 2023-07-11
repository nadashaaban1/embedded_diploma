#include <stdio.h>
int checkBit(int num)
{
    if((num & (1<<3))==0)
        return 0;
    else
    return 1;
    
}
int main()
{
    int num;
    scanf("%d",&num);
   printf("%d",checkBit(num)); 

}
