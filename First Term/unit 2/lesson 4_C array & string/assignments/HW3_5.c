#include <stdio.h>

int main()
{
	int n, element, location, arr[100];
	printf("Enter no. of elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}


	printf("Enter the element to be searched : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&element);

	for(int i=0; i<n; i++)
	{
		if (arr[i]==element) location=i+1;
	}

	printf("Number found at the location = %d",location);



}


