// getint: 接受自由格式的输入，并执行转换，将输入的字符流分解成整数，且每次调用得到一个整数。
// return: 返回转换后得到的整数，并且，在到达输入结尾时要返回文件结束标记。
// design: 将标识是否到达文件结尾的状态作为getint函数的返回值，
//         同时，使用一个指针参数存储转换后得到的整数并传回给主调函数。----> scanf()

# include <ctype.h>
# include <stdio.h>

/* getch */
# define BUFSIZE 100
static char buf[BUFSIZE];  // a buffer used by ungetch()
static int bufp = 0;      // next free address in buf[]
int getch(void);
void ungetch(int);

/* getint() */
int getint(int *pn);


// test: 调用getint给整型数组赋值
# define SIZE 10
int main()
{
    int n, array[SIZE], getint(int *);

    for(n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        ;
    
    // print array
    for(int i = 0; i < SIZE; i++)
        printf("%d ", array[i]);

    return 0;
}


// getint: Assign the next integer number entered to *pn
// 函数在到达文件结尾时返回EOF，当下一个输入不是数字时返回0，
// 当输入中包含一个有意义的数字时返回一个正值
int getint(int *pn )
{
    int c, sign;

    while(isspace(c = getch())) // skip space
        ;

    if(!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);   // invalid input
        return 0;     
    }

    sign = (c == '-') ? -1 : 1;
    if(c == '+' || c == '-')
        c = getch();

    for(*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * (*pn) + (c - '0');
    }
    
    *pn *= sign;
    if(c != EOF)
        ungetch(c);
    return c;
}


// get a char from buf or next input
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

// push a char to buf
void ungetch(int c)
{
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters.\n");
    else
        buf[bufp++] = c;
}