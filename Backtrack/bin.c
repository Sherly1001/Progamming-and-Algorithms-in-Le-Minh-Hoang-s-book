#include <stdio.h>
#include <stdlib.h>

void printResult(int *x, int n) {
    for (int i = 0; i < n; i++) printf("%d", x[i]);
    printf("\n");
}

void try(int *x, int n, int i) {
    for (int j = 0; j < 2; j++) {
        x[i] = j;
        if (i == n - 1) printResult(x, n);
        else try(x, n, i + 1);
    }
}

void bin(int n) {
    if (n <= 0) return;
    int *x = (int*)calloc(n, sizeof(int));
    try(x, n, 0);
    free(x);
}

int main() {
    int n = 0;
    scanf("%d", &n);
    bin(n);
    return 0;
}
