#include <stdio.h>
#include "calc.h"

#define STACKSIZE 100

static int sp = 0; // next stack position
static double stack[STACKSIZE];

void push(double f) {
    if(sp < STACKSIZE) {
        stack[sp++] = f;
    } else {
        printf("error: stack is full\n");
    }
}

double pop(void) {
    if(sp > 0) {
        return stack[--sp];
    } else {
        printf("error: stack is empty\n");
        return 0.0;
    }
}
