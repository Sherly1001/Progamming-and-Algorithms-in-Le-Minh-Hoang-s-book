#include <stdio.h>
#include <stdlib.h>

void prt(int *arr, int n) {
    for (int i = 0; i < n; ++i) printf("%d ", arr[i]);
    printf("\n");
}

void merge(int *a, int *t, int l, int m, int h) {
    for (int i = l, j = m + 1, p = 0; i <= m || j <= h; ++p) i <= m ? j <= h ? t[p] = (a[i] < a[j]) ? a[i++] : a[j++] : (t[p] = a[i++]) : j <= h && (t[p] = a[j++]);

    for (int i = l; i <= h; ++i) a[i] = t[i - l];
}

void ms(int *a, int *t, int l, int h) {
    if (l >= h) return;
    int m = (h - l) / 2 + l;
    ms(a, t, l, m);
    ms(a, t, m + 1, h);
    merge(a, t, l, m, h);
}

void mergeSort(int *arr, int n) {
    if (n < 2) return;
    int *t = (int*)malloc(sizeof(int) * n);
    ms(arr, t, 0, n - 1);
    free(t);
}

int main(int ag, char **av) {
    int a[] = {1, 4, 7, 5, 3};
    int n = sizeof(a) / sizeof(a[0]);
    prt(a, n);
    mergeSort(a, n);
    prt(a, n);
    return 0;
}
