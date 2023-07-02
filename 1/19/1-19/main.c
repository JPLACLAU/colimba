#include <stdio.h>
#include <stdlib.h>

/*Exercise 1-19. Write a function reverse(s) that reverses the character
string s. Use it to write a program that reverses its input a line at a time */

#define MAXLINE 1000

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
            if (max > 0)
                reverse(longest); /* esta es la funcion de reversa, se hace justo antes del print */
                printf("%s", longest);
        return 0;
}

int getline(char s[], int lim)
{
        int c, i, j;

        i = j = 0;

        while ((c = getchar()) !=EOF && c != '\n') {
            if ( c != ' ' && c != '\t'){
                s[i++] = c;
                j = i;
            }

              else if (i > 0 && s[i-1] != ' ' && s[i-1] != '\t') {
                s[i++] = ' ';
            }
        }

        if ( c == '\n') {

            if (i <lim-1){
               s[i++] = c;
            }
            ++j;
        }

        s[j] = '\0';
        return i;
}

void copy(char to[], char from[])
{
        int i;

        i = 0;
        while ((to[i] = from[i]) != '\0')
            ++i;
}

/* funcion nueva, es void porque no devuelve ninguna informacion, ejecuta algo */
void reverse(char s[]) {

        int length = 0;
        /* necesito saber cuan larga es la cadena para calcular las inversiones */

        while (s[length] != '\0')
            ++length;
        /* en este bucle voy contando cuan largo es el array s y sumando lenght hasta llegar al final */

        for (int i = 0; i < length / 2; ++i) {
        /* con este bucle cuento i hasta la mitad de length */
            char temp = s[i];
            /* preservo temporalmente el valor del caracter de la posicion i de s */
            s[i] = s[length - i -1];
            /* en esta linea sobre escribo el caracter en la posicion i, con el caracter con la posicion i pero contando desde el final de la cadena */
            /* el -1 es porque las posiciones al arrancar, empiezan en i = 0 */
            s[length - i - 1] = temp;
            /* aca coloco el caracter puesto en temporal, en la posicion que acabo de copiar en la linea anterior. */

        }
}
