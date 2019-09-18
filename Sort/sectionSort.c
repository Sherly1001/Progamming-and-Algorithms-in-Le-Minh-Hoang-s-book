#include <stdio.h>

void sectionSort(int *a, int n) {
    for (int i = 0; i < n - 1; i++) {
        int imin = i + 1;
        for (int j = i + 1; j < n; j++)
            if (a[imin] > a[j]) imin = j;
        if (a[imin] < a[i]) {
            int t = a[i];
            a[i] = a[imin];
            a[imin] = t;
        }
    }
}

void prtArr(const int *a, const int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {1, 3, 2, 5, 3, 2, 5, 4};
    int n = sizeof(a) / sizeof(a[0]);
    prtArr(a, n);
    sectionSort(a, n);
    prtArr(a, n);
    return 0;
}