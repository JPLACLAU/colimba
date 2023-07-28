#include <stdio.h>
#include <string.h>

/* itoa2: convert n to characters in s */
void itoa2(int n, char s[]) {
    static int i;

    if(n < 0) {
        s[i++] = '-';
        n = -n;
    }

    if(n / 10)
        itoa2(n / 10, s); /* recursion to the same function */
    else
        i = 0;

    s[i++] = n % 10 + '0';
    s[i] = '\0';
}

/* reverse: reverse string s */
void reverse(char s[]) {
    static int i = 0;
    static int j = 0;
    char c;

    if (j == 0) /* this is done only once */
        j = strlen(s) - 1;

    if (i < j) {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        i++;
        j--;
        reverse(s); /* recursion to the same function */
    } else {
        i = j = 0;
    }
}

int main() {
    int n = -1234;
    char s[10];

    itoa2(n, s);
    printf("original: %s\n", s);

    reverse(s);
    printf("reverse: %s\n", s);

    return 0;
}
