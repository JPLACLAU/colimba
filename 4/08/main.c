#include <stdio.h>
#include <string.h>
#define BUFSIZE 100

int buf = 0;

int getch(void) {
    int temp = buf;
    buf = 0;
    return (temp != 0) ? temp : getchar();
}

void ungetch(int c) {
     buf = c;
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
