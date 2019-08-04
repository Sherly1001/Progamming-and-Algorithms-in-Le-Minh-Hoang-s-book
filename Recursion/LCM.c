#include <stdio.h>

int lcm(int a, int b) {
    if (a < b) return lcm(b, a);
    if (b <= 0) return a; // section anchor
    else return lcm(b, a % b); // recursion
}

int main() {
    int a = 0, b = 0;
    scanf("%d %d", &a, &b);
    printf("%d\n", lcm(a, b));
    return 0;
}

