// 日期转换

// 二位数组：由行向量组成的一维数组
// 作为参数必须指明列数
// f(int daytab[2][13])  == f(int daytab[][13]) == f(int (*daytab)[13])
// !!!   int (*daytab)[13] !=  int *daytab[13]
// int (*daytab)[13]: 参数是一个指向具有13个整型元素的一维数组
// int *daytab[13]: 一个具有13个指向整型对象的指针的一维数组


# include <stdio.h>

// 在char类型中存放非字符整数是合法的
static char daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30},
    {0, 31, 29, 31, 30, 31, 30, 31, 30, 31, 30, 31, 30}   // 闰年
};

int day_of_year(int year, int month, int day);
void  month_day(int year, int yearday, int *pmonth, int *pday);

// test
int main()
{
    printf("year month day ---> yearday: ");
    int year, month, day;
    scanf("%d %d %d", &year, &month, &day);
    printf("yearday: %d\n", day_of_year(year, month, day));

    printf("year yearday ---> mongth day:");
    int year1, yearday1;
    scanf("%d%d", &year1, &yearday1);
    int pmonth, pday;
    month_day(year1, yearday1, &pmonth, &pday);
    printf("month:%d day:%d", pmonth, pday);

    return 0;
}


/* 将某月某日的日期转换为某年中的第几天 */
int day_of_year(int year, int month, int day)
{
    int i, leap;
    
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for(i = 1; i < month; i++)
    {
        day += daytab[leap][i];
    }

    return day;
}

/* 将某年的第几天的日期表示形式转换为某月某日的形式 */
// 有两个返回值：使用指针获取返回值
void  month_day(int year, int yearday, int *pmonth, int *pday)
{
    int i, leap;
    
    leap = year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
    for (i = 1; yearday > daytab[leap][i]; i++)
        yearday -= daytab[leap][i];
    *pmonth = i;
    *pday = yearday;
}