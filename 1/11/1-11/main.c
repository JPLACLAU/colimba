

#include <stdio.h>
#include <stdlib.h>


int main()
{
    printf("Exercise 1-11");
    printf("\n");
    printf("How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?");
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
        } /* Cuento las palabras */

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
