 #include <stdio.h>

int main()
{
	int n=0;
	float arr[100], sum=0;
	printf("Enter the numbers of data: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		printf("%d. Enter number: ",i+1);
		fflush(stdin); fflush(stdout);
			scanf("%f",&arr[i]);
			sum+=arr[i];
	}
	printf("Average = %.1f",sum/n);
}

