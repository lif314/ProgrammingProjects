// Numbers are generated in reverse order
// 1. store in a array
// 2. Recursion

# include <stdio.h>

/* printd: print n */
void printd(int n)
{
    if(n < 0){
        putchar('-');
        n = -n;
    }
    if( n / 10)
        printd(n / 10);
    putchar(n % 10 + '0'); 
}

// test main
int main()
{
    int x;
    scanf("%d", &x);
    printd(x);
    return 0;
}