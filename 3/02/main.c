#include <stdio.h>

void escape(char s[], char t[]) {
    int i, j;
    for(i = j = 0; t[i] != '\0'; i++)
        switch(t[i]) {
            case '\n':
                s[j++] = '\\';
                s[j++] = 'n';
                break;
            case '\t':
                s[j++] = '\\';
                s[j++] = 't';
                break;
            default:
                s[j++] = t[i];
                break;
        }
    s[j] = '\0';
}

void unescape(char s[], char t[]) {
    int i, j;
    for (i = j = 0; t[i] != '\0'; i++)
        if (t[i] != '\\')
            s[j++] = t[i];
        else
            switch(t[++i]) {
                case 'n':
                    s[j++] = '\n';
                    break;
                case 't':
                    s[j++] = '\t';
                    break;
                default:
                    s[j++] = '\\';
                    s[j++] = t[i];
                    break;
            }
    s[j] = '\0';
}

int main() {
    int c, i, nwhite, nother, ndigit[10];
    nwhite = nother = 0;

    for (i = 0; i < 10; i++)
        ndigit[i] = 0;

    char t[100], s[100];
    i = 0;
    while ((c = getchar()) != EOF && c != '\n' && i < 99)
        t[i++] = c;

    t[i] = '\0';

    escape(s, t);
    printf("Escaped: %s\n", s);

    unescape(t, s);
    printf("Unescaped: %s\n", t);

    return 0;
}
