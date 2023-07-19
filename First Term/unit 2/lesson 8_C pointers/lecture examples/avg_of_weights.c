#include <stdio.h>
int main()
{
    int weight[5];
    int sum = 0;
    int *pW = weight;
    printf("Enter the weight of the boxes\n");
    for (int i = 0; i < 5; i++)
        scanf("%d ", pW + i);
    for (int i = 0; i < 5; i++, pW++)
        sum += *pW;
    printf("sum= %d", sum);
    return 0;
}