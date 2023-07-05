#include <stdio.h>
int sum(int start,int end);
int main()
{
    int start,end;
    printf("Enter two numbers(intervals): ");
    fflush(stdin); fflush(stdout);
    scanf("%d %d",&start,&end);
    printf("sum between %d and %d is %d",start,end,sum(start,end));
   
return 0;
}
int sum(int start,int end)
{
    int val=0;
    if(start>end) return val;
    val+=start+sum(start+1,end);
}