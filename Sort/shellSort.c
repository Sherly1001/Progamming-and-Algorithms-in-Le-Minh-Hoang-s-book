#include <stdio.h>
#include <stdlib.h>


void shellSort(int *a, int n) {
    int h = n / 2;
    while (h != 0) {
        for (int i = h; i < n; i++) {
            int t = a[i], j = i - h;
            while (j >= 0 && a[j] > t) {
                printf("%d->%d\n", j, j + h);
                a[j + h] = a[j];
                j -= h;
            }
            a[j + h] = t;
        }
        h /= 2;
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
    shellSort(a, n);
    prtArr(a, n);
    return 0;
}