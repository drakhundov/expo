#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "calc.h"

#define MAXOP 100

int is_opp(char);

/* Polish calculator */

int main(int argc, char *argv[]) {
	int type;
    double op2;
    char s[MAXOP];

    if(argc > 1) { // expression given as argument
        argv += argc;

        ungetch(EOF);
        ungetch('\n');

        while(--argc > 0 && --argv) {
            strrev(argv[0]);

            if(isdigit(*argv[0])) {
                while(*argv[0]) {
                    ungetch(*argv[0]++);
                }
            } else if(is_opp(*argv[0])) {
                ungetch(*argv[0]);
            }

            ungetch(' ');
        }
    }

    while((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;

            case '+':
                push(pop() + pop());
                break;

            case '-':
                op2 = pop();
                push(pop() - op2);
                break;

            case '*':
                push(pop() * pop());
                break;

            case '/':
                op2 = pop();

                if(op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("error: zero division\n");
                }

                break;

            case '^':
                op2 = pop();
                push(pow(pop(), op2));
                break;

            case '%':
                op2 = pop();
                push(fmod(pop(), op2));
                break;

            case SINUS:
                push(sin(pop()));
                break;

            case COSINUS:
                push(cos(pop()));
                break;

            case '\n':
                printf("%g\n", pop());
                break;

            default:
                printf("error: unknown operand\n");
        }
    }

	return 0;
}

int is_opp(char c) {
    switch(c) {
        case '+':
        case '-':
        case '/':
        case '*':
        case '^':
        case '%':
        case SINUS:
        case COSINUS:
            return 1;

        default:
            return 0;
    }
}
