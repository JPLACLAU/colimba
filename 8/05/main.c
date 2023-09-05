#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

/* Function to print the information contained in the inode entry */
void print_inode_info(const char *name, const struct stat *stbuf) {
    printf("File: %s\n", name);
    /* Displaying the inode number of the file */
    printf("Inode Number: %ld\n", (long)stbuf->st_ino);

    /* Determining and displaying the file type */
    printf("File Type: ");
    switch (stbuf->st_mode & S_IFMT) {
        case S_IFREG: printf("Regular File\n"); break;
        case S_IFDIR: printf("Directory\n"); break;
        default: printf("Other\n"); break;
    }

    /* Displaying the file permissions */
    printf("Permissions: %o\n", stbuf->st_mode & ~S_IFMT);

    /* Displaying the number of hard links */
    printf("Number of Hard Links: %u\n", stbuf->st_nlink);

    /* Displaying owner and group ID of the file */
    printf("Owner ID: %d\n", stbuf->st_uid);
    printf("Group ID: %d\n", stbuf->st_gid);

    /* Displaying the file size */
    printf("File Size: %ld bytes\n", (long)stbuf->st_size);

    /* Displaying the timestamps for the file */
    printf("Last Access Time: %ld\n", (long)stbuf->st_atime);
    printf("Last Modification Time: %ld\n", (long)stbuf->st_mtime);
    printf("Last Status Change Time: %ld\n", (long)stbuf->st_ctime);
    printf("\n");
}

void fsize(char *name) {
    struct stat stbuf;

    /* Using the stat function to get the inode information */
    if (stat(name, &stbuf) == -1) {
        fprintf(stderr, "fsize: can't access %s\n", name);
        return;
    }

    /* If the file is not a directory, we display its inode information */
    print_inode_info(name, &stbuf);
}

int main() {
    char filename[] = "text.txt";
    /* Calling the function on the specified file "text.txt" */
    fsize(filename);
    return 0;
}
