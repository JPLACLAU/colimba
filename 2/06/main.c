#include <stdio.h>
#include <stdlib.h>

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned mask = (1 << n) - 1;
    mask = ~(mask << p);
    x = x & mask;
    y = (y & ~mask) << p;
    return x | y;
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
    char binaryX[9], binaryY[9], result[9];
    unsigned x, y;
    int p, n;

    printf("\n8-bit byte called x\n");
    printf("This has to be a byte of 8 characters only of 0 and 1\n");
    printf("Enter value for x:\n");
    scanf("%8s%*c", binaryX);
    x = binaryToDecimal(binaryX);

    printf("\n8-bit byte called y\n");
    printf("This has to be a byte of 8 characters only of 0 and 1\n");
    printf("Enter value for y:\n");
    scanf("%8s%*c", binaryY);
    y = binaryToDecimal(binaryY);

    printf("\np is a position in x, where a bit-by-bit exchange is initiated with bits from y and to the right.\n");
    printf("This can only be a single digit number from 1 to 8\n" );
    printf("Enter value for p:\n");
    scanf("%d%*c", &p);

    printf("\nn is the number of bits that are switched to the right from position p\n");
    printf("This can only be a single digit number from 1 to 8\n" );
    printf("Enter value for n:\n");
    scanf("%d%*c", &n);

    decimalToBinary(setbits(x, p, n, y), result);
    printf("The result of setbits(x, p, n, y) is: %s\n", result);
    return 0;
}
