#include <stdio.h>
#include <string.h>

int main() {
    FILE *file1, *file2;
    char line1[1000], line2[1000];
    char diff_line1[1000], diff_line2[1000];  /* Added to store the lines with the first difference */
    int line_number = 0, first_diff = 0;

    /* Open the two files for reading */
    file1 = fopen("text1.txt", "r");
    file2 = fopen("text2.txt", "r");

    /* Check if either file failed to open */
    if (!file1 || !file2) {
        printf("Error opening files.\n");
        return 1;
    }

    /* Compare each line from both files */
    while (fgets(line1, sizeof(line1), file1) != NULL && fgets(line2, sizeof(line2), file2) != NULL) {
        line_number++;
        /* If the lines are different, store the number of the lines, also print it */
        if (strcmp(line1, line2) != 0) {
            if (first_diff == 0) {
                printf("The texts are different.\nThey are differecies on these lines: \n");
                first_diff = line_number;
                strcpy(diff_line1, line1);  /* Save the different lines */
                strcpy(diff_line2, line2);
            }
            printf("%d, ", line_number);
        }
    }

    /* If there was at least one difference, print the lines that are different from the two files */
    if (first_diff != 0) {
        printf("\n\nPrinting of the first line where they are different:\n");
        printf("\ntext1.txt :\nLine %d: %s", first_diff, diff_line1);
        printf("\ntext2.txt :\nLine %d: %s\n", first_diff, diff_line2);
    } else {
        printf("The files are identical.\n");
    }

    fclose(file1);
    fclose(file2);

    return 0;
}
