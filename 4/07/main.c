#include <stdio.h>
#include <string.h>
#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void ungets(char s[]) {
    int i;
    for (i = strlen(s) - 1; i >= 0; i--)
        ungetch(s[i]);
}

int main() {
    char s[BUFSIZE];
    int i = 0, c;

    while (i < BUFSIZE - 1 && (c = getc(stdin)) != EOF && c != '\n')
        s[i++] = c;
    s[i] = '\0';

    ungets(s);
    printf("%c", getch());
    return 0;
}
