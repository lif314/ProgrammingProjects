// 指向函数的指针

// 排序函数：给定可选参数-n的情况下，按照数值大小排序而非字典顺序
// 通过在算法中调用不同的比较和交换函数，则可以实现按照不同标准的排序

/*
* strcmp(): 按照字典排序
* numcmp(): 按照数值排序
* 传给qsort()函数调用
*/


# include <stdio.h>
# include <string.h>
# include <stdlib.h> // atof()

#define MAXLINES 5000 // 待排序的最大行数
char *lineptr[MAXLINES]; // 指向文本的指针

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void quicksort(void *lineptr[], int left, int right, int (*comp)(void *, void *));

int numcmp(char *, char *);

/* 对输入的文本进行排序 */
int main(int argc, char *argv[])
{
    int nlines;   // 读入的输入行数
    int numeric = 0; // 若进行数值排序，则numeric的值为1

    if(argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;

    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        quicksort((void **) lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    }else{
        printf("input too big to sort\n");
        return 1;
    }
}

/* 按值顺序比较字符串 */
int numcmp(char *s1, char *s2)
{
    double v1, v2;

    v1 = atof(s1);
    v2 = atof(s2);

    if(v1 < v2)
        return -1;
    else if(v1 > v2)
        return 1;
    else
        return 0;
}


/* swap() */
void swap(void *v[], int i, int j)
{
    void * temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}


// qsort()
void quicksort(void *v[], int left, int right, int (*comp)(void *, void *))
{
    int i, last;
    void swap(void *v[], int, int);

    if(left >= right) /* 如果数组元素的个数小于2，则返回 */
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; i++)
    {
        if((*comp)(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }

    swap(v, left, last);
    quicksort(v, left, last - 1, comp);
    quicksort(v, last + 1, right, comp);
}

/*
* int (*comp)(void *, void *): comp是一个指向函数的指针，具有两个void*类型的参数，返回值为int
* (*comp)(v[i], v[left]) < 0: comp是指向函数的指针，则*comp代表一个函数本身，括号是必须的
*/



# define MAXLEN 1000  /* 每个输入文本的最大长度 */
int getLine(char *line, int maxlen);
char *alloc(int n);

/* readlines(): 读取输入行 */
int readlines(char *lineptr[], int maxlines)
{
    int  len, nlines;
    char *p, line[MAXLEN];

    nlines =  0;
    while((len = getLine(line, MAXLEN)) > 0)
        if(nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else{ 
            line[len - 1] = '\0';  /* 删除换行符 */
            strcpy(p, line);
            lineptr[nlines++] = p;
        }

    return nlines;
}


/* writelines()：写输入行 */
void writelines(char *lineptr[], int nlines)
{
    int i;

    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}


/* 
void writelines(char *lineptr[], int nlines)
{
    while(nlines-- > 0)
        printf("%s\n", *lineptr++);
}
*/


/* alloc()  getline()  */
# define ALLOCSIZE 10000  /* free space size */

static char allocbuf[ALLOCSIZE];  /* store area used by alloc() */
static char *allocp = allocbuf;   /* next free sapce */

// return a pointer that points n chars
char *alloc(int n)
{
    if(allocbuf + ALLOCSIZE - allocp >= n){ // enough space
        allocp += n;
        return allocp - n; 
    } else
        return NULL;
}

// free the space that p point
void afree(char *p)
{
    if(p >= allocbuf && p < allocbuf + ALLOCSIZE)
        allocp = p;
}

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