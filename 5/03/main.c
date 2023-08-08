#include <stdio.h>

void p_strcat(char *s, char *t) {
    while (*s != '\0') {
        s++;
    }
    while ((*s = *t) != '\0') {
        s++;
        t++;
    }
}

int main() {
    char s[100] = "123";
    char t[] = "456";

    p_strcat(s, t);

    printf("s+t: %s\n", s);

    return 0;
}

