#include <stdio.h>
#include <stdarg.h>

/* Declare the miniscanf function which takes a format string and a variable number of arguments */
void miniscanf(char *fmt, ...);

int main() {
    int day, month, year;
    char monthname[20];
    char *months[] = {
        "Jan", "Feb", "Mar", "Apr", "May", "Jun",
        "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"
    };

    printf("Enter a date (example, 22/8/2023): ");
    /* Use custom miniscanf function to read the date entered by the user */
    miniscanf("%d/%d/%d", &day, &month, &year);

    /* Check if the entered month is valid, and if so, convert the date format */
    if (month >= 1 && month <= 12) {
        strcpy(monthname, months[month-1]);
        printf("%d of %s %d\n", day, monthname, year);
    } else {
        printf("Invalid date format entered.\n");
    }

    return 0;
}

void miniscanf(char *fmt, ...) {
    /* Initialize the va_list ap */
    va_list ap;
    char *p;
    /* Pointer to hold the address of an integer argument */
    int *ival;
    /* Pointer to hold the address of a double argument */
    double *dval;
    /* Pointer to hold the address of a string argument */
    char *sval;

    /* The va_start macro is used to initialize the va_list variable to an argument list */
    va_start(ap, fmt);

    /* Loop through each character in the format string */
    for (p = fmt; *p; p++) {
        if (*p != '%') {
            continue;
        }

        /* Check the character after '%' to determine the type of data to read */
        switch(*++p) {
            case 'd':
                /* Get the next argument as an integer pointer */
                ival = va_arg(ap, int *);
                /* Read an integer from the standard input */
                scanf(" %d", ival);
                /* Consume the next character, which should be '/' */
                getchar();
                break;
            case 'f':
                /* Get the next argument as a double pointer */
                dval = va_arg(ap, double *);
                /* Read a double from the standard input */
                scanf("%lf", dval);
                break;
            case 's':
                /* Get the next argument as a string (char array) pointer */
                sval = va_arg(ap, char *);
                /* Read a string from the standard input */
                scanf("%s", sval);
                break;
            default:
                break;
        }
    }

    /* Clean up the va_list ap . this is mandatory. s*/
    va_end(ap);
}
