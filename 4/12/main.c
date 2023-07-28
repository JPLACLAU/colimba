#include <stdio.h>

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

int main() {
    int n = -1234;
    char s[10];  /* I sssume max digits = 10 */

    itoa2(n, s);  /* converts n to characters in s */
    printf("%s\n", s);

    return 0;
}
