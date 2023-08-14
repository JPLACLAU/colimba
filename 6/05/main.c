#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define HASHSIZE 101

struct nlist {
    struct nlist *next; /* next entry in chain */
    char *name;         /* defined name */
    char *defn;         /* replacement text */
};

static struct nlist *hashtab[HASHSIZE]; /* pointer table */

unsigned hash(char *s) {
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
        hashval = *s + 31 * hashval;
    return hashval % HASHSIZE;
}

struct nlist *lookup(char *s) {
    struct nlist *np;
    for (np = hashtab[hash(s)]; np != NULL; np = np->next)
        if (strcmp(s, np->name) == 0)
            return np; /* found */
    return NULL; /* not found */
}

struct nlist *install(char *name, char *defn) {
    struct nlist *np;
    unsigned hashval;
    if ((np = lookup(name)) == NULL) {
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np;
    } else {
        free((void *)np->defn); /* already there, free previous defn */
    }
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}

void undef(char *s) {
    struct nlist *np1, *np2;
    unsigned hashval = hash(s);

    for (np1 = hashtab[hashval], np2 = NULL;
         np1 != NULL;
         np2 = np1, np1 = np1->next) {
        if (strcmp(s, np1->name) == 0) {
            /* found a match */
            free(np1->name);
            free(np1->defn);
            if (np2 == NULL) {
                /* beginning? */
                hashtab[hashval] = np1->next;
            } else {
                /* middle or end? */
                np2->next = np1->next;
            }
            free(np1);
            return;
        }
    }
}

int main() {
install("Franco Armani", "1");
install("Juan Foyth", "2");
install("Nicol�s Tagliafico", "3");
install("Gonzalo Montiel", "4");
install("Leandro Paredes", "5");
install("Germ�n Pezzella", "6");
install("Rodrigo De Paul", "7");
install("Marcos Acu�a", "8");
install("Juli�n Alvarez", "9");
install("Lionel Messi", "10");
install("Angel Di Mar�a", "11");
install("Ger�nimo Rulli", "12");
install("Cristian Romero", "13");
install("Exequiel Palacios", "14");
install("Angel Correa", "15");
install("Thiago Almada", "16");
install("Alejandro G�mez", "17");
install("Guido Rodr�guez", "18");
install("Nicol�s Otamendi", "19");
install("Alexis Mac Allister", "20");
install("Paulo Dybala", "21");
install("Lautaro Mart�nez", "22");
install("Emiliano Mart�nez", "23");
install("Enzo Fern�ndez", "24");
install("Lisandro Mart�nez", "25");
install("Nahuel Molina", "26");
install("Lionel Scaloni", "DT");


    char *keys[] = {"Franco Armani", "Juan Foyth", "Nicol�s Tagliafico",
                    "Gonzalo Montiel", "Leandro Paredes", "Germ�n Pezzella",
                    "Rodrigo De Paul", "Marcos Acu�a", "Juli�n Alvarez",
                    "Lionel Messi", "Angel Di Mar�a", "Ger�nimo Rulli",
                    "Cristian Romero", "Exequiel Palacios", "Angel Correa",
                    "Thiago Almada", "Alejandro G�mez", "Guido Rodr�guez",
                    "Nicol�s Otamendi", "Alexis Mac Allister", "Paulo Dybala",
                    "Lautaro Mart�nez", "Emiliano Mart�nez", "Enzo Fern�ndez",
                    "Lisandro Mart�nez", "Nahuel Molina", "Lionel Scaloni",
                    "UNKNOWN"};

    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        struct nlist *result = lookup(keys[i]);
        if (result != NULL) {
            printf("Found: %s -> %s\n", result->name, result->defn);
        } else {
            printf("Not found: %s\n", keys[i]);
        }
    }

    /* removing players using undef */
    printf("\nRemoving 'Juan Foyth'...\n");
    undef("Juan Foyth");
    printf("Removing '�ngel Correa'...\n");
    undef("�ngel Correa");
    printf("Removing 'Ger�nimo Rulli'...\n");
    undef("Ger�nimo Rulli");
    printf("Removing 'Franco Armani'...\n");
    undef("Franco Armani");

    /* reprinting list after removing players with undef */
    printf("\n\nNew list of players with some players removed with undef:\n\n");
    for (int i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        struct nlist *result = lookup(keys[i]);
        if (result != NULL) {
            printf("Found: %s -> %s\n", result->name, result->defn);
        } else {
            printf("Not found: %s\n", keys[i]);
        }
    }

    return 0;
}
