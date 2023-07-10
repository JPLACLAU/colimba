#include <stdio.h>
#include <stdlib.h>



int main()
{
    printf("Exercise 1-6");
    printf("\n");
    printf("Verify that the expression getchar ( ) !« EOF is 0 or 1");
    printf("\n");
    int c;

    c= (getchar()!= EOF);

    printf("Verification: %u", c);
    return 0;
}
