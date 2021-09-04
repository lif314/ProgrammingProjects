// stack: push(), pop()
# include <stdio.h>
# include "calc.h"
# define MAXVAL 100

static int sp = 0;     // next free stack area
static double val[MAXVAL];

// push a val to val[]
void push(double f)
{
    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}


// pop a val from val[]
double pop(void)
{
    if(sp > 0)
        return val[--sp];
    else
    {
        printf("error: stack empty.\n");
        return 0.0;
    }
}