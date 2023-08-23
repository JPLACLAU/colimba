#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXLINE 1000

/* Using a custom function to avoid compatibility issues on Windows with the standard getline function */
int get_line(char *line, int max);

/* Function to search a given pattern in a file and print the matching lines */
void search_in_file(char *filename, char *pattern) {
    FILE *fp;
    char line[MAXLINE];
    long lineno = 0;
    int found = 0;

    /* Attempt to open the file. If unsuccessful, print a message and exit the function */
    fp = fopen(filename, "r");
    if (!fp) {
        printf("File %s not found or incorrect.\n", filename);
        return;
    }

    /* Loop through each line in the file */
    while (fgets(line, MAXLINE, fp) != NULL) {
        lineno++;
        /* Check if the pattern is present in the current line */
        if (strstr(line, pattern) != NULL) {
            /* Print the filename, line number, and the matching line */
            printf("In file %s - Line #%ld: %s", filename, lineno, line);
            found++;
        }
    }

    fclose(fp);

    /* If no matches were found in the entire file, print a message */
    if (found == 0) {
        printf("Pattern not found in file %s.\n", filename);
    }
}

int main() {
    char line[MAXLINE];
    char pattern[MAXLINE];
    char filenames[MAXLINE];
    char *token;

    /* Collect the search pattern from the user */
    printf("Enter the pattern to search for: ");
    get_line(pattern, MAXLINE);
    /* Remove the newline character for accurate string comparison */
    pattern[strlen(pattern)-1] = '\0';

    /* Collect file names from the user */
    printf("Enter the names of files separated by commas (or just press enter to input text manually): ");
    get_line(filenames, MAXLINE);

    /* If file names are provided, search in those files */
    if (strlen(filenames) > 1) {
        filenames[strlen(filenames)-1] = '\0';
        /* Adjusting the filename string for processing */

        /* we need to process each file one by one, file1.txt, then file2.txt, etc,
        that is why a token is used */

        token = strtok(filenames, ",");

        /* strtok is used to break a string into separate pieaces by using a comma */
        while (token != NULL) {
            search_in_file(token, pattern);
            token = strtok(NULL, ",");
        }
    } else {
        /* If no file names provided, allow manual text input */
        printf("\nNo files provided or file not found. Enter your text manually.\n");
        printf("Write your text. When done, press Ctrl-D (or Ctrl-Z on Windows):\n");

        long lineno = 0, line_number[MAXLINE];
        char lines_with_pattern[MAXLINE][MAXLINE];
        int found = 0;
        while (get_line(line, MAXLINE) > 0) {
            lineno++;
            /* Check each line for the pattern */
            if (strstr(line, pattern) != NULL) {
                strcpy(lines_with_pattern[found], line);
                line_number[found] = lineno;
                found++;
            }
        }

        /* Display results of the pattern search in the manually entered text */
        if (found == 0) {
            printf("Pattern not found in the provided lines.\n");
        } else {
            printf("\nThe pattern was found in the following lines:\n\n");
            for (int i = 0; i < found; i++) {
                printf("Line #%ld: %s", line_number[i], lines_with_pattern[i]);
            }
        }
    }
    return 0;
}

/* Custom function to read a line from the user input.
   This is used instead of the standard library's getline function due to some compatibility issues on Windows. */
int get_line(char *line, int max) {
    int c, i;
    for (i = 0; i < max - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        line[i] = c;
    }
    if (c == '\n') {
        line[i++] = c;
    }
    line[i] = '\0';
    return i;
}
