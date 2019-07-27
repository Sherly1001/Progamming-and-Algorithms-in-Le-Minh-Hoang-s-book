#include <stdio.h>
#include <stdlib.h>


void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void permutation(int *arr, int size) {
    if (size <= 0) return;
    int *x = (int*)malloc(sizeof(int) * size);
    for (int i = 0; i < size; i++) x[i] = i;
    while (1) {
        printf("{");
        for (int i = 0; i < size - 1; i++) printf("%d, ", arr[x[i]]);
        printf("%d}\n", arr[x[size - 1]]);
        int i = size - 2;
        while (x[i] > x[i + 1] && i >= 0) i--;
        if (i < 0) break;
        int k = size - 1;
        for (k = size - 1; k > i; k--) if (x[k] > x[i]) break;
        swap(&x[i], &x[k]);
        k = size - 1;
        i++;
        while (i < k) swap(&x[i++], &x[k--]);
    }
    free(x);
}

int main() {
    int a[] = {1, 2, 3, 4};
    int size = sizeof(a) / sizeof(a[0]);
    permutation(a, size);
    return 0;
}
