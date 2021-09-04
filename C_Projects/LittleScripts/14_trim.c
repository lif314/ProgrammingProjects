# include <stdio.h>
# include <string.h>

// trim(): Delete spaces, tabs, and newlines at the end of the string
int trim(char s[])
{
    int n;
    for(n = strlen(s) - 1; n >= 0; n--)
    {
        if(s[n] != '\n' && s[n] != ' ' && s[n] != '\t')
            break;
    }

    s[n+1] = '\0';  // delete !!!!
    return n;
}


// test
int main()
{
    char s[] = "Hello World     \t  \n   ";
    printf("%d, %s", trim(s), s);
    return 0;
}