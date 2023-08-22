#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LINE 1000

int main(int argc, char *argv[]) {
    char line[MAX_LINE];
    int c, i = 0;

    while (i < MAX_LINE - 1 && (c = getchar()) != EOF && c != '\n') {
        line[i++] = c;
    }
    line[i] = '\0';

    if (strcmp(argv[1], "-toupper") == 0) {
        for (int j = 0; j < i; j++)
            line[j] = toupper(line[j]);
    } else if (strcmp(argv[1], "-tolower") == 0) {
        for (int j = 0; j < i; j++)
            line[j] = tolower(line[j]);
    } else {
        printf("Arguments are mandatory for this program: %s -toupper|-tolower\n", argv[0]);
        return 1;
    }
    printf("%s\n", line);
    return 0;
}
