#include <stdio.h>

int main()
{
	int a, sum=0;
	printf("Enter an integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&a);
	for(int i=1; i<=a; i++)
	{
		sum+=i;
	}
	printf("Sum = %d",sum);
}
