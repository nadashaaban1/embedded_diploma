#include<stdio.h>
#include<string.h>
int add(char num[])
{

    int val=0;
    for(int i=0;i<strlen(num);i++)
    {
      val+=num[i]-'0';
    }
    return val;
}
int main()
{
    char num[100];
    printf("Enter a number: ");
    fflush(stdin); fflush(stdout);
    scanf("%s",&num);
   // printf("input:%d ",num);
   printf("output:%d",add(num));
    return 0;
}