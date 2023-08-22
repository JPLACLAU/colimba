#include <stdio.h>
#include <ctype.h>

#define FORMAT "%X" /* "%X" for hex, "%o" for octal */
#define MAXLINE 75

int main() {
    int c, i = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            i = 0;
            putchar(c);
        } else if (++i == MAXLINE) {
            i = 0;
            putchar('\n');
        }

        if (isgraph(c) || isspace(c))
            putchar(c);
        else
            printf(FORMAT, c);
    }

    return 0;
}

