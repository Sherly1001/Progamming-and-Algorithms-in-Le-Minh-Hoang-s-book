#include <stdio.h>
#include <stdlib.h>

void printResult(const char *ch, int len, int *best, int n, int cMin) {
    for (int i = 0; i < n; i++) printf("%c", ch[best[i]]);
    printf("\n'%c' letter count: %d\n", ch[len - 1], cMin);
}

int same(int *x, int i, int l) {
    int j = i - l;
    for (int k = 0; k < l; k++) {
        if ((j - k) < 0) return 0;
        if (x[i - k] != x[j - k]) return 0;
    }
    return 1;
}

int check(int *x, int i) {
    for (int l = 1; l <= (i + 1) / 2; l++)
        if (same(x, i, l)) return 0;
    return 1;
}

void tryAbc(const char *ch, int len, int *best, int *x, int *t, int n, int *cMin, int i) {
    for (int j = 0; j < len; j++) {
        x[i] = j;
        if (check(x, i)) {
            t[i] = !i ? 0 : (j == len - 1 ? t[i - 1] + 1 : t[i - 1]);
            if (t[i] + (n - i) / 4 < *cMin)
                if (i == n - 1) {
                    *cMin = t[i] + (n - i) / 4;
                    for (int k = 0; k < n; k++) best[k] = x[k];
                } else tryAbc(ch, len, best, x, t, n, cMin, i + 1);
        }
    }
}

void abc(int n, const char *ch, int len) {
    if (n <= 0) return;
    int cMin = n;
    int *x = (int*)malloc(n * sizeof(int));
    int *best = (int*)malloc(n * sizeof(int));
    int *t = (int*)calloc(n, sizeof(int));
    tryAbc(ch, len, best, x, t, n, &cMin, 0);
    printResult(ch, len, best, n, cMin);
    free(x);
    free(best);
    free(t);
}

int main() {
    char ch[] = "ABC";
    int len = sizeof(ch) / sizeof(ch[0]) - 1;
    int n = 0;
    scanf("%d", &n);
    abc(n, ch, len);
    return 0;
}