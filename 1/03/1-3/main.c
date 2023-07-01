#include <stdio.h>
#include <stdlib.h>

/* print Fahrenheit-Celsus table
for fahr = 0, 20, ..., 300 */

    /* cero copy paste all typed manually */
    /* Punto 1-4: C to F */
    /* Tabla celsius -> fahr */

    main()
{
    printf("Table heading");
    printf("\n");
    printf("\n");

    float celsius, fahr;
    int lower, upper, step;

    lower = -20; /* lower limit of temperature table */
    upper = 150; /*upper limit*/ /*se modifica esto para el 1-3*/
    step = 10; /* step size */

    celsius = lower;
    while (celsius <= upper) {
        fahr = (celsius *(9.0/5.0))+ 32;
        printf("%3.0f  %6.0f \n", celsius, fahr);
        celsius = celsius + step;

    }
}
