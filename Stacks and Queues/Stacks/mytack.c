#include "mystack.h"



int push(stack **st, int val) {
    stack *p = (stack*)malloc(sizeof(stack));
    p->val = val;
    p->prev = *st;
    *st = p;
    return val;
}


int pop(stack **st) {
    if (*st == NULL) {
        // printf("\nStack is empty\n");
        return 0;
    }
    else {
        int p = (*st)->val;
        stack *pr = (*st)->prev;
        free(*st);
        *st = pr;
        return p;
    }
}
