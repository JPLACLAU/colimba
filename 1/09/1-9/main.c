

#include <stdio.h>
#include <stdlib.h>


int main()
{
    printf("Exercise 1-9");
    printf("\n");
    printf("Write a program to copy its input to its output, replacing each string of one or more blanks by a single blank");
    printf("\n");
    int c, blanks, tabs, nl, lastChar;



    blanks = 0;
    tabs = 0;
    nl = 0;
    lastChar = ' ';


    while ((c = getchar()) !=EOF)
    {
        lastChar = c; /* Para comparar el caracter nuevo con el previo */
        if ( c == ' ') {
            {
            if (lastChar != ' ')
                putchar(c);
                ++blank;
        };


        if ( c == '\t')
        ++tabs;

        if ( c == '\n')
        ++nl;

        else { putchar(c);}
        }



    }
    printf("blanks: %d\n", blanks);
    printf("\n");
    printf("tabs: %d\n", tabs);
    printf("\n");
    printf("nl: %d\n", nl);
    printf("\n");



}
