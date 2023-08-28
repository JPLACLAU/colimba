#include <stdio.h>
#include <stdlib.h>

/* This program will use only standard functions from libraries */
void filecopy(FILE *ifp, FILE *ofp) { /* ifp = input file, ofp = outputfile */
    int c;
    /* Loop that read and write all characters */
    while ((c = fgetc(ifp)) != EOF) {
        fputc(c, ofp);
    }
}

int main(void) {
    FILE *fp1, *fp2, *fp3;
    /* Placeholder for program name; useful for consistent error messages */
    char *prog = "cat_program";

    /* Opening text1.txt for reading; 'r' mode ensures it isn't altered */
    fp1 = fopen("text1.txt", "r");
    if (fp1 == NULL) {
        /* Display error message and exit if file can't be opened */
        fprintf(stderr, "%s: can't open text1.txt\n", prog);
        exit(1);
    }

    /* Opening text2.txt for reading */
    fp2 = fopen("text2.txt", "r");
    if (fp2 == NULL) {
        fprintf(stderr, "%s: can't open text2.txt\n", prog);
        fclose(fp1);
        exit(1);
    }

    /* Opening text3 for writing; 'w' mode creates/truncates file */
    fp3 = fopen("text3Standard.txt", "w");
    if (fp3 == NULL) {
        fprintf(stderr, "%s: can't open text3 for writing\n", prog);
        fclose(fp1);
        fclose(fp2);
        exit(1);
    }

    /* Using filecopy to concatenate contents */
    filecopy(fp1, fp3);
    filecopy(fp2, fp3);

    /* Close all files to free resources */
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);

    /* Check for any write errors on text3 */
    if (ferror(fp3)) {
        fprintf(stderr, "%s: error writing to text3\n", prog);
        exit(2);
    }

    return 0;
}
