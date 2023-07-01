

#include <stdio.h>
#include <stdlib.h>

/* count lines in input */

int main()
{
    printf("Exercise 1-8");
    printf("\n");
    printf("Write a program to count blanks, tabs, and newlines");
    printf("\n");
    int c, blanks, tabs, nl; /* declarado */
    /* esta es una variable automatica */


    nl = 0; /*definidos*/
    blanks = 0;
    tabs = 0;

    while ((c = getchar()) !=EOF)
    {
        if ( c == ' ')
        ++blanks;
        if ( c == '\t')
        ++tabs;
        if ( c == '\n')
        ++nl;


    }
    printf("blanks: %d\n", blanks);
    printf("\n");
    printf("tabs: %d\n", tabs);
    printf("\n");
    printf("nl: %d\n", nl);
    printf("\n");



}
