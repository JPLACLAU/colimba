#include <stdio.h>
#include <stdlib.h>

unsigned rightrot(unsigned x, int n) {
    /* Get the number of bits of unsigned */
    int bitCount = sizeof(x) * 8;
    /* Compute the effective amount of rotation */
    n = n % bitCount;
    /* Rotate x to the right by n positions */
    return (x >> n) | (x << (bitCount - n));
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
    int n;

    printf("\n8-bit byte called x\n");
    printf("This has to be a byte of 8 characters only of 0 and 1\n");
    printf("Enter value for x:\n");
    scanf("%8s%*c", binaryX);
    x = binaryToDecimal(binaryX);

    printf("\nn is the number of positions that x will be rotated to the right\n");
    printf("This can only be a single digit number from 0 to 7\n");
    printf("Enter value for n:\n");
    scanf("%d%*c", &n);

    decimalToBinary(rightrot(x, n), result);
    printf("The result of rightrot(x, n) is: %s\n", result);
    return 0;
}
