#include <stdio.h>
#include <stdlib.h>

int countMine(const int* x, int m, int n, int i) {
    int count = 0;
    for (int k = -n; k <= n; k += n) {
        if ((i < n && k == -n) || (i >= n * (m - 1) && k == n)) continue;
        for (int h = -1; h <= 1; h++) {
            if ((i % n == 0 && h == -1) || (i % n == n - 1 && h == 1)) continue;
            if (h == 0 && k == 0) continue;
            if (x[i + h + k]) count++;
        }
    }
    return count;
}

int preCount(const int *x, int m, int n, int i) {
    int count = 0;
    for (int k = -n; k <= n; k += n) {
        if ((i < n && k == -n) || (i >= n * (m - 1) && k == n)) continue;
        for (int h = -1; h <= 1; h++) {
            if (h + k >= 0) continue;
            if ((i % n == 0 && h == -1) || (i % n == n - 1 && h == 1)) continue;
            if (x[i + h + k]) count++;
        }
    }
    return count;
}

void printResult(const int *x, int m, int n) {
    printf("\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) printf("%d ", x[i * n + j]);
        printf("\n");
    }
}

int check(const int *map, const int *x, int m, int n) {
    for (int i = 0; i < m * n; i++) if (map[i] != countMine(x, m, n, i)) return 0;
    return 1;
}

void trySetMine(const int *map, int *x, int m, int n, int i) {
    for (int j = 1; j >= 0; j--) {
        x[i] = j;
        if (preCount(x, m, n, i) > map[i]) continue;
        if (i < m * n - 1) trySetMine(map, x, m, n, i + 1);
        else if (check(map, x, m, n)) printResult(x, m, n);
    }
}

void mineWeep(const int *map, int m, int n) {
    if (m < 2 || n < 2) return;
    int *x = (int*)calloc(m * n, sizeof(int));
    trySetMine(map, x, m, n, 0);
    free(x);
}

int main() {
    int m = 0, n = 0;
    scanf("%d %d", &m, &n);
    int *map = (int*)malloc(m * n * sizeof(int));
    for (int i = 0; i < m; i++) for (int j = 0; j < n; j++) scanf("%d", &map[i * n + j]);
    mineWeep(map, m, n);
    return 0;
}
