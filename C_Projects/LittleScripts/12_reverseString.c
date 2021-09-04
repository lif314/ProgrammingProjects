# include <stdio.h>
# include <string.h>


// reverse each charactor in s
void reverse(char s[])
{
    int c, i, j;

    for(i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

// test
int main()
{
    char s[] = "Hello World!";
    printf("old: %s\n", s);
    reverse(s);
    printf("rev: %s", s);
    return 0;
}