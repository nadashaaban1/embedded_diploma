#include <stdio.h>
void reverse(int arr[],int n);
int main()
{
	int arr[100],n;
	printf("Enter number of elements: ");
	fflush(stdin); fflush(stdout);
	scanf("%d",&n);
    printf("Enter an array: ");
    fflush(stdin); fflush(stdout);
    for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);

    printf("input: int a[%d]={",n);
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
        if(i!=n-1) printf(",");
    }
    printf("}");
    
	printf("\noutput: ");
	reverse(arr,n);


}
void reverse(int arr[],int n)
{
    for(int i=n-1;i>=0;i--)
    printf("%d ",arr[i]);
}
