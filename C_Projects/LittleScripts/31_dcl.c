/*
* int *f(): f是一个函数，返回一个指向iint的指针
* int (*pf)(): pf是一个指向函数的指针，该函数返回一个int类型的对象
* *是一个前缀运算符，其优先级低于()
*/

/* dcl: 将c语言声明转换为文字描述 */
// eg: char **argv --- argv: pointer to pointer to char
// eg: char(*(*x[3])())[5] --- x: array[3] of pointer to function returning pointer to array[5] of char

// core: dcl() dirdcl() ---- 根据声明符的语法对声明进行分析
// 因为语法是递归定义的，所以在识别一个声明的组成部分时，这两个函数也是相互递归调用的。
// 称该程序为一个递归下降语法分析程序


# include <stdio.h>
# include <string.h>
# include <ctype.h>

# define MAXTOKEN 100

enum {NAME, PARENS, BRACKETS};

void dcl(void);
void dirdcl(void);


// test
int main()
{

}


/* dcl(): 对一个声明符进行语法分析 */
void dcl(void)
{
    int ns;

    for (ns = 0; gettoken() == '*';) /* 统计字符的个数 */
        ns++;
    dirdcl();
    while(ns-- > 0)
        strcat(out, " pointer to");
}

/* dirdcl(): 分析一个直接声 */
void dirdcl(void)
{
    int type;

    if(tokentype == '('){   /* 形式为(dcl) */
        dcl();
        if(tokentype != ')')
            printf("error: missing )\n");
    }else if (tokentype == NAME)
        strcpy(name, token);
    else
        printf("error: excepted name or (dcl)\n");

    while((type = gettoken()) == PARENS || type == BRACKETS)
        if (type == PARENS)
            strcat(out, " function returning");
        else{
            strcat(out, " array");
            strcat(out, token);
            strcat(out, " of");
        }
}