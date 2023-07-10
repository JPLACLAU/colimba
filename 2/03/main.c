#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define LIM 100

int htoi(const char s[]) {
    int i = 0;
    int n = 0;

    /* skip optional 0x or 0X */
    if (s[0] == '0' && (tolower(s[1]) == 'x')) {
        i = 2;
    }

    /* hex conversion */
    for (; s[i] != '\0'; i++) {
        if (isxdigit(s[i])) {
            n = 16 * n;
            if(isdigit(s[i])){
                n += (s[i] - '0');
            }
            else{
                n += (tolower(s[i]) - 'a' + 10);
            }
        }
        else {
            /* stop if invalid chars */
            return -1;
        }
    }

    return n;
}


int main(){
    int c;
    char s[LIM];
    int i = 0;

    for (; i < LIM - 1 && (c=getchar()) != EOF && c != '\n'; ) {
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'f') || (c >= 'A' && c <= 'F')) {
            s[i] = c;
            ++i;
        }
    }

    s[i] = '\0'; /* stop if invalid chars */

    printf("Captured hexadecimals:%s\n", s);
    printf("The integer value of %s is %u\n", s, htoi(s)); /* uso %u porque quiero un UNSIGNED INT */

    return 0;
}
