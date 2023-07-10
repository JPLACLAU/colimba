#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Exercise 1-12\n");
    printf("Write a program that prints its input one word per line.\n");

    int c, lastChar;

    lastChar = 0;

    while ((c = getchar()) != EOF)
    {
        /* If the current character is a space, tab, or newline and the last character was not, */
        /* print a newline character to start a new word on the next line. */
        if ((c == ' ' || c == '\t' || c == '\n') && (lastChar != ' ' && lastChar != '\t' && lastChar != '\n')) {
            printf("\n");
        }

        /* If the current character is not a space, tab, or newline, print it. */
        if (c != ' ' && c != '\t' && c != '\n') {
            putchar(c);
        }

        /* Remember the current character for the next iteration. */
        lastChar = c;
    }

    printf("\n");
    return 0;
}
