#include <stdio.h>
#include <string.h>
int calcPower(int base,int n)
{

	int val=base;
	if(n>0)
	return (val*calcPower(base,n-1));
	else
		return 1;
}
int main()
{
	int base,n;
	printf("Enter base number: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&base);
	printf("Enter power number(positive integer): ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	printf("%d^%d = %d",base,n,calcPower(base,n));



}
