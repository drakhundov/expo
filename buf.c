#include <stdio.h>
#include "calc.h"

#define BUFSIZE 80

static int bp = 0; // next buffer position
static char buf[BUFSIZE];

int getch(void) {
    return (bp > 0) ? buf[--bp] : getchar();
}

void ungetch(int c) {
    if(bp + 1 >= BUFSIZE) {
        printf("error: buffer is full\n");
    } else {
        buf[bp++] = c;
    }
}
