# include <stdio.h>
# define MAXLINE 1000 // Maximum length of the allowed input line

// Read in a set of text and print the longest line of text


int getLine(char line[], int maxline);
void copy(char to[], char from[]);

// print the longest input line
int main()
{
    int currentLen;          // the length current length
    int max;                 // The longest line length found so far
    char line[MAXLINE];      // current input line
    char longest[MAXLINE];   // save the longest line

    max = 0;
    while((currentLen = getLine(line, MAXLINE)) > 0)
    {
        if(currentLen > max)
        {
            max = currentLen;
            copy(longest, line);
        }
    }

    if(max > 0)
    {
        printf("%s", longest);
    }

    return 0;
}


// Read a line in s, and return the length
// lim : the limit of the length of a line
// 0 is the return value that marks the end of the file
// The length of a line containing only newlines is 1
int getLine(char s[], int lim)
{
    int c; // char
    int i;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        s[i] = c;
    }
    if(c == '\n')
    {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';  // flag of end
    return i;
}


// copy: from[] ----> to[] 
// Save the longest line
void copy(char to[], char from[])
{
    int i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}