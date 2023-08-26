#include "linked_list.h"
#include "linked_list.c"

int main()
{
    int option,index;
    while(1)
    {
    printf("\n\tChoose one of the following options");
    printf("\n1: Add Student"); 
    printf("\n2: Delete Student");
    printf("\n3: Print Students");
    printf("\n4: Delete All");
    printf("\n5: Get Value at Nth Index");
    printf("\n6: Get Value at Nth Index from The End");
    printf("\n7: Get Length of Linked List");
    printf("\n8: Get Middle of Linked List");
    printf("\n9: Detect If a Loop Exists");
    printf("\n10: Reverse Linked List");


    printf("\nEnter option number: ");
    scanf("%d",&option);

    switch(option)
    {
    case 1:
        addStudent();
        break;
    case 2:
        deleteStudent();
        break;
    case 3:
        printStudents();
        break;
    case 4:
        deleteAll();
        break;
    case 5:
        printf("\nEnter the index: ");
        scanf("%d",&index);
        getIndex(index);
        break;
    case 6:
        printf("\nEnter the index: ");
        scanf("%d",&index);
        getIndexEnd(index);
        break;
    case 7:
        printf("\nThe Linked List Length is %d ",getLength());
        break;
    case 8:
        getMiddle();
        break;
    case 9:
        loopDetect();
        break;
    case 10:
        reverse();
        break;
    default:
        printf("\nWrong option!");
        break;
    }
    printf("\n==================\n");
    }
    return 0;
}