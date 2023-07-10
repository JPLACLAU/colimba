#include <stdio.h>
#include <stdlib.h>

#define TAMANO_MAXIMO_LETRA 300 /* Tamaño maximo de caracteres contadas en el array */

int main()
{
    printf("Exercise 1-14\n");
    printf("Write a program to print a histogram of the frequencies of different characters in its input.\n");
    printf("------------\n");
    printf("Escriba su texto aqui abajo: \n");

    int c;
    int frecuenciaCaracteres[TAMANO_MAXIMO_LETRA] = {0}; /* Asi se define un array*/

    while ((c = getchar()) !=EOF)
    {
        if (c >= 0 && c < TAMANO_MAXIMO_LETRA) {
            ++frecuenciaCaracteres[c]; /* sumo al contador de caracteres */
        }
    }

    printf("\n------------\n");
    printf("Cantidades de letras\n");
    printf("------------\n");

    for (int i = 32; i < TAMANO_MAXIMO_LETRA; ++i) {
        /* el i empieza en 32 porque C interpreta cada caracter como un numero que en ASCII empiezan en 32 */
        /* antes del 32, hay caracteres que son operadores como el backspace y el escape */

        if (frecuenciaCaracteres[i] > 0) {
            printf("'%c': %d ", i, frecuenciaCaracteres[i]);
            for(int j = 0; j < frecuenciaCaracteres[i]; ++j) {
                printf("*");
            }
            printf("\n");
        }
    }

    printf("\n");

    return 0;
}
