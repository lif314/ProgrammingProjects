// int ----> double

# include <stdio.h>
# include <ctype.h>

# define MAXLINE 100 // test simple calculator

// char s ---> double
double atof(char s[])
{
    double val, power;
    int i, sign;

    for(i = 0; isspace(s[i]); i++) // skip space
        ;
    
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')  // skip +, -
        i++;
    
    for(val = 0.0; isdigit(s[i]); i++)  // integer part
    {
        val = 10.0 * val + (s[i] - '0');
    }
    if(s[i] == '.') // skip .
        i++;
    for(power = 1.0; isdigit(s[i]); i++)
    {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    return sign * val / power;
}

// stdlib
// double (ATOF)(const char *s)
// {	/* convert string to double */
// 	return (_Stod(s, NULL));
// }

// test
// Read a line
int getLine(char s[], int lim)
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

// simple line calculator
double lineCalculator()
{
    // declar function 
    double sum, atof(char[]);
    char line[MAXLINE];
    int getLine(char line[], int max);

    sum = 0;
    while(getLine(line, MAXLINE) > 0)
    {
        sum += atof(line);
    }
    return sum;
}

int main()
{
    char s[] = "  -133.3434   ";
    // printf("%f %f", atof(s), ATOF(s));
    printf("s: %f\n", atof(s));
    printf("sum: %f", lineCalculator());
    return 0;
}
