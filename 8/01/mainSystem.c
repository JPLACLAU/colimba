#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFSIZ 512 /* buffer size for reading/writing */

void filecopy(int ifd, int ofd) { /* ifd = input file descriptor, ofd = output file descriptor */
    char buf[BUFSIZ];
    int n;
    /* Loop that reads and writes all characters */
    while ((n = read(ifd, buf, BUFSIZ)) > 0) {
        if (write(ofd, buf, n) != n) {
            perror("filecopy: write error");
            exit(2);
        }
    }
    if (n < 0) {
        perror("filecopy: read error");
        exit(3);
    }
}

int main(void) {
    int fd1, fd2, fd3;
    /* Placeholder for program name; useful for consistent error messages */
    char *prog = "cat_program";

    /* Opening text1.txt for reading */
    fd1 = open("text1.txt", O_RDONLY);
    if (fd1 == -1) {
        perror(prog);
        exit(1);
    }

    /* Opening text2.txt for reading */
    fd2 = open("text2.txt", O_RDONLY);
    if (fd2 == -1) {
        perror(prog);
        close(fd1);
        exit(1);
    }

    /* Opening text3System.txt for writing; O_CREAT and O_TRUNC flags ensure file is created or truncated */
    fd3 = open("text3System.txt", O_WRONLY | O_CREAT | O_TRUNC, 0666);
    if (fd3 == -1) {
        perror(prog);
        close(fd1);
        close(fd2);
        exit(1);
    }

    /* Using filecopy to concatenate contents */
    filecopy(fd1, fd3);
    filecopy(fd2, fd3);

    /* Close all file descriptors to free resources */
    close(fd1);
    close(fd2);
    close(fd3);

    return 0;
}
