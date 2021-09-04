# define ALLOCSIZE 1000  /* free space size */

static char allocbuf[ALLOCSIZE];  /* store area used by alloc() */
static char *allocp = allocbuf;   /* next free sapce */

// return a pointer that points n chars
char *alloc(int n)
{
    if(allocbuf + ALLOCSIZE - allocp >= n){ // enough space
        allocp += n;
        return allocp - n; 
    } else
        return 0;
}


// free the space that p point
void afree(char *p)
{
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}