#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

/* Using a custom function to avoid compatibility issues on Windows with the standard getline function */
int get_line(char *line, int max);

/* Function to print a file's content, starting each file on a new page with a title and page count */
void print_file_with_title(char *filename, int *page_number) {
    FILE *fp;
    char line[MAXLINE];

    /* Attempt to open the file. If unsuccessful, print a message and exit the function */
    fp = fopen(filename, "r");
    if (!fp) {
        printf("File %s not found or incorrect.\n", filename);
        return;
    }

    /* Print a new page header */
    printf("\n\f\n");  /* Form feed character to simulate a new page */
    printf("\nTitle: %s\n", filename);
    printf("Page Number: %d\n\n", *page_number);
    (*page_number)++;  /* Increment the page count for the next file */

    /* Loop through each line in the file and print it */
    while (fgets(line, MAXLINE, fp) != NULL) {
        printf("%s", line);
    }

    fclose(fp);
}

int main() {
    char filenames[MAXLINE];
    char *token;
    int page_number = 1;  /* Initialize page count */

    /* Collect file names from the user */
    printf("Enter the names of files separated by commas: ");
    get_line(filenames, MAXLINE);
    filenames[strlen(filenames)-1] = '\0';  /* Remove the newline character */

    /* Start processing each file */
    token = strtok(filenames, ",");
    while (token != NULL) {
        print_file_with_title(token, &page_number);
        token = strtok(NULL, ",");
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
