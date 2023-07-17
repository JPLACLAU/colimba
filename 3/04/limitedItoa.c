#include <stdio.h>

/* itoa: convert n to characters in s. This is the function original of itoa, with the limitations discussed. */
void itoa(int n, char s[]) {
    int i, sign;
    unsigned int abs_n;

    if ((sign = n) < 0) {
        abs_n = -(unsigned int)n;
    } else {
        abs_n = n;
    }

    i = 0;
    do {
        s[i++] = abs_n % 10 + '0';
        abs_n /= 10;
    } while (abs_n > 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';

    for(int start = 0, end = i - 1; start < end; start++, end--) {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;
    }
}

int main() {
    char limit1[12];
    itoa(2147483647, limit1); /* if you change this value to 2147483648 you will find the itoa limitation */
    printf("%s\n", limit1);
    char zero[12];
    itoa(0, zero);
    printf("%s\n", zero);
    char limit2[12];
    itoa(-2147483648, limit2);
    printf("%s\n", limit2);

    return 0;
}
