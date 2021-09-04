// simple grep: 简单模式匹配
/*
* while(还有未处理的行)
*   if(该行包含指定的模式)
*       打印该行
*/

# include <stdio.h>
# define MAXLINE 1000 // max length of an input line

int getLine(char s[], int max); // read a line
int strindex(char source[], char searchfor[]); // search searchfor[] in source[]

char pattern[] = "ould";  // searchfor[]

int main()
{
    char line[MAXLINE];
    int found = 0;

    while(getLine(line, MAXLINE) > 0)
    {
        if(strindex(line, pattern) >= 0)
        {
            printf("%s", line);
            found++;
        }
    }

    printf("Total found: %d", found);

    return 0;
}

// Read a line
int getLine(char s[], int lim)
{
    int c; // char

    int i = 0;
    while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if(c == '\n')
        s[i++] = c;

    s[i] = '\0';
    return i;
}

// simple grep
int strindex(char s[], char t[])
{
    int i, j, k;

    for(i = 0; s[i] != '\0'; i++)
    {
        for(j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if(k > 0 && t[k] == '\0')
            return i;
    }

    return -1;
}