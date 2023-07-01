#include <stdio.h>
#include <stdlib.h>


/* copy input to output; 1st version */

int main()
{
    printf("Exercise 1-6");
    printf("\n");
    printf("Verify that the expression getchar ( ) !« EOF is 0 or 1");
    printf("\n");
    int c;

    c= (getchar()!= EOF);

    printf("c", c);
    return 0;
}
