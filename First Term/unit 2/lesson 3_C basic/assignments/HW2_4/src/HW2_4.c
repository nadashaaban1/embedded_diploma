#include <stdio.h>

int main()
{
	float a;
	printf("Enter a number: ");
	fflush(stdin); fflush(stdout);
	scanf("%f",&a);
	if(a>0)
	 printf("%f is positive",a);
	else if(a<0)
		printf("%f is negative",a);
	else
		printf("You entered zero");


}
