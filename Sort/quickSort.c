#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int t = *a; *a = *b, *b = t;
}

int partition(int *a, int l, int h) {
    int p = a[h];
    int i = l;
    for (int j = l; j < h; j++)
        if (a[j] < p)
            swap(&a[i++], &a[j]);
    swap(&a[i], &a[h]);
    return i;
}

void qs(int *a, int l, int h) {
    if (l >= h) return;
    int p = partition(a, l, h);
    qs(a, l, p - 1);
    qs(a, p + 1, h);
}

void quickSort(int *a, int n) {
    qs(a, 0, n - 1);
}

void prtArr(const int *a, const int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {1, 3, 2, 5, 3, 2, 5, 4};
    int n = sizeof(a) / sizeof(a[0]);
    prtArr(a, n);
    quickSort(a, n);
    prtArr(a, n);
    return 0;
}
