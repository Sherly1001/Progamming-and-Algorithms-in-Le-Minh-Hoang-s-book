#include <stdio.h>
#include <stdlib.h>

void printResult(int *arr, int *x, int k) {
    printf("{");
    for (int i = 0; i < k - 1; i++) printf("%d, ", arr[x[i]]);
    printf("%d}\n", arr[x[k - 1]]);
}

void try(int *arr, int *x, int n, int k, int i) {
    for (int j = !i ? 0 : x[i - 1] + 1; j <= n - k + i; j++) {
        x[i] = j;
        if (i == k - 1) printResult(arr, x, k);
        else try(arr, x, n, k, i + 1);
    }
}

void subSet(int *arr, int n, int k) {
    if (n <= 0 || k <= 0 || k > n) return;
    int *x = (int*)calloc(k, sizeof(int));
    try(arr, x, n, k, 0);
    free(x);
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 0;
    scanf("%d", &k);
    subSet(arr, n, k);
    return 0;
}