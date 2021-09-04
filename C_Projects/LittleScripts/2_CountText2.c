# include <stdio.h>

// Count the appearance times of each number, blank character, and other characters, and draw a histogram

int main()
{
    int numDigit[10];   // 0-9
    for(int i = 0; i < 10; ++i)
        numDigit[i] = 0;

    int numWhite = 0; // blank character
    int numOther = 0; // other characters

    int c;            // char
    while((c = getchar()) != EOF)
    {
        if(c >= '0' && c < '9')
            ++numDigit[c - '0'];
        else if(c == ' ' || c == '\t' || c == '\n')
            ++numWhite;
        else
            ++numOther;
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

    // draw a Vertical histogram
    // printf("\n\n");
    // printf("Vertical histogram:\n");
}