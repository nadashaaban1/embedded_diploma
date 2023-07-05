#include <stdio.h>
void calcUnique(int arr[],int n,int j);
int main()
{
    int arr[100],n;
    printf("Enter number of elements:");
    fflush(stdin); fflush(stdout);
    scanf("%d",&n);
    printf("Enter the array:");
    fflush(stdin); fflush(stdout);
    for(int i=0;i<n;i++)
    {
         scanf("%d",&arr[i]);
    }
    printf("input: int a[%d]={",n);
    for(int i=0;i<n;i++)
    {
         printf("%d",arr[i]);
         if(i!=n-1) printf(",");
    }
    printf("};");
    printf("\noutput:");
    calcUnique(arr,n,n-1);
   
return 0;
}

void calcUnique(int arr[],int n,int j)
{
    if(n==1) 
    {
        printf("%d",arr[n-1]);
        return;
    }
    int counter=0;
    int num=arr[j];
    for(int i=n-1;i>=0;i--)
    {
     if(i==j) continue;
   
     if(num!=arr[i]) counter++;
     else break;

    }
     if(counter==n-1) 
     {
        printf("%d",num);
        return;
     }
     else
     {
      calcUnique(arr,n,j-1);  
     }
   
}
