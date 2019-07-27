#include <stdio.h>
#include <stdlib.h>

void printResult(int *arr, int *x, int k) {
    for (int i = 0; i < k; i++) printf("%d ", arr[x[i]]);
    printf("\n");
}

void try(int *arr, int *x, char *c, int n, int k, int i) {
    for (int j = 0; j < n; j++) {
        if (!c[j]) {
            x[i] = j;
            if (i == k - 1) printResult(arr, x, k);
            else {
                c[j] = 1;
                try(arr, x, c, n, k, i + 1);
                c[j] = 0;
            }
        }
    }
}

void arrangement(int *arr, int n, int k) {
    if (n <= 0 || k <= 0 || k > n) return;
    char *c = (char*)calloc(n, 1);
    int *x = (int*)calloc(n, sizeof(int));
    try(arr, x, c, n, k, 0);
    free(x);
    free(c);
}

int main() {
    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 0;
    scanf("%d", &k);
    arrangement(arr, n, k);
    return 0;
}