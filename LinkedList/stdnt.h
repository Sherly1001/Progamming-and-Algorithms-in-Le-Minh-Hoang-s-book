#ifndef __stdnt__
#define __stdnt__

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define fileName "student.txt"

typedef struct node {
    char name[100];
    char Class[30];
    char phone[15];
    float grade;
} node;

typedef struct Student{
    node stdnt;
    struct Student *prev;
    struct Student *next;
} Student;

void clrscr();
void clear();
void loadFile(Student **first);
void saveFile(Student *first);
void addNode(Student **first, node nod);
void addStudents(Student **first, int n);
void freeList(Student *first);
void printAllList(Student *first);
void printNameGrade(Student *first);
void filtByClass(Student *first);
void printMenu();
void choice(int *lc);
void StdntsManagement();
void inputData(Student **first);
void printList(Student *first);
void search(Student *frist);
void swap(Student *st1, Student *st2);
void sortByGrade(Student *first);
int compare(const char *s1, const char *s2);
char *strStr(const char *s1, const char *s2);
void enterName(char *name);
void enterClass(char *class);
void enterPhone(char *phone);
void enterGrade(float *grade);

#endif