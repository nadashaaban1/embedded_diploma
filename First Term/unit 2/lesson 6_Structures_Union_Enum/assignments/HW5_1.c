#include<stdio.h>

struct student
{
   char name[50];
   int roll;
   float marks;
};
void print(struct student s)
{
    printf("\nDisplaying Information");
    printf("\nName: %s",s.name);
    printf("\nRoll: %d",s.roll);
    printf("\nMarks: %.2f",s.marks);
}

int main()
{
    struct student s;
    printf("Enter information of students: ");
    printf("\nEnter name: ");
    gets(s.name);
    printf("Enter roll number: ");
    scanf("%d",&s.roll);
    printf("Enter marks: ");
    scanf("%f",&s.marks);
    print(s);
    
    return 0;
}