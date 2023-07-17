#include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y) {
    unsigned mask_y = (~(~0 << n)) & y;
    mask_y = mask_y << (p + 1 - n);
    unsigned mask_x = ~((~(~0 << n)) << (p + 1 - n));
    x = x & mask_x;
    x = x | mask_y;
    return x;
}

int main() {
    unsigned x = 12;
    int p = 4;
    int n = 3;
    unsigned y = 18;
    unsigned result = setbits(x, p, n, y);
    printf("The result is: %u\n", result);
    return 0;

}
