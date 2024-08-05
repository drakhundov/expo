#include <stdio.h>
#include "calc.h"

#include <string.h>
#include <ctype.h>

int getop(char s[]) {
    int c;
    int i, sign;
    
    i = 0;

    while((s[0] = c = getch()) == ' ' || c == '\t');
    
    if(!isdigit(c) && !isalpha(c) && c != '.' && c != '-') {
        return c; // NAN (not a number)
    }

    // maybe it's negative num
    if(c == '-') {
        c = s[++i] = getch();

        if(!isdigit(c) && c != '.') {
            ungetch(c);
            return s[i-1];
        } 
    }
    
    // maybe it's sin or cos
    if(isalpha(c)) {
        while(isalpha(c = s[++i] = getch()));
        s[--i] = '\0';

        ungetch(c);

        if(strcmp(s, "sin")) {
            return SINUS;
        } else if(strcmp(s, "cos")) {
            return COSINUS;
        } else {
            return '\0';
        }
    }

    if(isdigit(c)) {
        // collect integer part
        while(isdigit(s[++i] = c = getch()));
    }

    if(c == '.') {
        // collect fraction part
        while(isdigit(s[++i] = c = getch()));
    }

    s[i] = '\0';

    ungetch(c);

    return NUMBER;
}
