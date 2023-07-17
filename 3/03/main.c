#include <stdio.h>
#include <ctype.h>
#include <string.h>


void expand(const char s1[], char s2[]) {
    int i, j, k;

    for (i = j = 0; s1[i]; ++i) {
        if (s1[i] == '-' && i > 0 && s1[i + 1]) {
            for (k = s1[i - 1] + 1; k < s1[i + 1]; ++k) {
                s2[j++] = k;
            }
        }
        else if (!(s1[i] == '-' && (i == 0 || !s1[i + 1]))) {
            s2[j++] = s1[i];
        }
    }

}

int main() {
    char s1[] = "a-z";
    char s2[100]; /* This number is arbitrarly, it needs to be big enought to handle the solution provided by the expand function. */
    expand(s1, s2);
    printf("Expanded string: %s\n", s2);
    return 0;
}
