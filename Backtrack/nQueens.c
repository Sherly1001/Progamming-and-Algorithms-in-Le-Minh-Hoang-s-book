#include <stdio.h>
#include <stdlib.h>

void printResult(int *x, int n) {
    for (int i = 0; i < n - 1; i++) printf("(%d, %d); ", i + 1, x[i] + 1);
    printf("(%d, %d)\n", n, x[n - 1] + 1);
}

void trySetQueen(int *x, int *a, int *b, int *c, int n, int i) {
    for (int j = 0; j < n; j++) {
        if (!a[j] && !b[i + j] && !c[i - j + n - 1]) {
            x[i] = j;
            a[j] = b[i + j] = c[i - j + n - 1] = 1;
            if (i == n - 1) printResult(x, n);
            else trySetQueen(x, a, b, c, n, i + 1);
            a[j] = b[i + j] = c[i - j + n - 1] = 0;
        }
    }
}

void nQueens(int n) {
    if (n <= 0) return;
    int *x = (int*)malloc(n * sizeof(int));
    int *a = (int*)calloc(n, sizeof(int));
    int *b = (int*)calloc(2 * n - 1, sizeof(int));
    int *c = (int*)calloc(2 * n - 1, sizeof(int));
    trySetQueen(x, a, b, c, n, 0);
    free(x);
    free(a);
    free(b);
    free(c);
}

int main() {
    int n = 0;
    scanf("%d", &n);
    nQueens(n);
    return 0;
}