#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZ 512

/* Struct to encapsulate file state without relying on bitwise operations */
struct Flags {
    int READ; /* Flag to check if the file is in read mode */
    int END;  /* Flag to indicate if the end of the file is reached */
};

/* Custom structure to represent a file and its associated metadata */
typedef struct CustomFile {
    FILE *fp;          /* Standard file pointer */
    struct Flags _flag;/* Custom flag structure */
    char *_base;       /* Base pointer to the buffer */
    char *_ptr;        /* Current position pointer within the buffer */
    int _cnt;          /* Number of characters left in the buffer */
} CustomFile;

/* Replaces standard fopen with additional field initializations */
CustomFile *custom_fopen(const char *filename, const char *mode) {
    /* Allocate memory for our custom file structure */
    CustomFile *cfp = (CustomFile *)malloc(sizeof(CustomFile));
    if (!cfp) return NULL;

    /* Open the file using standard fopen. I chose to do this because im not sure if i had to go deep on this function as well. */
    cfp->fp = fopen(filename, mode);
    if (cfp->fp) {
        /* Determine if the file is opened in read mode */
        cfp->_flag.READ = (*mode == 'r') ? 1 : 0;
        /* Initially, we haven't reached the end of the file */
        cfp->_flag.END = 0;
        /* Buffer pointers are initially set to NULL */
        cfp->_base = NULL;
        cfp->_ptr = NULL;
        cfp->_cnt = 0;
    } else {
        /* If file opening fails, free the allocated memory */
        free(cfp);
        return NULL;
    }
    return cfp;
}

/* Custom buffer filling function */
int _fillbuf(CustomFile *cfp) {
    /* Check if the file is opened in read mode */
    if (!cfp->_flag.READ)
        return EOF;

    /* Allocate buffer space if it hasn't been allocated yet */
    if (cfp->_base == NULL) {
        if ((cfp->_base = (char *) malloc(BUFSIZ)) == NULL)
            return EOF;
    }

    /* Reset buffer pointer and fill buffer */
    cfp->_ptr = cfp->_base;
    cfp->_cnt = read(fileno(cfp->fp), cfp->_ptr, BUFSIZ);

    /* If no characters were read, set the end flag */
    if (cfp->_cnt <= 0) {
        cfp->_flag.END = 1;
        cfp->_cnt = 0;
        return EOF;
    }

    /* Return the character at the current pointer and increment the pointer */
    return (unsigned char) *cfp->_ptr++;
}

/* Custom getchar function using _fillbuf */
int _fillbuf_getchar(CustomFile *cfp) {
    /* Check if buffer is empty and if end of file has not been reached */
    if (cfp->_cnt <= 0 && !cfp->_flag.END) {
        return _fillbuf(cfp);
    } else if (cfp->_flag.END) {
        return EOF;
    }

    /* Decrement count and return character at the current buffer pointer */
    cfp->_cnt--;
    return (unsigned char) *cfp->_ptr++;
}

/* Function to analyze a file for lines, words, and characters */
void fileAnalyzer() {
    /* Use custom fopen to get the custom file structure */
    CustomFile *file = custom_fopen("text.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int ch, words = 0, lines = 0, characters = 0;

    /* Read through the file character by character */
    while ((ch = _fillbuf_getchar(file)) != EOF) {
        characters++;
        /* Increment word count on spaces or tabs */
        if (ch == ' ' || ch == '\t')
            words++;
        /* Increment both word and line counts on newline */
        if (ch == '\n') {
            lines++;
            words++;
        }
    }

    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);

    /* Cleanup */
    fclose(file->fp);
    free(file);
}

int main() {
    fileAnalyzer();
    return 0;
}
