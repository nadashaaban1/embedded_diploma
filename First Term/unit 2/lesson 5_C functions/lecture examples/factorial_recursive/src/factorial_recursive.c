#include <stdio.h>
int factorial(int x)
{
	if(x==1||x==0)
		return 1;
	else
		return x*factorial(x-1);
}
int main()
{
	int x;
	scanf("%d",&x);
	printf("%d",factorial(x));

}
