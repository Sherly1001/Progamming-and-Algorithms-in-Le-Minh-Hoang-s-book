#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void prtArr(const int *a, const int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

void adjust(int *arr, int r, int n) {
    int k = arr[r];
    int c = 0;
    while (r * 2 < n) {
        c = r * 2;
        if (c < n - 1 && arr[c] < arr[c + 1]) ++c;
        if (arr[c] <= k) break;
        arr[r] = arr[c];
        r = c;
    }
    arr[r] = k;
}

void swap(int *a, int *b) {
    // static int i = 0;
    // printf("swaped %d\n", ++i);
    int t = *a; *a = *b, *b = t;
}

void heapSort(int *arr, int n) {
    for (int r = n / 2; r >= 0; --r) adjust(arr, r, n);
    for (int i = n - 1; i > 0; --i) {
        swap(&arr[0], &arr[i]);
        adjust(arr, 0, i - 1);
    }
}


int main() {
    srand(time(NULL));
    int mm = 10;
    // int a[] = {1, 3, 2, 5, 3, 2, 5, 4};
    int *a = (int*)malloc(sizeof(int) * mm);
    for (int i = 0; i < mm; i++) a[i] = rand() % mm;
    int n = mm; // sizeof(a) / sizeof(a[0]);
    prtArr(a, n);
    heapSort(a, n);
    prtArr(a, n);
    free(a);
    return 0;
}