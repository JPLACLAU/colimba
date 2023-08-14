#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define BUFSIZE 100
#define MAXWORD 100

int buf = 0;

int getch(void) {
    int temp = buf;
    buf = 0;
    return (temp != 0) ? temp : getchar();
}

void ungetch(int c) {
    buf = c;
}

int getword(char *word, int lim) {
    int c;
    char *w = word;
    while (isspace(c = getch()))
        ;
    if (c != EOF) {
        *w++ = c;
    }
    if (!isalpha(c)) {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) {
        if (!isalnum(*w = getch())) {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

int main() {
    char word[MAXWORD];
    int count = 0;

    printf("The getword function will get the first three words of the line.\nEnter a line of text: ");
    fflush(stdout);

    while (getword(word, MAXWORD) != '\n') {
        if (isalpha(word[0])) {
            printf("Word %d: %s\n", count + 1, word);
            count++;
        }
        if (count == 3) {
            break;
        }
    }

    return 0;
}
