#include <stdio.h>
int calcOnes(int num);
int main()
{
    int num;
    printf("Enter a number: ");
    fflush(stdin); fflush(stdout);
    scanf("%d",&num);
    printf("input:%d",num);
    printf("\noutput:%d",calcOnes(num));
return 0;
}
int calcOnes(int num)
{
    int bits=0,ones=0;
    while(num)
    {
        bits++;
        if(num&1)
        ones++;
        num=num>>1;
    }

return ones;
}