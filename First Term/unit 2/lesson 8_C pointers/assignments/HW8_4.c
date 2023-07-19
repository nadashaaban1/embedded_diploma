#include <stdio.h>

int main()
{
    int n, arr[15];
    int *p=arr;  
    printf("Enter th number of elements to store in the array (max 15): ");
    scanf("%d",&n);
    printf("Enter %d number of elements in the array: \n",n);
    for(int i=0; i<n; i++)
    {
    printf("element - %d : ",i+1);
    scanf("%d",p);
    p++;
    }
    p=&arr[n-1];
    printf("the elements of array in reverse order are:\n");
    for(int i=n; i>0; i--)
    {
    printf("element - %d : %d\n",i,*p);
    p--;
    }

}