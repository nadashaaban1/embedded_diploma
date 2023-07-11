#include <stdio.h>
int main()
{
  int a[100];
  int b[100];
  int temp[100];
  int n,m;
  printf("Enter first array size: ");
  fflush(stdin);
  fflush(stdout);
  scanf("%d", &n);
  printf("Enter first array: ");
  fflush(stdin);
  fflush(stdout);
  for (int i = 0; i < n; i++)
  {
    scanf("%d ", &a[i]);
  }
  printf("Enter second array size: ");
  fflush(stdin);
  fflush(stdout);
  scanf("%d", &m);
  printf("Enter second array: ");
  fflush(stdin);
  fflush(stdout);
  for (int i = 0; i < m; i++)
  {
    scanf("%d ", &b[i]);
  }
if(n>m)
{
  for(int i=0; i<n; i++)
  {
    temp[i]=a[i];
    a[i]=b[i];
    b[i]=temp[i];
  }
}
else 
{
  for(int i=0; i<m; i++)
  {
    temp[i]=a[i];
    a[i]=b[i];
    b[i]=temp[i];
  }
}
printf("first array after swapping = ");
for(int i=0;i<m;i++)
{
  printf("%d ",a[i]);
}
printf("second array after swapping = ");
for(int i=0;i<n;i++)
{
  printf("%d ",b[i]);
}


}
