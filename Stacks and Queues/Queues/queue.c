#include <stdio.h>
#include <stdlib.h>

typedef int qtype;

typedef struct queue {
    qtype val;
    struct queue *next;
    struct queue *rear;
} queue;

int empty(queue **q);
qtype deQ(queue **q, qtype val);
qtype enQ(queue **q);


int main() {
    int n = 4;
    queue *q = NULL;
    for (int i = 0; i < n; i++) deQ(&q, i);
    while (q != NULL) printf("%d\n", enQ(&q));
    return 0;
}

int empty(queue **q) {
    return *q == NULL;
}

qtype deQ(queue **q, qtype val) {
    queue *p = (queue*)malloc(sizeof(queue));
    p->val = val;
    p->next = NULL;

    if (*q == NULL) {
        *q = p;
        (*q)->next = p;
    } else {
        q->rear->next = p;
    }
    (*q)->rear = p;
    return val;
}

qtype enQ(queue **q) {
    if (*q == NULL) {
        printf("Queue is empty\n");
        return 0;
    }
    qtype val = (*q)->val;
    queue *tmp = *q;
    *q = (*q)->next;
    free(tmp);
    return val;
}