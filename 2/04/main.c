#include <stdio.h>

void squeeze(char s1[], char s2[]) {
    int i, j, k;
    for(i = j = 0; s1[i] != '\0'; i++) {
        for(k = 0; s2[k] != '\0' && s2[k] != s1[i]; k++)
            ; /* el loop stopea al llegar al final o si encontramos el caracter. */
        if(s2[k] == '\0')  /* Sin encontrar el caracter. */
            s1[j++] = s1[i];
    }
    s1[j] = '\0';
}

int main() {
    char s1[] = "Chapeau";
    char s2[] = "C";
    printf("Original s1: %s\n", s1);
    squeeze(s1, s2);
    printf("Squeezed s1: %s\n", s1);
    return 0;
}
