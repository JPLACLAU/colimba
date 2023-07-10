#include <stdio.h>
#include <stdlib.h>

unsigned invert(unsigned x, int p, int n) {
    /* Generate mask with n bits set to 1 at position p */
    unsigned mask = ((1 << n) - 1) << p;
    /* Invert bits at positions specified by mask */
    return x ^ mask;
}

unsigned binaryToDecimal(char *binary){
    return (unsigned) strtol(binary, NULL, 2);
}

void decimalToBinary(unsigned n, char *binary) {
    for(int i = 7; i >= 0; --i, n >>= 1)
        binary[i] = (char)((n & 1) + '0');
    binary[8] = '\0';
}

int main() {
    char binaryX[9], result[9];
    unsigned x;
    int p, n;

    printf("\n8-bit byte called x\n");
    printf("This has to be a byte of 8 characters only of 0 and 1\n");
    printf("Enter value for x:\n");
    scanf("%8s%*c", binaryX);
    x = binaryToDecimal(binaryX);

    printf("\np is a position in x, where an inversion of bits is initiated and moves to the right.\n");
    printf("This can only be a single digit number from 0 to 7\n" );
    printf("Enter value for p:\n");
    scanf("%d%*c", &p);

    printf("\nn is the number of bits that are inverted to the right from position p\n");
    printf("This can only be a single digit number from 1 to 8\n" );
    printf("Enter value for n:\n");
    scanf("%d%*c", &n);

    decimalToBinary(invert(x, p, n), result);
    printf("The result of invert(x, p, n) is: %s\n", result);
    return 0;
}
