#include "stdio.h"
#include "stdlib.h"
#include "stdint.h"
#include "string.h"

#ifndef LINKED_LIST_H_
#define LINKED_LIST_H_

struct sData
{
    int id;
    char name[40];
    float height;
    struct sData *pNextStudent;
};
struct sData *gpFisrtStudent=NULL;

//APIs
void addStudent();
void fillData(struct sData* new);
int deleteStudent();
void printStudents();
void deleteAll();
int getIndex(int index);
int getIndexEnd(int index);
int getLength();
void getMiddle();
void loopDetect();
int reverse();

#endif