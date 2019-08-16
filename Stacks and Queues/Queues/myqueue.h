#ifndef __myqueue__
#define __myqueue__

#include <stdlib.h>
#include <stdio.h>

typedef struct queue {
    int val;
    struct queue *next;
} queue;

int push(queue **qu, int val);
int pop(queue **qu);

#endif