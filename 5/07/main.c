#include <stdio.h>
#include <string.h>
#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];
char lines[MAXLINES][MAXLEN]; /* array for storing lines */

void swap(char *v[], int i, int j) {
    char *temp;
    temp = v[i];
    v[i] = v[j];
    v[j] = temp;
}

void qsort(char *v[], int left, int right) {
    int i, last;
    if (left >= right)
        return;
    swap(v, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
        if (strcmp(v[i], v[left]) < 0)
            swap(v, ++last, i);
    swap(v, left, last);
    qsort(v, left, last - 1);
    qsort(v, last + 1, right);
}

int getline(char s[], int lim) {
    int c, i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}



int readlines(char *lineptr[], char lines[][MAXLEN], int maxlines) {
    int len, nlines = 0;
    char line[MAXLEN];
    while ((len = getline(line, MAXLEN)) > 0) {
        if (nlines >= maxlines)
            return -1;
        else {
            line[len - 1] = '\0';
            strcpy(lines[nlines], line);
            lineptr[nlines] = lines[nlines];
            nlines++;
        }
    }
    return nlines;
}

void writelines(char *lineptr[], int nlines) {
    int i;
    for (i = 0; i < nlines; i++)
        printf("%s\n", lineptr[i]);
}

int main() {
    int nlines;
    if ((nlines = readlines(lineptr, lines, MAXLINES)) >= 0) {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    } else {
        printf("error: input too big to sort\n");
        return 1;
    }
}
