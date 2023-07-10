#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Exercise 1-11");
    printf("\n");
    printf("How would you test the word count program? What kinds of input are most likely to uncover bugs if there are any?");
    printf("\n");

    int c, lastChar, words;
    lastChar = 0;
    words = 0;

    while ((c = getchar()) !=EOF)
    {
        if ((c == ' ' || c == '\t' || c == '\n') && (lastChar != ' ' && lastChar != '\t' && lastChar != '\n')) {
            ++words;
        } /* Count the words */

        lastChar = c; /* Compare the new character with the previous one */
    }

    printf("words: %d\n", words);
    printf("\n");
    return 0;
}
