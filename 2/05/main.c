#include <stdio.h>

int any(char s1[], char s2[]) {
    int i, k;
    for(i = 0; s1[i] != '\0'; i++) {
        for(k = 0; s2[k] != '\0'; k++) {
            if(s1[i] == s2[k])
                return i;  /* Returns the first index where the character was found */
        }
    }
    return -1;  /* Char not found*/
}

int main() {
    char s1[] = "Chapeau";
    char s2[] = "C";
    int location = any(s1, s2);
    printf("S1: %s\n", s1);
    printf("S2: %s\n", s2);
    if(location == -1) {
        printf("No character from s2 is found in s1\n");
    } else {
        printf("The first occurrence of a character from s2 in s1 is at index: %d\n", location);
    }
    return 0;
}
