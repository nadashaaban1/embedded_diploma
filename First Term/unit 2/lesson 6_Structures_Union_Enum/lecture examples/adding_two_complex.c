#include<stdio.h>

struct SComplex
{
    double mReal;
    double mImaginary;
};
struct SComplex readComplex(char name[])
{
    struct SComplex val;
    printf("Enter %s complex value ",name);
    scanf("%lf,%lf",&val.mReal,&val.mImaginary);
    return val;
}
struct SComplex add(struct SComplex x,struct SComplex y)
{
    struct SComplex sum;
    sum.mReal=x.mReal+y.mReal;
    sum.mImaginary=x.mImaginary+y.mImaginary;
    return sum;
}
void printComplex(char name[],struct SComplex sum)
{
    printf("%s = %lf + j %lf",name,sum.mReal,sum.mImaginary);
}


int main()
{
    struct SComplex x,y,z;
    x=readComplex("x");
    y=readComplex("y");
    z=add(x,y);
    printComplex("z",z);
    
    return 0;
}