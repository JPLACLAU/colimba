#include <stdio.h>
#include <stdlib.h>

/*Exercise 1-18. Write a program to remove trailing blanks and tabs from each
line of input, and to delete entirely blank lines. */

/* este programa tiene un bug: no me reconoce lineas que escriba luego que borre una linea en blanco */

#define MAXLINE 1000 /*maximum input line size */

int getline(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line*/

int main()
{
        int len;    /*current line length */
        int max;    /*maximum length seen so far */
        char line[MAXLINE]; /* current input line */
        char longest[MAXLINE]; /* longest line saved here */

        max = 0;
        while ((len = getline(line,MAXLINE)) > 0)
            if ( len > max) {
                max = len;
                copy(longest, line);
            }
            if (max > 0)    /* there was a line */
                printf("%s", longest);
        return 0;
}
/* getline: read a line into s, return length */
int getline(char s[], int lim)
{
        int c, i, j;
        /* j sirve para diferenciar las linas con espacios y tabs no deseados */

        i = j = 0;
            /* esto es solo al inicio del programa, va ir cambiando */
            /* i va ser siempre igual o mayor que j */

            /* con esta linea de codigo elijo la regla general para cuando c no es
            ni espacio ni tabulacion*/
        while ((c = getchar()) !=EOF && c != '\n') {
            if ( c != ' ' && c != '\t'){
                s[i++] = c;
                /* cada caracter se agrega el "pointer" (no vector) s */
                j = i;
                /* j se iguala a i cuando se tipea un caracter, esto es importante despues */
            }   /* cuando agrego un caracter normal, crece i y j */

            /*con esta linea de codigo elijo que el espacio y el tab
            se transformen en esapcio, siempre qu eno haya habido un espacio antes */
            else if (i > 0 && s[i-1] != ' ' && s[i-1] != '\t') {
                s[i++] = ' ';
            }   /*cuando agrego un caracter espacio, solo crece i, y no crece j */
        }

        if ( c == '\n') {
                /* cuando terminamos una linea hay que verificar ciertas cosas... */
            if (i <lim-1){
                /* si lim es menor a MAXLINE, que definimos arriba como 1000, entonces la linea se puede guardar*/
                s[i++] = c;
                /* procedemos a guardar la linea entera */
            }
            ++j;
            /* es importante aumentar j al terminar de linea a la par que el i*/
        }

        s[j] = '\0';
            /* el final del programa se hace al final de la linea con caracter ni espacio ni tab */
        return i;
}

/* copy: copy 'from' into 'to': assume to is big enough */
void copy(char to[], char from[])
{
        int i;

        i = 0;
        while ((to[i] = from[i]) != '\0')
            ++i;
}
