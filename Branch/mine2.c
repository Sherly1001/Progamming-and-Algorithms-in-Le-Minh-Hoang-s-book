#include <stdio.h>
#include <stdlib.h>

const int hor[] = {-1, -1, -1, 0, 0, 1, 1, 1};
const int ver[] = {-1, 0, 1, -1, 1, -1, 0, 1};

void printResult(int** mine, int m, int n) {
    printf("\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mine[i][j]);
        printf("\n");
    }
}

int possible(int** board, int** mine, int m, int n, int j) {
    int count = 0;
    for (int i = 1; i < m; i++) {
        count = 0;
        mine[i][j] = 0;
        for (int k = 0; k < 8; k++)
            if (i - 1 + hor[k] >= 0 && j - 1 + ver[k] >= 0 && i - 1 + hor[k] < m && j - 1 + hor[k] < n)
                count += mine[i - 1 + hor[k]][j - 1 + ver[k]];
        switch (board[i - 1][j - 1] - count) {
        case 1:
            mine[i][j] = 1;
            break;
        case 0:
            mine[i][j] = 0;
            break;
        default:
            return 0;
        }
    }
    // return 1;
}

void tryHor(int** board, int** mine, int m, int n, int i) {
    if (i == n)
        printResult(mine, m, n);
    else
        for (int j = 0; j < 2; j++) {
            mine[0][i] = j;
            if (possible(board, mine, m, n, i))
                tryHor(board, mine, m, n, i + 1);
        }
}

void tryVer(int** board, int** mine, int m, int n, int i) {
    if (i == m)
        tryHor(board, mine, m, n, 1);
    else
        for (int j = 1; j >= 0; j--) {
            mine[i][0] = j;
            tryVer(board, mine, m, n, i + 1);
        }
}

void mineWeeep() {
    int m = 0, n = 0;
    scanf("%d %d", &m, &n);
    if (m < 2 || n < 2)
        return;
    int** mine = (int**)calloc(m, sizeof(int*));
    int** board = (int**)calloc(m, sizeof(int));
    for (int i = 0; i < m; i++) {
        *(mine + i) = (int*)calloc(n, sizeof(int));
        *(board + i) = (int*)calloc(n, sizeof(int));
    }
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &board[i][j]);
    tryVer(board, mine, m, n, 0);
    for (int i = 0; i < m; i++) {
        free(*(mine + i));
        free(*(board + i));
    }
    free(board);
    free(mine);
}

int main() {
    mineWeeep();
    return 0;
}