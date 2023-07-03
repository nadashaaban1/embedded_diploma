#include <stdio.h>
int checkIndex(int arr[],int n)
{
    int x,y;
    scanf("%d",&x);
    for(int i=n-1;i>=0;i--)
    {
        if(arr[i]==x)
        {
            y=i;
            break;
        }
        else 
        y=-1;
    }
    return y;
    
}
int main()
{
    int arr[7];
    for(int i=0;i<7;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("%d",checkIndex(arr,7));
  

}
