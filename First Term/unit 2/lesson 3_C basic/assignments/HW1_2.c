#include <stdio.h>

int main()
{
	int a;
	printf("Enter an integer: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&a);
//	fflush(stdin); fflush(stdout);
	printf("You entered: %d",a);
}
