/* point & array */

// char amessage[] = "Hello World";  // 可以修改内容，但不能修改amessage
// char * pmessage = "Hello World";  // 不能修改内容，但能修改pmessage
// 进出栈标准用法：
// *p++ = val;
// val = *--p;

// dictionary order
/*
* s < t : -
* s = t : 0
* s > t : +
*/

// array index
int Strcmp_array(char *s, char *t)
{
    int i;

    for(i = 0; s[i] == t[i]; i++)
        if(s[i] == '\0')
            return 0;

    return s[i] - t[i];
}


// pointer
int Strcmp_pointer(char *s, char *t)
{
    for(; *s = *t; s++, t++)
        if(*s == '\0')
            return 0;

    return *s - *t;

}