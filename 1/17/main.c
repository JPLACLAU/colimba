#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int get_line(char line[], int maxline);


int main() {
    int len; /* current line length */
    char line[MAXLINE]; /* current input line */

    while ((len = get_line(line, MAXLINE)) > 0) {
        if (len > 10 && len < MAXLINE) { /* imprimi si es mas largo que 10 chars y mas chico MAXLINE */
            printf("%s\n", line);
        }
    }
    return 0;
}


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

