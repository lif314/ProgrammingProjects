/* point & array */

// char amessage[] = "Hello World";  // 可以修改内容，但不能修改amessage
// char * pmessage = "Hello World";  // 不能修改内容，但能修改pmessage

// array index
void strcpy_array(char *s, char *t)
{
    int i;

    i - 0;
    while((s[i] = t[i]) != '\0')
        i++;
}

// pointer
void strcpy_pointer(char *s, char *t)
{
    while((*s = *t) != '\0')
    {
        s++;
        t++;
    }
}

// pointer2
void strcpy_pointer2(char *s, char *t)
{
    while((*s++ = *t++) != '\0')
        ;
}

// pointer3
void strcpy_pointer3(char *s, char *t)
{
    while(*s++ = *t++)
        ;
}