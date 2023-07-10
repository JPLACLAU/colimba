#include <stdio.h>
#include <limits.h>
#include <float.h>

int main() {
    /* char */
    printf("The range of signed char is from %d to %d\n", SCHAR_MIN, SCHAR_MAX);
    printf("The range of unsigned char is from 0 to %d\n", UCHAR_MAX);

    /* short */
    printf("The range of signed short is from %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("The range of unsigned short is from 0 to %d\n", USHRT_MAX);

    /* int */
    printf("The range of signed int is from %d to %d\n", INT_MIN, INT_MAX);
    printf("The range of unsigned int is from 0 to %u\n", UINT_MAX);

    /* long */
    printf("The range of signed long is from %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("The range of unsigned long is from 0 to %lu\n", ULONG_MAX);

    /* floating point types */
    printf("The range of float is from %e to %e\n", FLT_MIN, FLT_MAX);
    printf("The range of double is from %e to %e\n", DBL_MIN, DBL_MAX);
    printf("The range of long double is from %Le to %Le\n", LDBL_MIN, LDBL_MAX);

    return 0;
}
