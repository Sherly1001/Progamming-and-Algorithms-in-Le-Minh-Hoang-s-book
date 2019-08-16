#ifndef __mystack__
#define __mystack__

#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int val;
    struct stack *prev;
} stack;

int push(stack **st, int val);
int pop(stack **st);


#endif