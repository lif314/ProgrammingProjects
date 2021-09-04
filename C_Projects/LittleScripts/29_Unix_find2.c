/* find 多个可选参数 */
/* Unix:
* 以符号-开头的参数表示一个可选标识
* -x: 表示打印所有与模式不匹配的文本行
* -n: 打印行号
*/

/*
* find -x -n 模式：打印所有与模式不匹配的行号，并在每个打印行的前面加上行号
* find -xn: 可选参数可以组合使用
*/

# include <stdio.h>
# include <string.h>
# define MAXLINE 1000

int getLine(char *line, int max);

/* find(): 打印第一个参数指定的模式匹配的行 */
int main(int argc, char *argv[])
{
    char line[MAXLINE];
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;

    /* 参数解析 */
    /* 
    * argc执行自减运算，argv执行自增运算，循环结束时，如果没有错误，
    * 则argc的值表示还没有处理的参数数目，argv表示指向未处理参数中的第一个参数
    * 因此，此时argc=1,而*argv指向模式
    * 
    * *++argv是一个指向参数字符串的指针，因此(*++argv)[0]是它的第一个字符,等价于**++argv
    * 括号是必须的，因为[]与操作数的结合优先级比*和++高
    * 
    * *++argv[0] == *++(argv[0]): 遍历特定的参数串，即遍历参数串argv[0]
    */
    while(--argc > 0 && (*++argv)[0] == '-')
        while(c = *++argv[0])
            switch(c){
                case 'x':
                    except = 1;
                    break;
                case 'n':
                    number = 1;
                    break;
                default:
                    printf("find: illegal option %c\n", c);
                    argc = 0;
                    found = -1;
                    break;
            }

    // 实现参数
    if(argc != 1)
        printf("Usage: find -x -n pattern\n");
    else
        while(getLine(line, MAXLINE) > 0){
            lineno++;
            if((strstr(line, *argv) != NULL) != except){
                if(number)
                    printf("%ld: ", lineno);
                printf("%s", line);
                found++;
            }
        }
    return found++;
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