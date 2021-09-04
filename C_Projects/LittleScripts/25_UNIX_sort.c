// KEY: 指针数组与指向指针的指针


// 按字母顺序对由文本行(长度不同)组成的集合进行排序 --- 指针数组
/*
* 读取所有行         ---- readlines()
* 对文本行进行排序    ---- qsort()   
* 按次序打印文本行    ---- writelines()
*/

# include <stdio.h>
# include <string.h>

#define MAXLINES 5000 // 进行排序的最大文本行数

char *lineptr[MAXLINES]; // 指向文本行的指针数组

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(char *lineptr[], int left, int right);

/* 对输入的文本进行排序 */
int main()
{
    int nlines;  // 读取的输入行书目

    if((nlines = readlines(lineptr, MAXLINES)) >= 0){
        printf("\nINPUT:\n");
        writelines(lineptr, nlines);
        printf("\nSort: ......\n");
        qsort(lineptr, 0, nlines - 1);
        printf("\nOUTPUT:\n");
        writelines(lineptr, nlines);
        return 0;
    }else{
        printf("error: input too big to sort\n");
        return 1;
    }
}


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


/* swap(): 交换v[i]和v[j] */
void swap(char *v[], int i, int j)
{
    char *temp;

    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

/* qsort()：按递增顺序排序 */
void qsort(char *v[], int left, int right)
{
    int i, last;
    void swap(char *v[], int i, int j);

    if(left >= right) /* 如果数组元素的个数小于2，则返回 */
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for(i = left + 1; i <= right; i++)
    {
        if(strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    }

    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}