#include<stdio.h>
#define pi 3.1415
#define area(r) (pi*(r)*(r))
int main()
{
    int r;
    float area;
    printf("Enter the radius: ");
    scanf("%d",&r);
    area=area(r);
    printf("Area= %.2f",area);

    return 0;
}