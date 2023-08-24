#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

/* Memory-optimized version of isupper.
   This approach uses less memory since we're not relying on an extra lookup table. */
int isupper_memory_optimized(char c) {
    return (c >= 'A' && c <= 'Z') ? 1 : 0;
}

/* Time-optimized version of isupper.
   A lookup table is used. This speeds up the check at the cost of more memory usage. */
int lookup[256];

void initialize_lookup_table() {
    for (int i = 0; i < 256; i++) {
        if (i >= 'A' && i <= 'Z') {
            lookup[i] = 1;
        } else {
            lookup[i] = 0;
        }
    }
}

int isupper_time_optimized(char c) {
    return lookup[(int) c];
}

/*  User input and then the desired isupper function (either time or memory optimized) to use. */
void process_input(int (*isupper_function)(char)) {
    char sentence[MAXLINE];
    printf("Enter a sentence: ");
    scanf("%[^\n]", sentence);  /* Reads until a newline character */
    getchar();  /* Consume the newline character left in the input buffer */

    for (int i = 0; i < strlen(sentence); i++) {
        printf("%d", isupper_function(sentence[i]));
    }
    printf("\n");
}

int main(int argc, char *argv[]) {
    /* We check if the user has provided the required command-line argument */
    if (argc != 2) {
        printf("Please run the program again with either -time or -memory arguments.\n");
        return 1;
    }

    /* Depending on the user's choice, we select the appropriate isupper function. */
    if (strcmp(argv[1], "-time") == 0) {
        printf("Using the time optimized version of isupper\n");
        initialize_lookup_table();
        process_input(isupper_time_optimized);
    } else if (strcmp(argv[1], "-memory") == 0) {
        printf("Using the memory optimized version of isupper\n");
        process_input(isupper_memory_optimized);
    } else {
        printf("Please run the program again with either -time or -memory arguments.\n");
    }

    return 0;
}
