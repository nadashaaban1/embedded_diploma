#include <stdio.h>

int main()
{
	int n, element, location,temp[100], arr[100];
	printf("Enter no. of elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&arr[i]);
	}


	printf("Enter the element to be inserted : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&element);
	printf("Enter the location : ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&location);

	for(int i=0; i<n; i++)
	{
		temp[i]=arr[i];
	}

	arr[location-1]=element;
	for(int i=location; i<n+1; i++)
	{
		arr[i]=temp[i-1];

	}



	for(int i=0; i<n+1;i++)
	{
		printf("%d ",arr[i]);
	}
}


