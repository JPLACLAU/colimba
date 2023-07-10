#include <stdio.h>
#include <stdlib.h>


float c_to_f(int celsius) {
    return celsius * 9.0/5.0 + 32;
}

int main() {
    printf("\n------------\n\n");
    printf("Exercise 1-15");
    printf("\n");
    printf("Write a program to print a histogram of the frequencies of different characters in its input");
    printf("\n\n------------\n");



    int celsius;
    printf("------------\n\n");
    printf("Celsius Fahrenheit");
    printf("\n\n------------\n\n");

    for (celsius = 0; celsius <= 100; celsius += 5) {
        printf("%7d %10.1f\n", celsius, c_to_f(celsius));
    }
    return 0;
}


