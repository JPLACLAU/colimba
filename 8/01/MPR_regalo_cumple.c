#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void imprimirTortaConVelas(int edad);
void imprimirTortaSinVelas();

int main() {
    int edad;
    char deseo[256];

    printf("Feliz Cumpleanios, Mariano!!! \nTambien conocido como MPR en La crypta...\nY como Sensei en la famosisima colimba de programacion... \n\n");
    printf("Nueva edad de Mariano: ");
    scanf("%d", &edad);
    getchar();

    imprimirTortaConVelas(edad);

    printf("\nHace 3 deseos y toca Enter para soplar las velitas...\n");

    for(int i = 1; i <= 3; i++) {
        printf("Deseo %d: ", i);
        fgets(deseo, sizeof(deseo), stdin);
    }

    imprimirTortaSinVelas();
    printf("\nDeseos guardados: Tus deseos se van a hacer realidad proximamente!\nQue tengas un cumpleanios muy feliz!\n\n\n\n");

    return 0;
}

void imprimirTortaConVelas(int edad) {


    for(int i = 0; i < edad; i++) {
        printf("i");
    }
    printf("\n");

    for(int i = 0; i < edad; i++) {
        printf("|");
    }
    printf("\n");

    printf("             ,   ,   ,   ,             \n");
    printf("           , |_,_|_,_|_,_| ,           \n");
    printf("       _,-=|;  |,  |,  |,  |;=-_       \n");
    printf("     .-_| , | , | , | , | , |  _-.     \n");
    printf("     |:  -|:._|___|___|__.|:=-  :|     \n");
    printf("     ||*:  :    .     .    :  |*||     \n");
    printf("     || |  | *  |  *  |  * |  | ||     \n");
    printf(" _.-=|:*|  |    |     |    |  |*:|=-._ \n");
    printf("-    `._:  | *  |  *  |  * |  :_.'    -\n");
    printf(" =_      -=:.___:_____|___.: =-     _= \n");
    printf("    - . _ __ ___  ___  ___ __ _ . -    \n\n");

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("|  FELIZ CUMPLE MARIANO!  |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

void imprimirTortaSinVelas() {
    printf("\n             |_ _|_ _|_ _|             \n");
    printf("       _ -=|   |   |   |   | =-_       \n");
    printf("     .-_|   |   |   |   |   |  _-.     \n");
    printf("     |:  -|:._|___|___|__.|:=-  :|     \n");
    printf("     ||*:  :    .     .    :  |*||     \n");
    printf("     || |  | *  |  *  |  * |  | ||     \n");
    printf(" _.-=|:*|  |    |     |    |  |*:|=-._ \n");
    printf("-    `._:  | *  |  *  |  * |  :_.'    -\n");
    printf(" =_      -=:.___:_____|___.: =-     _= \n");
    printf("    - . _ __ ___  ___  ___ __ _ . -    \n");

    printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    printf("|  FELIZ CUMPLE MARIANO!  |\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}
