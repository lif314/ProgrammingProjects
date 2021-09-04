// getch()   ungetch()

# include <stdio.h>
# define BUFSIZE 100
static char buf[BUFSIZE];  // a buffer used by ungetch()
static int bufp = 0;      // next free address in buf[]

// get a char from buf or next input
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// push a char to buf
void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters.\n");
    else
        buf[bufp++] = c;
}