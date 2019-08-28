#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
void freeTree(binTree *t);
void preorderTraversalNonRcursion(binTree *t);
void inorderTraversalNonRcursion(binTree *t);
void postorderTraversalNonRcursion(binTree *t);
void postorderTraversalNonRcursion2(binTree *t);

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
    printf("\n\n");

    inorderTraversal(t);
    putchar('\n');
    inorderTraversalNonRcursion(t);
    printf("\n\n");

    postorderTraversal(t);
    putchar('\n');
    postorderTraversalNonRcursion(t);
    printf("\n\n");
    postorderTraversalNonRcursion2(t);

    freeTree(t);
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
    inorderTraversal(t->left);
    printf("%d ", t->data);
    inorderTraversal(t->right);
}

void postorderTraversal(binTree *t) {
    if (t == NULL) return;
    postorderTraversal(t->left);
    postorderTraversal(t->right);
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
    binTree *temp = t;
    stack *st = NULL;
    do {
        while (temp != NULL) {
            push(&st, temp);
            temp = temp->left;
        }
        printf("%d ", back(st)->data);
        temp = pop(&st)->right;
    } while (temp != NULL || !empty(st));
}

void postorderTraversalNonRcursion(binTree *t) {
    binTree *temp = t;
    stack *st = NULL;
    do {
        while (temp != NULL) {
            if (temp->right) push(&st, temp->right);
            if (temp) push(&st, temp);
            temp = temp->left;
        }
        temp = pop(&st);
        if (temp->right == back(st)) {
            pop(&st);
            push(&st, temp);
            temp = temp->right;
        } else {
            printf("%d ", temp->data);
            temp = NULL;
        }
    } while (!empty(st));
}

void postorderTraversalNonRcursion2(binTree *t) {
    binTree *temp = t;
    stack *st = NULL;
    char s[100] = "";
    char stmp[10] = "";
    while (temp != NULL) {
        if (temp->left) push(&st, temp->left);
        sprintf(stmp, "%d ", temp->data);
        strcat(s, stmp);
        temp = temp->right ? temp->right : pop(&st);
    }
    for (int i = strlen(s) - 2; i >= 0; i--) printf("%c", s[i]);
}

void freeTree(binTree *t) {
    if (t == NULL) return;
    freeTree(t->left);
    freeTree(t->right);
    free(t);
    t = NULL;
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
    return st == NULL;
}

binTree *back(stack *st) {
    if (st == NULL) return NULL;
    return st->val;
}
