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
    int  cnt;
    char *ptr;
    char *base;
    int  flag;
    int  fd;
} FILE;

enum _flags {
    _READ   = 01,
    _WRITE  = 02,
    _UNBUF  = 04,
    _EOF    = 010,
    _ERR    = 020
};

/* Pre-initializing first three slots for standard streams (stdin, stdout, stderr) */
FILE _iob[OPEN_MAX] = {
    {0, NULL, NULL, _READ, 0},
    {0, NULL, NULL, _WRITE, 1},
    {0, NULL, NULL, _WRITE | _UNBUF, 2}
};

int custom_flushbuf(int x, FILE *fp) {
    int num_written;

    /* If not writable or an error was previously encountered, we exit */
    if((fp->flag & (_WRITE | _ERR)) != _WRITE) {
        return EOF;
    }

    /* If there's no buffer, and it's not unbuffered mode, allocate buffer space */
    if(fp->base == NULL && ((fp->flag & _UNBUF) == 0)) {
        if((fp->base = (char *) malloc(BUFSIZ)) == NULL) {
            /* Memory allocation failure */
            fp->flag |= _ERR;
            return EOF;
        }
    } else {
        /* Flush out the buffer */
        num_written = write(fp->fd, fp->base, fp->ptr - fp->base);
        /* Ensure all buffered data was written out */
        if(num_written < fp->ptr - fp->base) {
            fp->flag |= _ERR;
            return EOF;
        }
    }

    /* Reinitialize buffer and store the given character */
    fp->ptr = fp->base;
    fp->cnt = BUFSIZ - 1;
    *fp->ptr++ = (char) x;
    return x;
}

int custom_fflush(FILE *fp) {
    int retval = 0;

    /* If fp is NULL, attempt to flush all open files */
    if(fp == NULL) {
        int i;
        for(i = 0; i < OPEN_MAX; i++) {
            if((_iob[i].flag & _WRITE) == 0 && custom_fflush(&_iob[i]) == -1) {
                retval = -1;
            }
        }
    } else {
        /* If it's not writable, return error */
        if((fp->flag & _WRITE) == 0) return -1;
        /* Flush the current buffer */
        custom_flushbuf(0, fp);
        /* If an error occurred during flush, return error */
        if(fp->flag & _ERR) retval = -1;
    }
    return retval;
}

int custom_fclose(FILE *fp) {
    int fd;

    /* If the file pointer is invalid, return error */
    if(fp == NULL) return -1;
    fd = fp->fd;

    /* Flush any buffered data before closing */
    custom_fflush(fp);

    /* Reset the file structure */
    fp->cnt = 0;
    fp->ptr = NULL;
    if(fp->base != NULL) free(fp->base);
    fp->base = NULL;
    fp->flag = 0;
    fp->fd = -1;

    /* Close the file using system close */
    return close(fd);
}

FILE *fopen(char *name, char *mode) {
    int fd;
    FILE *fp;

    /* Ensure the mode is valid */
    if(*mode != 'r' && *mode != 'w' && *mode != 'a') return NULL;

    /* Find an available file slot */
    for(fp = _iob; fp < _iob + OPEN_MAX; fp++) {
        if((fp->flag & (_READ | _WRITE)) == 0) break;
    }

    /* If all slots are occupied, return NULL */
    if(fp >= _iob + OPEN_MAX) return NULL;

    /* Open or create file based on the mode */
    if(*mode == 'w') {
        fd = creat(name, 0644);
    } else if(*mode == 'a') {
        if((fd = open(name, O_WRONLY)) < 0) {
            fd = creat(name, 0644);
        }
        lseek(fd, 0L, 2); /* Set position to the end for append mode */
    } else {
        fd = open(name, O_RDONLY);
    }

    /* If file opening/creation failed, return NULL */
    if(fd == -1) return NULL;

    /* Initialize the file structure */
    fp->fd = fd;
    fp->cnt = 0;
    fp->base = NULL;
    fp->flag = (*mode == 'r') ? _READ : _WRITE;
    return fp;
}

int custom_fseek(FILE *fp, long offset, int origin) {
    /* If the file is in write mode and there's data buffered, it needs to be flushed before we change position */
    if ((fp->flag & _WRITE) && fp->base && (fp->ptr > fp->base)) {
        custom_fflush(fp);
    }

    /* If the file is in read mode, we adjust the seek offset based on the buffered data
       This ensures that the seek action is in coordination with the buffered data */
    if (fp->flag & _READ) {
        if (origin == 1) {
            offset -= fp->cnt;
        }

        /* Reset the buffer pointers. This is necessary as we're changing the file position */
        fp->cnt = 0;
        fp->ptr = fp->base;
    }

    /* Use lseek to perform the actual file position change. If there's an error, return EOF */
    if (lseek(fp->fd, offset, origin) < 0) {
        return EOF;
    }

    /* Clear the end-of-file and error flags, as the file position has changed */
    fp->flag &= ~(_EOF | _ERR);
    return 0;
}

int main() {
    FILE *fp = fopen("text.txt", "w+");
    if(fp == NULL) {
        perror("Failed to open file");
        return 1;
    }
    char initialData[] = "This is the initial data.";
    for(int i = 0; initialData[i] != '\0'; i++) {
        custom_flushbuf(initialData[i], fp);
    }
    custom_fseek(fp, 0L, 0);
    char overwriteData[] = "Overwritten!";
    for(int i = 0; overwriteData[i] != '\0'; i++) {
        custom_flushbuf(overwriteData[i], fp);
    }
    custom_fflush(fp);
    custom_fclose(fp);
    return 0;
}
