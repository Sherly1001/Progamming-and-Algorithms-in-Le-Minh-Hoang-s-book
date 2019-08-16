#include "myqueue.h"
#include <string.h>

void moveWT(int n) {
    if (n < 1) return;
    int *a = (int*)malloc(n * sizeof(int));
    int *c = (int*)malloc(n * sizeof(int));
    queue *b = NULL;
    char s[1000] = "";
    int k = 0;

    for (int i = 1; i <= n; i++) a[i - 1] = i;
    printf("\nEnter permutations you desire to get: ");
    for (int i = 0; i < n; i++) scanf("%d", &c[i]);

    for (int i = 0; i < n; i++) {
        int temp = b ? b->val : 0;
        if (temp && temp == c[i]) {
            pop(&b);
            strcat(s, "B->C\n");
            continue;
        }
        while (c[i] != a[k] && k < n) {
            push(&b, a[k++]);
            strcat(s, "A->B\n");
        }
        if (k == n) {
            s[0] = '\0';
            break;
        } else if (c[i] == a[k]) {
            strcat(s, "A->C\n");
            k++;
        }
    }
    if (s[0]) printf("%s", s);
    else printf("\nDon't have this permutation\n");
}

int main() {
    int n = 0;
    printf("Enter number of wagon trains: ");
    scanf("%d", &n);
    moveWT(n);
    return 0;
}