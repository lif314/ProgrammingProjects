# include <stdio.h>
# include <ctype.h>


// char s ----> int
// white -----> skip
// character -> skip
// + -  ------> skip
// digit -----> transfer
int atoi(char s[])
{
    int i, n, sign;

    for(i = 0; isspace(s[i]); i++) // skip the space
        ;

    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-') // skip
        i++;
    for(n = 0; isdigit(s[i]); i++)
        n = 10 * n + (s[i] - '0');
    
    return sign * n;
}


// test
int main()
{
    char s[] = "    -123";
    int n = atoi(s);
    printf("%d", n);
    return 0;
}