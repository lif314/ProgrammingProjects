// 通过指针扩展strlen()，使其适合多种数据形式

# include <stdio.h>

int Strlen(char *s)
{
    int n;

    for(n = 0; *s != '\0'; s++)
        n++;
    return n;
}


int Strlength(char *s)
{
    char *p = s;
    while(*p != '\0')
        p++;
    return p - s;
}

// test
int main()
{
    char *ptr = "Hello World!";
    char s[] = "Hello C!";
    printf("%d %d %d", Strlen(ptr), Strlen(s), Strlen("Hello "));
    return 0;
}