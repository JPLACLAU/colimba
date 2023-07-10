#include <stdio.h>
#include <stdlib.h>

#define LIM 100

int main()
{
    int i = 0;
    int c;
    /* int lim = 100; PREGUNTA */

    /* Declare and initialize the array with size LIM */
    char s[LIM];

while (i < LIM - 1) /* arrays start with 0 so max is 99 in this case */
    {
        c = getchar();

        if (c != '\n')
        {
            if (c != EOF)
            {
                s[i] = c;
                ++i;
            }
            else
            {
                /*  EOF case */
                i = LIM;
            }
        }
        else
        {
            /*  '\n' case */
            i = LIM;
        }
    }

    printf(" %s", s); /* print input saved on array s */

    return 0;
}
