/* Unix 模式查找程序 -- grep | find */

# include <stdio.h>
# include <string.h>
# define MAXLINE 100

int getLine(char *s, int max);

/* find(): 打印第一个参数指定的模式匹配的行 */
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    int found = 0;

    if(argc != 2)
        printf("Usage: find pattern\n");
    else
        while(getLine(line, MAXLINE) > 0)
        {
            if(strstr(line, argv[1]) != NULL){
                printf("%s", line);
                found++;
            }
        }
    return found;
}

/* strstr() --- string.h */
/*
*   strstr(s,t)返回一个指针，该指针指向字符串t在字符串s中第一次出现的位置；
*   如果t没有在s中出现，则返回NULL
*/

// Read a line in s, and return the length
// lim : the limit of the length of a line
// 0 is the return value that marks the end of the file
// The length of a line containing only newlines is 1
int getLine(char *s, int lim)
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