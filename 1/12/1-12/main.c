

#include <stdio.h>
#include <stdlib.h>


int main()
{
    printf("Exercise 1-12");
    printf("\n");
    printf("Write a program that prints its input one word per line.");
    printf("\n");

    int c, blanks, tabs, nl, lastChar, words;

    blanks = 0;
    tabs = 0;
    nl = 0;
    lastChar = 0;
    words = 0;


    while ((c = getchar()) !=EOF)
    {
        if ((c == ' ' || c == '\t' || c == '\n') && (lastChar != ' ' && lastChar != '\t' && lastChar != '\n')) {
            ++words;
            printf("\n");
        } /* Cuento las palabras e imprime un salto de linea al final de cada palabra*/

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
    printf("tabs: %d\n", tabs);
    printf("nl: %d\n", nl);
    printf("words: %d\n", words);
    printf("\n");

    return 0;

    }
