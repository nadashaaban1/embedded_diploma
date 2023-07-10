#include <stdio.h>

int main()
{
	int a, factorial=1;
	printf("Enter an integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&a);
	if(a==0)
	{
		printf("Factorial = 1");
	}
	else if(a<0)
	{
		printf("Error!! Factorial of negative number doesn't exist");
	}
	else
	{
		for(int i=1; i<=a; i++)
			factorial*=i;
		printf("Factorial = %d",factorial);
	}
}
