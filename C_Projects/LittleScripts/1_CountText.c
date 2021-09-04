# include <stdio.h>

# define IN 1   // in a word
# define OUT 0  // out of a word

// Count the number of lines, words, and characters of the input text

int main()
{
    int c; // input char
    int state = OUT; // IN or OUT
    int numLines = 0, numWords = 0, numCharas = 0; 

    while((c = getchar()) != EOF)
    {
        ++numCharas;
        if(c == '\n')
        {
            ++numLines;
        }
        if(c == ' ' || c == '\t' || c == '\n')
            state = OUT;
        else if (state == OUT)
        {
            state = IN;
            ++numWords;
        }        
    }

    printf("Lines = %d, Words = %d, Charas = %d\n", numLines, numWords, numCharas);
}