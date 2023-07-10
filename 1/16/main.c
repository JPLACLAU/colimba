/* mashup de codigos en la red */

#include <stdio.h>
#define MAXLINE 1000 /* maximum input line size */

int get_line(char line[], int maxline);
void copy(char to[], char from[]);

/* print longest input line */
int main() {
    int len; /* current line length */
    int max; /* maximum length seen so far */
    char line[MAXLINE]; /* current input line */
    char longest[MAXLINE]; /* longest line saved here */

    max = 0;
    while ((len = get_line(line, MAXLINE)) > 0)
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    if (max > 0) { /* there was a line */
        printf("Longest line length: %d\n", max);
        printf("Longest line text (first %d characters): %s\n", MAXLINE, longest);
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

/* copy: copy 'from' into 'to': assume to is big enough */
void copy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0')
        ++i;
}
