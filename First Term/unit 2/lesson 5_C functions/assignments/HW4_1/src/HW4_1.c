#include <stdio.h>
void calcPrime(int x,int y);
int main()
{
	int x,y;
	printf("Enter two numbers(intervals): ");
	fflush(stdin); fflush(stdout);
	scanf("%d" "%d",&x,&y);
	printf("Prime numbers between %d and %d are: ",x,y);
	calcPrime(x,y);
}
void calcPrime(int x,int y)
{
	int primes[100],k=0;
	for(int i=x;i<=y;i++)
	{
		int flag=1;
		if(i<=1) flag=0;

		for(int j=2;j<i;j++)
		{
			if(i%j==0)
			{
				flag=0;
				break;
			}
		}
		if(flag)
			primes[k++]=i;
	}
	for(int i=0;i<k;i++)
		printf("%d ",primes[i]);
}

