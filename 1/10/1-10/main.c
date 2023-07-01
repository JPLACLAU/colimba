

#include <stdio.h>
#include <stdlib.h>


int main()
{
    printf("Exercise 1-10");
    printf("\n");
    printf("Write a program to copy its input to its output, replacing each tab by \t, each backspace by \b, and each backslash by \\. This makes tabs and backspaces visible in an unambiguous way. Q");
    printf("\n");


        int c;

    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            putchar('\\');
            putchar('t');
        }
        else if (c == '\\')
        {
            putchar('\\');
            putchar('\\');
        }
        else if (c == '\b')
        {
            putchar('\\');
            putchar('b');
        }
        else
        {
            putchar(c);
        }
    }



    printf("\n");
    return 0;

    }


