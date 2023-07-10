#include <stdio.h>
#include <stdlib.h>

#define TAMANO_MAXIMO_PALABRA 20 /* Tamaño maximo de palabras contadas en el array */

int main()
{
    printf("Exercise 1-13");
    printf("\n");
    printf("Write a program to print a histogram of the lengths of words in its input. It is easy to draw the histogram with the bars horizontal; a vertical orientation is more challenging.");
    printf("\n\n Escriba su texto aqui abajo: \n");

    int c, lastChar, words, wordLength;


    lastChar = 0;
    words = 0;
    wordLength = 0;

    int wordLengthCantidades[TAMANO_MAXIMO_PALABRA] = {0}; /* Asi se define un array*/


    while ((c = getchar()) !=EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n'){
            if (lastChar != ' ' && lastChar != '\t' && lastChar != '\n') {
                ++words;
                /* Cuento las palabras como en los ejercicios anteriores*/

                if(wordLength > 0 && wordLength < TAMANO_MAXIMO_PALABRA){
                   ++wordLengthCantidades[wordLength];
                   /* sumo al contador de palabra para este tamaño en el array */
                }
                wordLength = 0;
                /* reseteo el contador del tamaño de palabra luego de un espacio o tab o finde linea y luego de agregarlo al array */
            }
        }
        else {
            ++wordLength;
            /* sumo al contador de tamaño de palabra con cada caracter */
        }







        lastChar = c; /* Para comparar el caracter nuevo con el previo */

    }

    printf("\n");
    printf("Cantidades de palabras segun su tamaNIo");
    printf("\n");


    for (int i = 1; i < TAMANO_MAXIMO_PALABRA; ++i) {
        if (wordLengthCantidades[i] > 0) {
            printf("%d characters: %d word(s). Visualizacion: ", i, wordLengthCantidades[i]);
            for(int j = 0; j <wordLengthCantidades[i]; ++j) {
                printf("*");
            }
            printf("\n");
        }
    }

    /* Histograma con palabras */

    printf("\n");

    return 0;

}
