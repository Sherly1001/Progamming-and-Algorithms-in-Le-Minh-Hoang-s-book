#ifndef __i2p__
#define __i2p__

#include <string.h>
#include <ctype.h>
#include "mystack.h"

int priority(const char c);
void infix2postfix(char *postfix, const char *infix);

#endif