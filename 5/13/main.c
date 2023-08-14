#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DEFAULT_N 10
#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];
char lines[MAXLINES][MAXLEN];

int getline(char s[], int lim) {
    int c, i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int readlines(char *lineptr[], char lines[][MAXLEN], int maxlines, int n) {
    int len, nlines = 0, current_line = 0;
    char line[MAXLEN];
    while ((len = getline(line, MAXLEN)) > 0) {
        line[len - 1] = '\0';
        strcpy(lines[current_line], line);
        lineptr[current_line] = lines[current_line];
        current_line = (current_line + 1) % n;
        if (nlines < n) {
            nlines++;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines, int n) {
    int i;
    for (i = 0; i < nlines; i++) {
        printf("%s\n", lineptr[i]);
    }
}

int main(int argc, char *argv[]) {
    int nlines;
    int n = DEFAULT_N;

    if (argc > 1 && argv[1][0] == '-') {
        n = -atoi(argv[1]);
    }

    if ((nlines = readlines(lineptr, lines, MAXLINES, n)) >= 0) {
        writelines(lineptr, nlines, n);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}
