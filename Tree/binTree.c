#include <stdio.h>
#include <stdlib.h>

typedef struct binTree{
    int data;
    struct binTree *left;
    struct binTree *right;
} binTree;

typedef struct stack {
    binTree *val;
    struct stack *prev;
} stack;


binTree *push(stack **st, binTree *val);
binTree *pop(stack **st);
binTree *back(stack *st);
int empty(stack *st);


void preorderTraversal(binTree *t);
void inorderTraversal(binTree *t);
void postorderTraversal(binTree *t);
void addLeft(binTree *t, int data);
void addright(binTree *t, int data);
void preorderTraversalNonRcursion(binTree *t);
void inorderTraversalNonRcursion(binTree *t);
void postorderTraversalNonRcursion(binTree *t);


int main(int ar, char **av) {
    binTree *t = (binTree*)malloc(sizeof(binTree));
    t->data = 0;
    t->left = t->right = NULL;
    addLeft(t, 1);
    addright(t, 2);
    addLeft(t->left, 3);
    addright(t->left, 4);
    addLeft(t->right, 5);
    addright(t->right, 6);
    preorderTraversal(t);
    putchar('\n');
    preorderTraversalNonRcursion(t);

    inorderTraversal(t);
    putchar('\n');
    inorderTraversalNonRcursion(t);

    postorderTraversal(t);
    putchar('\n');
    postorderTraversalNonRcursion(t);
    free(t);
    return 0;
}

void preorderTraversal(binTree *t) {
    if (t == NULL) return;
    printf("%d ", t->data);
    preorderTraversal(t->left);
    preorderTraversal(t->right);
}

void inorderTraversal(binTree *t) {
    if (t == NULL) return;
    preorderTraversal(t->left);
    printf("%d ", t->data);
    preorderTraversal(t->right);
}

void postorderTraversal(binTree *t) {
    if (t == NULL) return;
    preorderTraversal(t->left);
    preorderTraversal(t->right);
    printf("%d ", t->data);
}

void addLeft(binTree *t, int data) {
    if (t == NULL) return;
    t->left = (binTree*)malloc(sizeof(binTree));
    t->left->data = data;
    t->left->left = t->left->right = NULL;
}

void addright(binTree *t, int data) {
    if (t == NULL) return;
    t->right = (binTree*)malloc(sizeof(binTree));
    t->right->data = data;
    t->right->left = t->right->right = NULL;
}

void preorderTraversalNonRcursion(binTree *t) {
    binTree *temp = t;
    stack *st = NULL;
    while (temp != NULL) {
        if (temp->right) push(&st, temp->right);
        printf("%d ", temp->data);
        temp = temp->left ? temp->left : pop(&st);
    }
}

void inorderTraversalNonRcursion(binTree *t) {
}

void postorderTraversalNonRcursion(binTree *t) {
}

binTree *push(stack **st, binTree *val) {
    stack *p = (stack*)malloc(sizeof(stack));
    p->val = val;
    p->prev = *st;
    *st = p;
    return val;
}

binTree *pop(stack **st) {
    if (*st == NULL) {
        // printf("\nStack is empty\n");
        return NULL;
    }
    else {
        binTree *p = (*st)->val;
        stack *pr = (*st)->prev;
        free(*st);
        *st = pr;
        return p;
    }
}

int empty(stack *st) {
    return st->val == NULL;
}

binTree *back(stack *st) {
    return st->val;
}
