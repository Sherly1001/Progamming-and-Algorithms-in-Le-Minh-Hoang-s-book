#include <stdio.h>

void move(int n, int x, int y) {
    static int count = 0;
    if (n == 1) printf("%d: Move a disk from stake %d to stake %d\n", ++count, x, y);
    else {
        move(n - 1, x, 6 - x - y); // move n - 1 disks form stake x to stake z
        move(1, x, y); // move the biggest disk form stake x to stake y
        move(n - 1, 6 - x - y, y); // move n - 1 disks from stke z to stake y
    }
}

int main() {
    int n = 0, x = 1, y = 2;
    scanf("%d", &n);
    if (n <= 0 || x <= 0 || x > 3 || y <= 0 || y > 3) return 0;
    move(n, x, y);
    return 0;
}
