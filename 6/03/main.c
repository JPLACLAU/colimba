#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define BUFSIZE 100
#define MAXWORD 100
#define MAXLINES 100

int buf = 0;
int line_number = 1;

int getch(void) {
    int temp = buf;
    buf = 0;
    return (temp != 0) ? temp : getchar();
}

void ungetch(int c) {
    buf = c;
}

int is_stop_word(const char *word) {
    const char *stop_words[] = {
        "a", "an", "and", "are", "as", "at", "be", "but", "by", "for", "he", "I", "in", "is", "it", "of", "off", "on", "or", "she", "so", "that", "the", "they", "this", "to", "was", "with", "you"
    };
    int n = sizeof(stop_words) / sizeof(stop_words[0]);
    for (int i = 0; i < n; i++) {
        if (strcmp(word, stop_words[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int getword(char *word, int lim) {
    int c;
    char *w = word;
    while (isspace(c = getch())) {
        if (c == '\n') line_number++;
    }
    if (c != EOF) {
        *w++ = c;
    }
    if (!isalpha(c) && c != '_') {
        *w = '\0';
        return c;
    }
    for (; --lim > 0; w++) {
        if (!isalnum(*w = getch()) && *w != '_') {
            ungetch(*w);
            break;
        }
    }
    *w = '\0';
    return word[0];
}

int main() {
    char word[MAXWORD];
    char textWords[MAXLINES][MAXWORD];
    int lineNumbers[MAXLINES][MAXLINES];
    int count[MAXLINES] = {0};
    int wordCount = 0;

    printf("Enter text, and the program will print back the words with line numbers, ignoring common stop words.\n");
    fflush(stdout);

    int c;
    while ((c = getword(word, MAXWORD)) != EOF) {
        if (c == '\n') continue;

        if (isalpha(word[0]) && !is_stop_word(word)) {
            int found = 0;
            for (int i = 0; i < wordCount; i++) {
                if (strcmp(word, textWords[i]) == 0) {
                    found = 1;
                    if (lineNumbers[i][count[i] - 1] != line_number) {
                        lineNumbers[i][count[i]] = line_number;
                        count[i]++;
                    }
                    break;
                }
            }
            if (!found) {
                strcpy(textWords[wordCount], word);
                lineNumbers[wordCount][0] = line_number;
                count[wordCount]++;
                wordCount++;
            }
        }
    }

    printf("\nThe words are:\n");
    for (int i = 0; i < wordCount; i++) {
        printf("Word: %s | Count: %d | Line Number:", textWords[i], count[i]);
        for (int j = 0; j < count[i]; j++) {
            printf(" %d", lineNumbers[i][j]);
            if (j < count[i] - 1) printf(",");
        }
        printf("\n");
    }

    return 0;
}
