#include<stdio.h>

struct SComplex
{
    float mReal;
    float mImaginary;
};
struct SComplex add(struct SComplex first,struct SComplex second)
{
    struct SComplex sum;
    sum.mReal=first.mReal+second.mReal;
    sum.mImaginary=first.mImaginary+second.mImaginary;
    return sum;
}
void print(struct SComplex sum)
{
    printf("sum = %.1f + %.1fi",sum.mReal,sum.mImaginary);
}


int main()
{
    struct SComplex first,second,sum;
    printf("For 1st complex number\n");
    printf("Enter real and imaginary respectively: ");
    scanf("%f %f",&first.mReal,&first.mImaginary);
    printf("For 2nd complex number\n");
    printf("Enter real and imaginary respectively: ");
    scanf("%f %f",&second.mReal,&second.mImaginary);
    sum=add(first,second);
    print(sum);
    
    return 0;
}