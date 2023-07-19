#include <stdio.h>

struct sData
{
    char name[50];
    int id;
}emp1={"Claire",1003},emp2={"Alex",1002},emp3={"Luke",1004};
int main ()
{
    int n,x;
    //struct sData arr[50];
   /*printf("Enter number of employee: ");
    scanf("%d",&n);
    for(int i=0; i<n; i++)
    {
        printf("Employee (%d) Name: ",i+1);
        scanf("%s",&arr[i].name);
        printf("Employee (%d) ID: ",i+1);
        scanf("%d",&arr[i].id);

    }*/
    //struct sData* employee[50];
    struct sData* arr[3]={&emp1,&emp2,&emp3};
    struct sData* (*ptr)[3]=&arr;
    // printf("Choose employee number: ");
    // scanf("%d",&x);

    printf("Employee Name: %s\n",(*(*ptr+1))->name);
    printf("Employee ID: %d",(*(*ptr+1))->id);

    return 0;
}