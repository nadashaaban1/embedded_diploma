#include "linked_list.h"

//APIs
void addStudent()
{
    struct sData* pNewStudent;
    struct sData* pLastStudent;
    //check if the list is empty
    if(!gpFisrtStudent)
    {
        //create new record
        pNewStudent=(struct sData*) malloc(sizeof(struct sData));
        gpFisrtStudent=pNewStudent;
        pNewStudent->pNextStudent=NULL;
        
    }
    else
    {
        //navigate till you reach the last record
        pLastStudent=gpFisrtStudent;
        while(pLastStudent->pNextStudent)
            pLastStudent= pLastStudent->pNextStudent;

        //create new record
        pNewStudent=(struct sData*) malloc(sizeof(struct sData));
        if(pNewStudent)
        {
        pLastStudent->pNextStudent=pNewStudent;
        pNewStudent->pNextStudent=NULL;
        }
        else
        printf("ERROR! malloc has failed!");
        
    }

    fillData(pNewStudent);
}

void fillData(struct sData* new)
{
    printf("\nEnter student ID: ");
    scanf("%d",&new->id);
    printf("\nEnter student full name: ");
   // while (getchar() != '\n');
    gets(new->name);
    gets(new->name);
    printf("\nEnter student height: ");
    scanf("%f",&new->height);
}

int deleteStudent()
{
    int selectedID,i;
    struct sData* pPrevStudent=NULL;
    struct sData* pSelectedStudent=gpFisrtStudent;
    printf("\nEnter student ID to be deleted: ");
    scanf("%d",&selectedID);

    //navigate until you reach the required data
    while(pSelectedStudent)
    {
        //if target node
        if(selectedID==pSelectedStudent->id)
        {
            //if the first element
            if(!pPrevStudent)
                gpFisrtStudent=pSelectedStudent->pNextStudent;

            //if the last element
            else if(!pSelectedStudent->pNextStudent)
                pPrevStudent->pNextStudent=NULL;
                
            else 
            pPrevStudent->pNextStudent=pSelectedStudent->pNextStudent;

        free(pSelectedStudent);
        return 1; //found
        }
        //if not target node
        else
        {
            pPrevStudent=pSelectedStudent;
            pSelectedStudent=pSelectedStudent->pNextStudent;
        }


    }
   
printf("\nStudent was not found!");   
return 0;
}

void printStudents()
{
    struct sData* pCurrentStudent=gpFisrtStudent;
    int count=0;
    //check if empty
    if(!gpFisrtStudent)
        printf("\nList is empty");
    
    while(pCurrentStudent)
    {
        printf("\nStudent number %d ",count+1);
        printf("\nID: %d",pCurrentStudent->id);
        printf("\nName: %s",pCurrentStudent->name);
        printf("\nHeight: %.3f",pCurrentStudent->height);

        pCurrentStudent=pCurrentStudent->pNextStudent;
        count++;
    }
}

void deleteAll()
{
    struct sData* pCurrentStudent=gpFisrtStudent;
    struct sData* pTempStudent=pCurrentStudent;

        //check if empty
    if(!pCurrentStudent)
        printf("\nList is empty");
    
    while(pTempStudent)
    {
        pTempStudent=pCurrentStudent->pNextStudent;
        free(pCurrentStudent);
        pCurrentStudent=pTempStudent;
    }
    gpFisrtStudent=NULL;
}

int getIndex(int index)
{
    int count=0;
    struct sData* pTarget=gpFisrtStudent;
    //check if empty
    if(!gpFisrtStudent)
    {
        printf("\nList is empty");
        return 0;
    }
     //check if index exists
    if(getLength() < index+1)
        {
            printf("Index doesn't exist!");
            return 0;
        }

    while(count != index)
    {
        pTarget=pTarget->pNextStudent;
        count++;

    }
    printf("\nThe node at index %d :",index);
    printf("\nID: %d",pTarget->id);
    printf("\nName: %s",pTarget->name);
    printf("\nHeight: %.3f",pTarget->height);
return 1;

}

int getIndexEnd(int index)
{
    int count=0;
    struct sData *pRef=gpFisrtStudent, *pTarget=gpFisrtStudent;

    //check if empty
    if(!gpFisrtStudent)
    {
        printf("\nList is empty");
        return 0;
    }
     //check if index exists
     if(getLength() < index+1)
        {
            printf("Index doesn't exist!");
            return 0;
        }
    while(count != index)
    {
        pRef=pRef->pNextStudent;
        count++;
    }
    while (pRef->pNextStudent)
    {
        pRef=pRef->pNextStudent;
        pTarget=pTarget->pNextStudent;
    }
    
    printf("\nThe node at index %d :",index);
    printf("\nID: %d",pTarget->id);
    printf("\nName: %s",pTarget->name);
    printf("\nHeight: %.3f",pTarget->height);
return 1;
}

int getLength()
{
    struct sData* temp=gpFisrtStudent;
    int count=0;;
        //check if empty
    if(!gpFisrtStudent)
    {
        printf("\nList is empty");
        return 0;
    }
    else 
    {
        while (temp->pNextStudent)
        {
            temp=temp->pNextStudent;
            count++;
        }

return count+1;
    }
}

void getMiddle()
{
    struct sData *pSlow=gpFisrtStudent, *pFast=gpFisrtStudent;

    //check if empty
    if(!gpFisrtStudent)
    {
        printf("\nList is empty");
    }
    else
    {
        while (pFast->pNextStudent)
        {
            pFast=pFast->pNextStudent;
            pSlow=pSlow->pNextStudent;
            if(pFast->pNextStudent)
                pFast=pFast->pNextStudent;
        }
    printf("\nID of The Middle Node: %d",pSlow->id);
    printf("\nName of The Middle Node: %s",pSlow->name);
    printf("\nHeight of The Middle Node: %.3f",pSlow->height);   
    }
}

void loopDetect()
{
    struct sData *pSlow=gpFisrtStudent, *pFast=gpFisrtStudent;

    //check if empty
    if(!gpFisrtStudent)
    {
        printf("\nList is empty");
    }
    else
    {
        while (pFast->pNextStudent)
        {
            pFast=pFast->pNextStudent;
            pSlow=pSlow->pNextStudent;
            if(pFast->pNextStudent)
                pFast=pFast->pNextStudent;
            if(pFast==pSlow)
                {
                    printf("\nFound Loop");
                    break;
                }
            else
            printf("\nNo Loop was Found");
        }   
    }
}

int reverse()
{
    struct sData *pTempStudent1=NULL,*pTempStudent2=gpFisrtStudent,*pHead=gpFisrtStudent;
    //check if empty
    if(!gpFisrtStudent)
    {
        printf("\nList is empty");
        return 0;
    }
    //check if there's only 1 element in the list
    if(!pHead->pNextStudent)
        return 0;
    else
    {
        while(pHead)
        {
            pTempStudent2=pHead->pNextStudent;
            pHead->pNextStudent=pTempStudent1;
            pTempStudent1=pHead;
            pHead=pTempStudent2;
        }
        pHead=pTempStudent1;
        gpFisrtStudent=pHead;
    }

return 1;
}