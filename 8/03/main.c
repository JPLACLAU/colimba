#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

#ifndef NULL
#define NULL      0
#endif
#define EOF       (-1)
#define BUFSIZ    1024
#define OPEN_MAX  20

typedef struct _iobuf {
    int  cnt;        /* Characters left */
    char *ptr;       /* Next character position */
    char *base;      /* Location of buffer */
    int  flag;       /* Mode of the file access */
    int  fd;         /* File descriptor */
} FILE;

enum _flags {
    _READ   = 01,
    _WRITE  = 02,
    _UNBUF  = 04,
    _EOF    = 010,
    _ERR    = 020
};

extern FILE _iob[OPEN_MAX];

/*
This array of FILE structures (basically a custom version of the standard I/O library's
internal file table) is initialized for stdin, stdout, and stderr.
The other entries are left empty for now.
*/
FILE _iob[OPEN_MAX] = {
    {0, NULL, NULL, _READ, 0},
    {0, NULL, NULL, _WRITE, 1},
    {0, NULL, NULL, _WRITE | _UNBUF, 2}
};


int custom_flushbuf(int x, FILE *fp) {
    int num_written;

    /* If the file isn't open for writing or if an error flag is set, return EOF */
    if((fp->flag & (_WRITE | _ERR)) != _WRITE) {
        return EOF;
    }

    /*
    If the file hasn't been buffered before and it's not set for unbuffered operation,
    allocate a buffer for it.
    */
    if(fp->base == NULL && ((fp->flag & _UNBUF) == 0)) {
        if((fp->base = (char *) malloc(BUFSIZ)) == NULL) {
            /* If we can't allocate memory, set the error flag and return EOF */
            fp->flag |= _ERR;
            return EOF;
        }
    } else {
        /* If there's buffered data, write it out to the file */
        num_written = write(fp->fd, fp->base, fp->ptr - fp->base);
        if(num_written < fp->ptr - fp->base) {
            /* If not all the data was written, set the error flag and return EOF */
            fp->flag |= _ERR;
            return EOF;
        }
    }

    /* Reset the buffer pointers and place the character x into the buffer */
    fp->ptr = fp->base;
    fp->cnt = BUFSIZ - 1;
    *fp->ptr++ = (char) x;
    return x;
}


int custom_fflush(FILE *fp) {
    int retval = 0;
    if(fp == NULL) {
        int i;
        /* If given file pointer is NULL, try to flush buffers for all open output files */
        for(i = 0; i < OPEN_MAX; i++) {
            if((_iob[i].flag & _WRITE) == 0 && custom_fflush(&_iob[i]) == -1) {
                retval = -1;
            }
        }
    } else {
        /* If the file isn't open for writing, return an error */
        if((fp->flag & _WRITE) == 0) return -1;
        /* Call the custom_flushbuf to actually perform the buffer flushing */
        custom_flushbuf(0, fp);
        /* If any errors occurred during flushing, return -1 */
        if(fp->flag & _ERR) retval = -1;
    }
    return retval;
}


int custom_fclose(FILE *fp) {
    int fd;

    /* If the file pointer is NULL, return error */
    if(fp == NULL) return -1;
    fd = fp->fd;
    /* Flush any buffered data */
    custom_fflush(fp);
    /* Reset the buffer and the flags */
    fp->cnt = 0;
    fp->ptr = NULL;
    if(fp->base != NULL) free(fp->base);
    fp->base = NULL;
    fp->flag = 0;
    fp->fd = -1;
    /* Close the file */
    return close(fd);
}

FILE *fopen(char *name, char *mode) {
    int fd;
    FILE *fp;

    /* Check the mode is valid */
    if(*mode != 'r' && *mode != 'w' && *mode != 'a') return NULL;
    /* Find an empty slot in our file table */
    for(fp = _iob; fp < _iob + OPEN_MAX; fp++) {
        if((fp->flag & (_READ | _WRITE)) == 0) break;
    }
    /* If all slots are used, return NULL */
    if(fp >= _iob + OPEN_MAX) return NULL;

    /* Handle different modes: read, write, or append */
    if(*mode == 'w') {
        fd = creat(name, 0644);
    } else if(*mode == 'a') {
        if((fd = open(name, O_WRONLY)) < 0) {
            fd = creat(name, 0644);
        }
        lseek(fd, 0L, 2);
    } else {
        fd = open(name, O_RDONLY);
    }

    if(fd == -1) return NULL;
    /* Set the file descriptor and initialize the buffer and flags */
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = (*mode == 'r') ? _READ : _WRITE;
    return fp;
}

int main() {
    FILE *fp = fopen("text.txt", "w");
    if(fp == NULL) {
        perror("Failed to open file");
        return 1;
    }

    char data[] = "Exercise 8-3: Design and write `_flushbuf`, `fflush`, and `fclose`.";
    for(int i = 0; data[i] != '\0'; i++) {
        custom_flushbuf(data[i], fp);
    }

    custom_fflush(fp);
    custom_fclose(fp);

    return 0;
}
