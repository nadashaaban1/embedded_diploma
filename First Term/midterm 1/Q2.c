#include <stdio.h>
#include <math.h>
float calcSqrt(int num);
int main()
{
    int num = 0;
    printf("Enter an integer number: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d", &num);
    printf("Input:%d", num);
    printf("\nOutput:%.3f", calcSqrt(num));
}
float calcSqrt(int num)
{
    float i;
    float y, x, sqrt, temp;
    for (i = 0; i * i < num; i++);

    if (i * i == num)
    {
        sqrt = i;
    }
    else
    {
        i--;
        while(i*i<=num-0.002)
        {
            i=i+0.001;
        }
        sqrt=i;
        sqrt = round(sqrt * 1000) / 1000.0;
    }
    return sqrt;
}