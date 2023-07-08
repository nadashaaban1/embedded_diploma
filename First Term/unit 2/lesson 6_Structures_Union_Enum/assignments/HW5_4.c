#include<stdio.h>

struct student
{
   char name[50];
   int roll;
   float marks;
};
void print(struct student s[])
{
    printf("\nDisplaying Information of students:");
    for(int i=0;i<10;i++)
    {
        printf("\nFor roll number %d\n",i+1);
        printf("Name: %s",s[i].name);
        printf("\nMarks: %.1f",s[i].marks);
    }
}

int main()
{
    struct student s[10];
    printf("Enter information of students: ");
    for(int i=0;i<10;i++)
    {
        printf("\nFor roll number %d\n",i+1);
        printf("Enter name: ");
        scanf("%s",&s[i].name);
        printf("Enter marks: ");
        scanf("%f",&s[i].marks);
    }
    print(s);
    
    return 0;
}