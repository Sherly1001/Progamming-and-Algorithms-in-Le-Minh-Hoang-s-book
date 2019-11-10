#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct tree {
    int val;
    struct tree *left, *right;
} tree;


void add(tree **t, int val) {
    tree **tmp = t;
    while (*tmp) {
        tmp = val <= (*tmp)->val ? &(*tmp)->left : &(*tmp)->right;
    }
    *tmp = (tree*)malloc(sizeof(tree));
    (*tmp)->val = val;
    (*tmp)->left = (*tmp)->right = NULL;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int height(const tree *t) {
    if (!t) return 0;
    if (!t->left && !t->right) return 1;
    return 1 + max(height(t->left), height(t->right));
}

void _l(const tree *t, int *l) {
    if (t) {
        if (!t->left && !t->right) (*l)++;
        _l(t->left, l);
        _l(t->right, l);
    }
}

int leaf(const tree *t) {
    int l = 0;
    _l(t, &l);
    return l;
}

void _n(const tree *t, int *n) {
    if (t) {
        (*n)++;
        _n(t->left, n);
        _n(t->right, n);
    }
}

int node(const tree *t) {
    int n = 0;
    _n(t, &n);
    return n;
}

void _rc(const tree *t, int *rc) {
    if (t) {
        *rc += !!t->right;
        _rc(t->right, rc);
        _rc(t->left, rc);
    }
}

int rightChild(const tree *t) {
    int rc = 0;
    _rc(t, &rc);
    return rc;
}


int _pt(const tree *t, int isLeft, int offset, int depth, char **b) {
    if (!t) return 0;
    
    char bf[20];
    int width = 5;
    sprintf(bf, "(%03d)", t->val);
    int left = _pt(t->left, 1, offset, depth + 1, b);
    int right = _pt(t->right, 0, offset + left + width, depth + 1, b);

    for (int i = 0; i < width; i++)
        b[depth][offset + left + i] = bf[i];
    if (depth && isLeft) {
        for (int i = 0; i < width + right; i++)
            b[depth - 1][offset + left + width / 2 + i] = 0xc4;
        b[depth - 1][offset + left + width / 2] = 0xda;
    } else if (depth) {
        for (int i = 0; i < width + left; i++)
            b[depth - 1][offset - width / 2 + i] = 0xc4;
        b[depth - 1][offset + left + width / 2] = 0xbf;
    }
    return left + width + right;
}

void pt(const tree *t) {
    char** b = (char**)malloc(sizeof(char*) * 50);
    for (int i = 0; i < 50; i++) {
        b[i] = (char*)malloc(sizeof(char) * 255);
        sprintf(b[i], "%100s", " ");
    }
    _pt(t, 0, 0, 0, b);
    printf("\n");
    int h = height(t);
    for (int i = 0; i < h; i++)
        printf("%s\n", b[i]);
    for (int i = 0; i < 50; i++) free(b[i]);
    free(b);
}


int main() {
    srand(time(0));
    tree *t = NULL;
    for (int i = 0; i < 20; i++) add(&t, rand() % 20);
    pt(t);

    int h = height(t);
    int l = leaf(t);
    int n = node(t);
    int rc = rightChild(t);

    printf("\nheight: %d\n", h);
    printf("Number of leaf: %d\n", l);
    printf("Number of internal node: %d\n", n - l);
    printf("Number of right child: %d\n", rc);
    return 0;
}