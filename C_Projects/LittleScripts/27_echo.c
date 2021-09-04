// 命令行参数
/*
* argc: 用于参数计数，表示运行时命令行中参数的数目
* agrv: 用于参数向量，指向字符串数组的指针，其中每个字符串对应一个参数   ---> 多级指针
*/

// eg: echo hello, world
// C语言中:
/*
* argv[0]: 启动程序的程序名，因此argc至少为1
* argv[1...]: 参数,字符串数组指针
* argv[argc] 必须是一个空指针
*/

# include <stdio.h>

// echo 1： argv看成一个字符指针数组
int echo1(int argc, char *argv[])
{
    int i;

    for(i = 1; i < argc; i++)
        printf("%s%s", argv[i], (i < argc -1) ? " " :"");
    printf("\n");
    return 0;
}

// echo2: argv看作是指向char类型的指针的指针
int echo2(int argc, char *argv[])
{
    while(--argc > 0)
        printf("%s%s", *++argv, (argc > 1)? " " : "");  // == printf((argc > 1) ? "%s " : "%s", *++argv);  printf()的格式化参数可以是表达式
    printf("\n");
    return 0;
}


// test
int main(int argc, char *argv[])
{
    return echo1(argc, argv);
}