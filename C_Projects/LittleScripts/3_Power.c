# include <stdio.h>

// power(m,n)
int power(int m, int n);

// test power(m,n)
int main()
{
    for(int i = 0; i < 10; ++i)
    {
        printf("%d %d %d\n", i, power(2, i), power(-3, i));
    }

    return 0;
}

// power(m, n) = m^n
int power(int base, int n)
{
    if(base == 0)
    {
        return EOF;
    }
    if (n == 0 && base != 0)
        return 1;

    int r = 1;
    for(int i = 1; i <= n; ++i)
        r *= base;

    return r;
}