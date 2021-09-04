# include <stdio.h>
# include <string.h>

// reverse each charactor in s
void Reverse(char s[])
{
    int c, i, j;

    for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

// int ----> char
void itoa(int n, char s[])
{
    int i, sign;

    if((sign = n) < 0)  // record flag
        n = -n;         // n > 0

    i =  0;
    do
    {
        s[i++] = n % 10 + '0';
    } while ((n /= 10) > 0);

    if(sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    Reverse(s);
}


// test
int main()
{
    int n = -2442;
    char *s;
    itoa(n, s);
    printf("s=%s", s);
    return 0;
}