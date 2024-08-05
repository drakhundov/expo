#define NUMBER '0'
#define SINUS 's'
#define COSINUS 'c'

int getch(void);
void ungetch(int);

int getop(char[]);

void push(double);
double pop(void);

int is_opp(char);
