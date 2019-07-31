#include <stdio.h>
#include <stdlib.h>

int depth(int *x, int n) {
    if (x[0] || n < 0) return -1;
    if (n == 0) return 0;
    int d = 0, flag = 0;
    for (int i = 0; i < n; i++) {
        if (d == flag && !x[i]) d++;
        if (x[i]) flag--;
        else flag++;
    }
    return d;
}

void printResult(const char *ch, int *x, int n) {
    for (int i = 0; i < n; i++) printf("%c", ch[x[i]]);
    printf("\n");
}

void tryBracket(const char *ch, int *x, int n, int k, int *open, int *close, int i) {
    for (int j = 0; j < 2; j++) {
        x[i] = j;
        int d = depth(x, i + 1);
        if (d > k) continue;
        if (j) {
            open[i] = open[i - 1];
            close[i] = close[i - 1] + 1;
        } else {
            open[i] = open[i - 1] + 1;
            close[i] = close[i - 1];
        }
        if (close[i] > open[i]) continue;
        if (open[i] > n / 2) continue;
        if (i == n - 1)
            if (d == k) printResult(ch, x, n);
            else return;
        else tryBracket(ch, x, n, k, open, close, i + 1);
    }
}

void bracket(int n, int k) {
    if (n <= 0 || k < 0 || k > n) return;
    int *x = (int*)calloc(2 * n, sizeof(int));
    int *open = (int*)calloc(2 * n, sizeof(int));
    open[0] = 1;
    int *close = (int*)calloc(2 * n, sizeof(int));
    char ch[] = "()";
    tryBracket(ch, x, 2 * n, k, open, close, 1);
    free(x);
    free(open);
    free(close);
}

int main() {
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    bracket(n, k);
    return 0;
}
