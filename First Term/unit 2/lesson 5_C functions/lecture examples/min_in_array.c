#include <stdio.h>
int calcMin(int arr[],int n)
{
	int min=arr[0];
	for(int i=1; i<n; i++)
	{
		if(arr[i]<min)
		min=arr[i];
	}
	return min;
}
int main()
{
	int x[5]={71,67,28,83,62};
	printf("%d",calcMin(x,5));
}
