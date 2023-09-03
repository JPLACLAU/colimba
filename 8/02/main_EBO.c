#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

/* BUFSIZ is typically set to 1024 because it's a power of 2*/
#define BUFSIZ 512

/* Define flags using single bits to represent multiple states. I only use the _READ flag */
enum _flags {
    _READ = 01
};

int _fillbuf(FILE *fp) {
    /* Use a bitwise AND operation to check if the file is in read mode.
       This is an efficient way to test for a specific condition without checking all other flags. */
    if (!(fp->_flag & _READ))
        return EOF;

    /* If buffer isn't allocated, allocate memory for buffering data. */
    if (fp->_base == NULL) {
        if ((fp->_base = (char *) malloc(BUFSIZ)) == NULL)
            return EOF;
    }

    /* Reset pointer to the beginning of the buffer. */
    fp->_ptr = fp->_base;

    /* Populate the buffer with data from the file. */
    fp->_cnt = read(fileno(fp), fp->_ptr, BUFSIZ);

    /* Check if we've reached the end or an error occurred during reading. */
    if (--fp->_cnt < 0) {
        fp->_cnt = 0;
        return EOF;
    }

    /* Return the next character from the buffer. */
    return (unsigned char) *fp->_ptr++;
}

int _fillbuf_getchar(FILE *fp) {
    /* If the buffer is empty, refill it to avoid accesing garbage values when re entering */
    if (fp->_cnt <= 0) {
        return _fillbuf(fp);
    }

    /* Decrease the count and return the next character from the buffer. */
    fp->_cnt--;
    return (unsigned char) *fp->_ptr++;
}

void fileAnalyzer() {
    /* Open the file in read mode. */
    FILE *file = fopen("text.txt", "r");

    /* If the file fails to open, print an error */
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int ch, words = 0, lines = 0, characters = 0;

    /* Read the file character by character. */
    while ((ch = _fillbuf_getchar(file)) != EOF) {
        characters++;

        /* Count words. */
        if (ch == ' ' || ch == '\t')
            words++;

        /* Count lines. */
        if (ch == '\n') {
            lines++;
            words++;
        }
    }

    /* Print results. */
    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);

    /* close the file to free system resources. */
    fclose(file);
}

int main() {
    /* Start the file analysis. */
    fileAnalyzer();
    return 0;
}
