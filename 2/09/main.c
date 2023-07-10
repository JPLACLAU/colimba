#include <stdio.h>
#include <stdlib.h>

unsigned binaryToDecimal(char *binary){
    return (unsigned) strtol(binary, NULL, 2);
}

void decimalToBinary(unsigned n, char *binary) {
    for(int i = 7; i >= 0; --i, n >>= 1)
        binary[i] = (char)((n & 1) + '0');
    binary[8] = '\0';
}

int bitcount(unsigned x) {
    int b;
    for (b = 0; x != 0; x &= (x-1))
        ++b;
    return b;
}

int main() {
    char binaryX[9];
    unsigned x;

    printf("\n8-bit byte called x\n");
    printf("This has to be a byte of 8 characters only of 0 and 1\n");
    printf("Enter value for x:\n");
    scanf("%8s%*c", binaryX);
    x = binaryToDecimal(binaryX);

    printf("The number of set bits in x is: %d\n", bitcount(x));
    return 0;
}
