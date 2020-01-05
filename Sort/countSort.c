#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void prtArr(const int *a, const int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

#define MS 100
void countSort(int *a, int n) {
    int c[MS] = {0};
    int *t = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; ++i) ++c[a[i]];
    for (int i = 1; i < MS; ++i) c[i] += c[i - 1];

    for (int i = n - 1; i >= 0; --i) t[--c[a[i]]] = a[i];

    for (int i = 0; i < n; ++i) a[i] = t[i];
    free(t);
}

int main() {
    srand(time(NULL));
    int mm = 10;
    // int a[] = {1, 3, 2, 5, 3, 2, 5, 4};
    int *a = (int*)malloc(sizeof(int) * mm);
    for (int i = 0; i < mm; i++) a[i] = rand() % MS;
    int n = mm; // sizeof(a) / sizeof(a[0]);
    prtArr(a, n);
    countSort(a, n);
    prtArr(a, n);
    free(a);
	return 0;
}