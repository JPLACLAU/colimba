#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int get_line(char line[], int maxline);

/* print lines that are longer than 80 characters */
int main() {
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > 80) { /* imprimi si es mas largo que 80 chars*/
            printf("%s\n", line);
        }
    }
    return 0;
}

/* getline / get_line: read a line into s, return length */
/*I rename getline to get_line because getline is an existing operator on  C*/
int get_line(char s[], int lim) {
    int c, i, j;
    /* la variable j es introducida para contar los caracteres de una lina guardada */

    /* la diferencia entre j e i es que una vez llegados al limite de caracteres, j no agrga mas caracteres,
    mientras que i ahora puede servir para seguir contando caracteres de una linea que exceda el limite*/

    for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (i < lim - 1) {
            s[j++] = c;
        }
    }
    if (c == '\n') {
        if (i < lim - 1) {
            s[j++] = c;
        }
        ++i;
    }
    s[j] = '\0';
    return i;
}

