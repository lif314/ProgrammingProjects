# include <stdio.h>

// // Count the appearance times of each number, blank character, and other characters

int main()
{
    int  c;  // char
    int numWhite = 0;
    int numOther = 0;
    
    int numDigit[10];
    for(int i = 0; i < 10; ++i)
    {
        numDigit[i] = 0;
    }

    while ((c = getchar()) != EOF)
    {
        switch (c)
        {
        case '0':  case '1':  case '2':  case '3':  case '4': 
        case '5':  case '6': case '7':  case '8':  case '9':
            numDigit[c - '0']++;
            break;
        case ' ':
        case '\t':
        case '\n':
            numWhite++;
            break;
        default:
            numOther++;
            break;
        }
    }

    // draw a Horizontal histogram
    printf("Horizontal histogram:\n");
    for(int i = 0; i < 10; ++i)
    {
        printf("%6d :", i);
        for(int j = 0; j < numDigit[i]; ++j)
        {
            printf("*");
        }
        printf("\n");
    }
    printf(" white ：");
    for(int k = 0; k < numWhite; ++k)
    {
        printf("*");
    }
    printf("\n");
    printf(" other :");
    for (int k = 0; k < numOther; ++k)
    {
        printf("*");
    }

    return 0;
}