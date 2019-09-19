#include <stdio.h>

void bubbleSort(int *a, int n) {
    for (int i = 1; i < n; i++)
        for (int j = n - 1; j >= i; j--)
            if (a[j] < a[j - 1]) {
                int t = a[j];
                a[j] = a[j - 1];
                a[j - 1] = t;
            }
}

void prtArr(const int *a, const int n) {
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
}

int main() {
    int a[] = {1, 3, 4, 5, 2, 3, 4};
    int n = sizeof(a) / sizeof(a[0]);
    prtArr(a, n);
    bubbleSort(a, n);
    prtArr(a, n);
    return 0;
}