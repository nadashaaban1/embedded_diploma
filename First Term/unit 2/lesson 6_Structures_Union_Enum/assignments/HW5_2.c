#include <stdio.h>

struct sDistance
{
    int feet;
    float inch;
};
struct sDistance add(struct sDistance first, struct sDistance second)
{
    struct sDistance sum;
    sum.feet=first.feet+second.feet;
    sum.inch=first.inch+second.inch;
    if(sum.inch>12)
    {
        sum.inch-=12;
        sum.feet++;
    }

    return sum;
}
void print(struct sDistance sum)
{
    printf("Sum of distances=%d' %.1f\"",sum.feet,sum.inch );
}

int main()
{
    struct sDistance first;
    struct sDistance second;
    struct sDistance sum;

    printf("Enter information for 1st distance: ");
    printf("\nEnter feet: ");
    scanf("%d", &first.feet);
    printf("Enter inch: ");
    scanf("%f", &first.inch);

    printf("Enter information for 2nd distance: ");
    printf("\nEnter feet: ");
    scanf("%d", &second.feet);
    printf("Enter inch: ");
    scanf("%f", &second.inch);

    sum = add(first, second);
    print(sum);

    return 0;
}