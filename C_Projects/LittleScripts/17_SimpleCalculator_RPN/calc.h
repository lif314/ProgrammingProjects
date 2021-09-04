// share memory
// For some medium-scale programs, it is best to use only one header file 
// to store objects shared by all parts of the program.

#define NUMBER '0'

/* stack.c */
void push(double);
double pop(void);

/* getop.c */
int getop(char []);

/* getch() */
int getch(void);
void ungetch(int);