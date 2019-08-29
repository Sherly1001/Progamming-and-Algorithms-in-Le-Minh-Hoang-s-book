#include "mystack.h"
#include "i2p.h"

int isOp(const char c);
int caculate(const char *in);

int main() {
    char s[100];
    scanf("%[^\n]s", s);
    printf("%d\n", caculate(s));
    return 0;
}

int caculate(const char *in) {
    int len = strlen(in);
    char *po = (char*)malloc(len * 2 * sizeof(char));
    infix2postfix(po, in);
    len = strlen(po);
    stack *st = NULL;

    for (int i = 0; i < len; i++) {
        char res[10] = ""; int j = 0, num = 0, x = 0, y = 0, temp = 1;
        while (po[i] != ' ' && i < len) {
            res[j++] = po[i++];
        }

        if (j > 1 || !isOp(res[0])) {
            for (int k = 0; k < j; k++) {
                num = 10 * num + res[k] - '0';
            }
            push(&st, num);
        } else {
            y = pop(&st);
            x = pop(&st);
            switch (res[0]) {
                case '+': x += y; break;
                case '-': x -= y; break;
                case '*': x *= y; break;
                case '/': x /= y; break;
                case '^': 
                    for (int k = 0; k < y; k++)
                        temp *= x;
                    x = temp;
                break;
                case '%': x %= y; break;
            }
            push(&st, x);
        }
    }
    free(po);
    return pop(&st);
}

int isOp(const char c) {
    if (c == '+' || c == '-' || c == '*' || c == '/' || c == '%' || c == '^')
        return 1;
    return 0;
}