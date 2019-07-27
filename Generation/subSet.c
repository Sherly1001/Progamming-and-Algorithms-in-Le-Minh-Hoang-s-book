#include <stdio.h>

void subSet(int* set, int n, int k) {
    if (n <= 0 || k <= 0 || k > n) return;
    char *x = (char*)calloc(n, 1);
    for (int i = 0; i < k; i++) x[i] = i;
    while (1) {
        printf("{");
        for (int i = 0; i < k - 1; i++) printf("%d, ", set[x[i]]);
        printf("%d}\n", set[x[k - 1]]);
        int i = k - 1;
        // x[k] <= n
        // x[k - 1] <= n - 1
        // k - 1 = i
        // -1 = i - k
        // x[i] <= n -k + i
        while (x[i] == n - k + i && i >= 0) i--;
        if (i < 0) break;
        x[i]++;
        for (int j = i + 1; j < k; j++)
            x[j] = x[j - 1] + 1;
    }
    free(x);
}

int main() {
    int set[] = {1, 2, 3, 4, 5};
    int n = sizeof(set) / sizeof(set[0]);
    int k = 0;
    scanf("%d", &k);
    subSet(set, n, k);
    return 0;
}
