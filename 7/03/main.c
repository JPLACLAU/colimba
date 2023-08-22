#include <stdio.h>
#include <stdarg.h>

void minprintf(const char *fmt, ...) {
    va_list ap;
    va_start(ap, fmt);

    for (; *fmt; fmt++) {
        if (*fmt != '%') {
            putchar(*fmt);
            continue;
        }

        switch (*++fmt) {
            case 'd':
            case 'i':
                printf("%d", va_arg(ap, int));
                break;
            case 'o':
                printf("%o", va_arg(ap, unsigned int));
                break;
            case 'x':
            case 'X':
                printf("%x", va_arg(ap, unsigned int));
                break;
            case 'u':
                printf("%u", va_arg(ap, unsigned int));
                break;
            case 'c':
                putchar(va_arg(ap, int));
                break;
            case 's':
                printf("%s", va_arg(ap, char *));
                break;
            case 'f':
                printf("%f", va_arg(ap, double));
                break;
            case 'e':
            case 'E':
                printf("%e", va_arg(ap, double));
                break;
            case 'g':
            case 'G':
                printf("%g", va_arg(ap, double));
                break;
            case 'p':
                printf("%p", va_arg(ap, void *));
                break;
            default:
                putchar(*fmt);
                break;
        }
    }

    va_end(ap);
}

int main() {
    int a = 21;
    double b = 20.999999;
    /* Testing minprintf function */
    minprintf("Testing miniprintf, a smaller version of printf\nThe number printed is int a=21\n");
    minprintf("Hex (lowercase): %x\n", a);
    minprintf("Hex (uppercase): %X\n", a);
    minprintf("Integer: %d\n", a);
    minprintf("Unsigned: %u\n", a);
    minprintf("Octal: %o\n", a);
    minprintf("Pointer: %p\n", &a);
    minprintf("\nThe number printed is int b=20.999999\n");
    minprintf("Floating point: %f\n", b);
    minprintf("Scientific: %e\n", b);
    minprintf("General: %g\n", b);
    minprintf("Char: %c\n", 'T');

    return 0;
}

