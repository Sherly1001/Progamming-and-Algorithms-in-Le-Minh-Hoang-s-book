#include <stdio.h>
#include <stdlib.h>

void printResult(int *bestWay, int n, int minSpending) {
    if (minSpending == __INT_MAX__) return;
    for (int i = 0; i < n; i++) printf("%d->", bestWay[i] + 1);
    printf("%d\n", bestWay[0] + 1);
    printf("Cost: %d\n", minSpending);
}

void tryTour(int *x, int *bestWay, int *t, int **c, int *f, int n, int *minSpending, int i) {
    for (int j = 1; j < n; j++) {
        if (!f[j]) {
            x[i] = j;
            t[i] = t[i - 1] + c[x[i - 1]][j];
            if (t[i] < *minSpending) {
                if (i == n - 1) {
                    if (t[i] + c[i][0] < *minSpending) {
                        for (int k = 0; k < n; k++) bestWay[k] = x[k];
                        *minSpending = t[i] + c[x[i]][0];
                    }
                } else {
                    f[j] = 1;
                    tryTour(x, bestWay, t, c, f, n, minSpending, i + 1);
                    f[j] = 0;
                }
            }
        }
    }
}

void travelling() {
    int n = 0, m = 0;
    scanf("%d %d", &n, &m);
    int minSpending = __INT_MAX__;
    int *x = (int*)calloc(n, sizeof(int));
    int *bestWay = (int*)malloc(n * sizeof(int));
    int *t = (int*)calloc(n, sizeof(int));
    int *f = (int*)calloc(n, sizeof(int));
    f[0] = 1;
    int **c = (int**)calloc(n, sizeof(int*));
    for (int i = 0; i < n; i++) *(c + i) = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (i != j) c[i][j] = __INT_MAX__;
    for (int i = 0; i < m; i++) {
        int u = 0, v = 0;
        scanf("%d %d", &u, &v);
        scanf("%d", &c[u - 1][v - 1]);
        c[v - 1][u - 1] = c[u - 1][v - 1];
    }
    tryTour(x, bestWay, t, c, f, n, &minSpending, 1);
    printResult(bestWay, n, minSpending);
    free(x);
    free(bestWay);
    free(t);
    free(f);
    for (int i = 0; i < n; i++) free(*(c + i));
    free(c);
}

int main() {
    travelling();
    return 0;
}
