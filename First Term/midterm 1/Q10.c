#include <stdio.h>
int calcOnes(int arr[], int n);
void calcBin(int num);
int main()
{
    int num;
    printf("Enter a number: ");
    fflush(stdin);
    fflush(stdout);
    scanf("%d", &num);
    printf("input:%d(", num);
    calcBin(num);
    return 0;
}
void calcBin(int num)
{
    if (num == 0)
        printf("0");
    int arr[32], i = 0;

    while (num)
    {
        arr[i] = num & 1;
        i++;
        num = num >> 1;
        arr[i + 1] = 0;
    }

    for (int k = i; k >= 0; k--)
    {
        printf("%d", arr[k]);
    }
    printf(")");

    printf("\noutput:%d", calcOnes(arr, i));
}
int calcOnes(int arr[], int n)
{
    int ones = 0, oldOnes = 0;
    for (int k = n - 1; k >= 0; k--)
    {
         int i = 0;
        if (arr[k] == 0)
        {
            while (arr[k + i + 1])
            {
                ones++;
                i++;
            }
            if (ones > oldOnes)
            {
                oldOnes = ones;
                ones = 0;
            }
            
        }
    }
    if(ones>oldOnes)
    return ones;
    else
    return oldOnes;
}