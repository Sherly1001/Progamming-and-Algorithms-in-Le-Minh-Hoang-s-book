#include "i2p.h"

int priority(const char c) {
    switch (c) {
    case '(':
        return 0;
    case '+': case '-':
        return 1;
    case '*': case '/':
        return 2;
    case '%':
        return 3;
    case '^':
        return 4;
    }
}

void infix2postfix(char *postfix, const char *infix) {
    int len = strlen(infix), j = 0;
    
    char *temp = (char*)malloc(2 * len * sizeof(char));
    for (int i = 0; i < len; i++) {
        if (infix[i] != ' ') {
            if ((infix[i] == '-' || infix[i] == '+') && !isdigit(temp[j - 1]) && !isalpha(temp[j - 1])) {
                temp[j++] = '(';
                temp[j++] = '0';
                do {
                    temp[j++] = infix[i++];
                } while (isdigit(infix[i]) || isalpha(infix[i]));
                temp[j++] = ')';
                temp[j++] = infix[i];
            } else
                temp[j++] = infix[i];

        }
    }
    temp[j] = '\0';
    len = j;
    j = 0;
    stack *st = NULL;
    char x = '\0';
    for (int i = 0; i < len; i++) {
        switch (temp[i]) {
        case '(':
            push(&st, temp[i]);
            break;
        case ')':
            do {
                x = pop(&st);
                if (x != '(') {
                    postfix[j++] = x;
                    postfix[j++] = ' ';
                }
            } while (x != '(');
            break;
        case '+': case '-': case '*': case '/': case '%': case '^':
            while (st && priority(temp[i]) <= priority(back(st))) {
                postfix[j++] = pop(&st);
                postfix[j++] = ' ';
            }
            push(&st, temp[i]);
            break;
        default:
            postfix[j++] = temp[i];
            if (!isdigit(temp[i + 1]) && !isalpha(temp[i + 1]))
                postfix[j++] = ' ';
        }
    }
    do {
        if (back(st) != '(') {
            postfix[j++] = pop(&st);
            postfix[j++] = ' ';
        }
        else
            pop(&st);
    } while (st);
    postfix[j] = '\0';
    free(temp);
}
