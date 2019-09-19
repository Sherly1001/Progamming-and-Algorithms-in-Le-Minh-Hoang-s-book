#include <stdio.h>

void insertSort(int *a, const int n) {
    for (int i = 1; i < n; i++) {
        int t = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > t) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = t;
    }
}

void prtArr(const int *a, const int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {1, 3, 2, 5, 3, 2, 5, 0};
    int n = sizeof(a) / sizeof(a[0]);
    prtArr(a, n);
    insertSort(a, n);
    prtArr(a, n);
    return 0;
}