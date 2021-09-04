# include <stdio.h>

// Type conversion

// char ---> int
int atoi(char s[])
{
    int i, n;
    
    n = 0;
    for(i = 0; s[i] > '0' && s[i] < '9'; ++i)
        n = 10 * n + (s[i] - '0');

    return n;
}

// lower
int lower(int c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 'a' - 'A';
    else
        return c;
}