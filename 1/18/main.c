#include <stdio.h>

/*Exercise 1-18. Write a program to remove trailing blanks and tabs from each
line of input, and to delete entirely blank lines. */

#define MAXLINE 1000 /* Maximum input line size */

int getLine(char s[], int lim);
void copy(char to[], char from[]);

int main()
{
    int len; /* Current line length */
    int max; /* Maximum length seen so far */
    char line[MAXLINE]; /* Current input line */
    char longest[MAXLINE]; /* Longest line saved here */

    max = 0;

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) /* If there was a line */
        printf("%s", longest);

    return 0;
}

int getLine(char s[], int lim)
{
    int c, i, j;

    for (i = 0, j = 0; (c = getchar()) != EOF && c != '\n'; ++i) {
        if (c != ' ' && c != '\t') {
            s[j++] = c;
        } else if (j > 0 && s[j-1] != ' ') {
            s[j++] = ' ';
        }
    }

    if (c == '\n' && j < lim - 1)
        s[j++] = c;

    s[j] = '\0';
    return j;
}

void copy(char to[], char from[])
{
    int i = 0;

    while ((to[i] = from[i]) != '\0')
        ++i;
}

