#include <stdio.h>

int nCk(int n, int k) {
    if (n < 0 || k < 0 || k > n) return -1;
    if (k > n / 2) return nCk(n, n - k);
    if (k == 0 || k == n) return 1;
    else return nCk(n - 1, k - 1) + nCk(n - 1, k);
}

int main() {
    int n = 0, k = 0;
    scanf("%d %d", &n, &k);
    printf("%d\n", nCk(n, k));
    return 0;
}

