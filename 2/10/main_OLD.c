#include <stdio.h>

#define LIM 100

int toLower(int c) {
    return (c >= 'A' && c <= 'Z') ? c + 'a' - 'A': c;
} /* I took this part of the function from Rapax. I thought I had the right to do it since I helped correcting it. */

int main(){
    int c;
    char s[LIM];
    int i = 0;

    for (; i < LIM - 1 && (c=getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }


    for (i = 0; s[i] != '\0'; i++) {
        s[i] = toLower(s[i]);
    }

    printf("Lower cases: %s\n", s);

    return 0;
}
