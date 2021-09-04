// getop()

# include <stdio.h>
# include <ctype.h>
# include "calc.h"

// get next op or digit
int getop(char s[])
{
    int i, c;
    while((s[i] = c = getch()) == ' ' || c == '\t')
        ;
    s[i] = '\0';
    if(!isdigit(c) && c != '.')   // not a digit
        return c;
    
    i = 0;
    if(isdigit(c)) // int part
        while(isdigit(s[++i] = c = getch()))
            ;
    
    if(c == '.')  // float part
        while(isdigit(s[++i] = c = getch()))
            ;
    
    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    
    return NUMBER;
}