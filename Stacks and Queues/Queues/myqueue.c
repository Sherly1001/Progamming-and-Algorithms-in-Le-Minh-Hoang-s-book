#include "myqueue.h"


int push(queue **qu, int val) {
    queue *p = (queue*)malloc(sizeof(queue));
    p->val = val;
    p->next = NULL;
    if (*qu == NULL) *qu = p;
    else (*qu)->next = p;
    return val;
}


int pop(queue **qu) {
    if (*qu == NULL) return 0;
    queue *p = *qu;
    int val = p->val;
    *qu = (*qu)->next;
    free(p);
    return val;
}
