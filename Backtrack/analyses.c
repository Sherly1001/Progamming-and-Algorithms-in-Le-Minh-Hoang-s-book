#include <stdio.h>
#include <stdlib.h>

void printResult(int* x, int k) {
    for (int i = 0; i < k; i++)
        printf("%d + ", x[i]);
    printf("%d\n", x[k]);
}

void tryAnalyses(int* x, int* t, int n, int i) {
    for (int j = !i ? 1 : x[i - 1]; j <= (!i ? n / 2 : (n - t[i - 1]) / 2); j++) {
        x[i] = j;
        t[i] = !i ? j : t[i - 1] + j;
        tryAnalyses(x, t, n, i + 1);
    }
    x[i] = !i ? n : n - t[i - 1];
    printResult(x, i);
}

void analyses(int n) {
    if (n < 0) return;
    int* x = (int*)malloc(n * sizeof(int));
    int* t = (int*)malloc(n * sizeof(int));
    tryAnalyses(x, t, n, 0);
    free(x);
    free(t);
}

int main() {
    int n = 0;
    scanf("%d", &n);
    analyses(n);
    return 0;
}