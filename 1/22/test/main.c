#include <stdio.h>
#include <stdlib.h>
#define IN 1  /* inside a word */
#define OUT 0 /* outside a word */
#define MAX_LENGTH 15

int main()
{
    int c, state, length;
    int lengths[MAX_LENGTH + 1] = {0};

    state = OUT;
    length = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
          if (state == IN) {
            if (length <= MAX_LENGTH) {
                lengths[length++];
            }
            length = 0;
            state = OUT;
        }
        else {
            state = IN;
            length++;
        }
    }
    return 0;
}
}
