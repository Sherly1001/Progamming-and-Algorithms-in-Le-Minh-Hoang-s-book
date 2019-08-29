
#include "mystack.h"
#include "i2p.h"

int main() {
    char in[100];
    char ou[100] = "";
    scanf("%s", in);
    infix2postfix(ou, in);
    printf("%s -> %s\n", in, ou);
    return 0;
}
