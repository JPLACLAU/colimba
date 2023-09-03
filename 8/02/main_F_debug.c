#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFSIZ 512

/* Define a struct with fields for the file flags. */
struct Flags {
    int READ;   /* 1 if set to read mode, 0 otherwise. */
    int END;    /* 1 if end of file reached, 0 otherwise. */
};

typedef struct CustomFile {
    FILE *fp;
    struct Flags _flag;
    char *_base;
    char *_ptr;
    int _cnt;
} CustomFile;

CustomFile *custom_fopen(const char *filename, const char *mode) {
    CustomFile *cfp = (CustomFile *)malloc(sizeof(CustomFile));
    if (!cfp) return NULL;

    cfp->fp = fopen(filename, mode);
    if (cfp->fp) {
        cfp->_flag.READ = (*mode == 'r') ? 1 : 0;
        cfp->_flag.END = 0;
        cfp->_base = NULL;     /* Initialize the buffer pointer to NULL */
        cfp->_ptr = NULL;      /* Initialize the current pointer to NULL */
        cfp->_cnt = 0;         /* Initialize the count to 0 */
    } else {
        free(cfp);
        return NULL;
    }
    return cfp;
}

int _fillbuf(CustomFile *cfp) {
    /* Debug statement */
    printf("Entering _fillbuf\n");
    if (!cfp->_flag.READ)
        return EOF;

    if (cfp->_base == NULL) {
        if ((cfp->_base = (char *) malloc(BUFSIZ)) == NULL)
            return EOF;
    }

    cfp->_ptr = cfp->_base;
    cfp->_cnt = read(fileno(cfp->fp), cfp->_ptr, BUFSIZ);
    /* Debug statement */
    printf("Read count: %d\n", cfp->_cnt);

    if (cfp->_cnt <= 0) {
        /* Debug statement */
        printf("End or error encountered\n");
        cfp->_flag.END = 1;
        cfp->_cnt = 0;
        return EOF;
    }

    return (unsigned char) *cfp->_ptr++;
}

int _fillbuf_getchar(CustomFile *cfp) {
    /* Debug statement */
    printf("Entering _fillbuf_getchar\n");
    /* Debug statement */
    printf("Count: %d, END flag: %d\n", cfp->_cnt, cfp->_flag.END);

    if (cfp->_cnt <= 0 && !cfp->_flag.END) {
        return _fillbuf(cfp);
    } else if (cfp->_flag.END) {
        return EOF;
    }

    cfp->_cnt--;
    return (unsigned char) *cfp->_ptr++;
}

void fileAnalyzer() {
    CustomFile *file = custom_fopen("text.txt", "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        return;
    }

    int ch, words = 0, lines = 0, characters = 0;

    while ((ch = _fillbuf_getchar(file)) != EOF) {
        characters++;
        if (ch == ' ' || ch == '\t')
            words++;
        if (ch == '\n') {
            lines++;
            words++;
        }
    }

    printf("Lines: %d\n", lines);
    printf("Words: %d\n", words);
    printf("Characters: %d\n", characters);

    fclose(file->fp);
    free(file);
}

int main() {
    fileAnalyzer();
    return 0;
}
