

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
    lastChar = 0;


    while ((c = getchar()) !=EOF)
    {


        if ( c == ' ') {

        if (lastChar != ' ') {
                ++blanks;
                putchar(c);
                }
         };

        if(c != ' ')
            putchar(c);

        if ( c == '\t')
        ++tabs;

        if ( c == '\n')
        ++nl;

        lastChar = c; /* Para comparar el caracter nuevo con el previo */


        }


    printf("blanks: %d\n", blanks);
    printf("\n");
    printf("tabs: %d\n", tabs);
    printf("\n");
    printf("nl: %d\n", nl);
    printf("\n");
    return 0;

    }


