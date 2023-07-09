#include <stdio.h>

/* Exercise 1-22. Write a program to "fold" long input lines into two or more
 * shorter lines after the last non-blank character that occurs before the n-th
 * column of input. Make sure your program does something intelligent with very
 * long lines, and if there are no blanks or tabs before the specified column.
 */

/* parsing states */
#define IN 0
#define OUT 1
#define SKIP 2

/* length to fold input lines to */
#define MAX_LEN 10

/* how many spaces does a TAB character take */
#define TAB_WIDTH 8

int main(void) {
    unsigned int state = SKIP;                                    /* parsing state (start by skipping blanks)                      */

    char c = 0;                                                   /* character being read                                          */
    char bBuffer[MAX_LEN + 1];                                    /* blanks buffer (extra space for terminator)                    */
    char nBuffer[MAX_LEN + 1];                                    /* non-blanks buffer (extra space for terminator)                */

    unsigned int bi = 0;                                          /* index into blanks buffer                                      */
    unsigned int ni = 0;                                          /* index into non-blanks buffer                                  */

    unsigned int bl = 0;                                          /* length of blanks in buffer                                    */
    unsigned int nl = 0;                                          /* length of non-blanks in buffer                                */
    unsigned int l = 0;                                           /* length of characters written so far                           */

    while ((c = getchar()) != EOF) {                              /* continue until EOF is found                                   */
        if ('\n' == c) {                                          /* ==== EARLY NEWLINE TREATMENT ====                             */
            bBuffer[bi] = nBuffer[ni] = '\0';                     /* add terminators to buffers                                    */
            if (l + bl + nl <= MAX_LEN) {                         /* if there's space in the current output line...                */
                printf("%s%s\n", bBuffer, nBuffer);               /*     print buffers and newline                                 */
            } else {                                              /* ... otherwise...                                              */
                printf(0 == l ? "%s\n" : "\n%s\n", nBuffer);      /*     print buffer (maybe on its own line), and add newline     */
            }                                                     /* end                                                           */
            l = 0;                                                /* no characters in our current (new) line                       */
            bi = ni = bl = nl = 0;                                /* reset buffer indexes and lengths                              */
            state = SKIP;                                         /* after a newline, we skip blanks                               */

                  } else if (SKIP == state) {                               /* ==== SKIPPING INITIAL BLANKS ====                             */
            if (' ' == c || '\t' == c) {                          /* if we find a blank...                                         */
                ;                                                 /*     we keep skipping                                          */
            } else {                                              /* ... otherwise ...                                             */
                nBuffer[ni++] = c;                                /*     store character as non-blank and increase index           */
                nl += 1;                                          /*     adjust non-blanks length                                  */
                state = IN;                                       /*     we're now inside if a word                                */
            }
                    } else if (state == OUT) {                                /* ==== OUTSIDE OF A WORD ====                                   */
            if (' ' == c || '\t' == c) {                          /* if we find a blank...                                         */
                bBuffer[bi++] = c;                                /*     store character as blank and increase index               */
                bl += '\t' == c ? TAB_WIDTH : 1;                  /*     adjust blank length (considering tab width)               */
            } else {                                              /* ... otherwise...                                              */
                nBuffer[ni++] = c;                                /*     store character as non-blank and increase index           */
                nl += 1;                                          /*     adjust non-blanks length                                  */
                state = IN;                                       /*     we're now inside of a word                                */
            }                                                     /* end                                                           */

                    } else if (IN == state) {                                 /* ==== INSIDE OF A WORD ====                                    */
            if (' ' == c || '\t' == c) {                          /* if we find a blank...                                         */
                bBuffer[bi] = nBuffer[ni] = '\0';                 /*     add terminators to buffers                                */
                if (l + bl + nl <= MAX_LEN) {                     /*     if there's space in the current output line...            */
                    printf("%s%s", bBuffer, nBuffer);             /*         print buffers                                         */
                    l += bl + nl;                                 /*         adjust current output line length                     */
                } else {                                          /*     ... otherwise...                                          */
                    printf(0 == l ? "%s" : "\n%s", nBuffer);      /*         print buffer (maybe on its own line)                  */
                    l = nl;                                       /*         adjust current output line length                     */
                }                                                 /*     end                                                       */
                bi = ni = bl = nl = 0;                            /*     reset buffer indexes and lengths                          */
                bBuffer[bi++] = c;                                /*     store character in blanks buffer                          */
                bl += '\t' == c ? TAB_WIDTH : 1;                  /*     adjust blank length (considering tab width)               */
                state = OUT;                                      /*     we're now outside of a word                               */


                        } else {                                              /* ... otherwise...                                              */
                if (MAX_LEN <= nl) {                              /*     if the non-blanks would fill a complete output line...    */
                    nBuffer[ni] = '\0';                           /*         add terminator to non-blanks buffer                   */
                    printf(0 == l ? "%s\n" : "\n%s\n", nBuffer);  /*         print buffer (maybe on its own line), and add newline */
                    l = 0;                                        /*         no characters in out current (new) line               */
                    bi = ni = bl = nl = 0;                        /*         reset buffer indexes and lengths                      */
                }                                                 /*     end                                                       */
                nBuffer[ni++] = c;                                /*     store character as non-blank and increase index           */
                nl += 1;                                          /*     adjust non-blanks length                                  */
            }                                                     /* end                                                           */
        }                                                         /* ==== END ====                                                 */
    }                                                             /* ==== REAMINING CHARACTERS TREATMENT ====                      */


        bBuffer[bi] = nBuffer[ni] = '\0';                             /* add terminators to buffers                                    */
    if (l + bl + nl <= MAX_LEN) {                                 /* if there's space in the current output line...                */
        printf("%s%s\n", bBuffer, nBuffer);                       /*     print buffers and newline                                 */
    } else {                                                      /* ... otherwise...                                              */
        printf(0 == l ? "%s\n" : "\n%s\n", nBuffer);              /*     print buffer (maybe on its own line), and add newline     */
    }                                                             /* end                                                           */

    return 0;
}


