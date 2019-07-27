#include <stdio.h>

void bin(int n) {
    if (n <= 0) return;
    char s[100] = {0};
    while (1) {
        for (int i = 0; i < n; i++) printf("%d", s[i]);
        printf("\n");
        int i = n - 1;
        while (s[i] != 0 && i >= 0) i--;
        if (i < 0) break;
        s[i] = 1;
        for (int j = i + 1; j < n; j++) s[j] = 0;
    }
}

int main() {
    int n = 0;
    scanf("%d", &n);
    bin(n);
    return 0;
}