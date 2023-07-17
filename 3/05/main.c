#include <stdio.h>

void reverse(char s[]) {
    int length = strlen(s);
    int i;
    for (i = 0; i < length / 2; i++) {
        char temp = s[i];
        s[i] = s[length - i - 1];
        s[length - i - 1] = temp;
    }
}

void itob(int n, char s[], int b) {
    int i, sign;
    unsigned int abs_n;

    if ((sign = n) < 0) {
        abs_n = -(unsigned int)n;
    } else {
        abs_n = n;
    }

    i = 0;
    do {
        int digit = abs_n % b;
        s[i++] = (digit > 9) ? (digit - 10 + 'A') : (digit + '0');
        abs_n /= b;
    } while (abs_n > 0);

    if (sign < 0) {
        s[i++] = '-';
    }
    s[i] = '\0';

    reverse(s);
}

int main() {
    char convertToHexadecimal[100];
    itob(20221218, convertToHexadecimal, 16);
    /* 2022-12-18 Is the Day Argentina became champion of the world. In hex it should be: "1348D22"*/
    printf("%s\n", convertToHexadecimal);

    return 0;
}
