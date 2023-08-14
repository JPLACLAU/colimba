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
install("Nicolás Tagliafico", "3");
install("Gonzalo Montiel", "4");
install("Leandro Paredes", "5");
install("Germán Pezzella", "6");
install("Rodrigo De Paul", "7");
install("Marcos Acuña", "8");
install("Julián Alvarez", "9");
install("Lionel Messi", "10");
install("Angel Di María", "11");
install("Gerónimo Rulli", "12");
install("Cristian Romero", "13");
install("Exequiel Palacios", "14");
install("Angel Correa", "15");
install("Thiago Almada", "16");
install("Alejandro Gómez", "17");
install("Guido Rodríguez", "18");
install("Nicolás Otamendi", "19");
install("Alexis Mac Allister", "20");
install("Paulo Dybala", "21");
install("Lautaro Martínez", "22");
install("Emiliano Martínez", "23");
install("Enzo Fernández", "24");
install("Lisandro Martínez", "25");
install("Nahuel Molina", "26");
install("Lionel Scaloni", "DT");


    char *keys[] = {"Franco Armani", "Juan Foyth", "Nicolás Tagliafico",
                    "Gonzalo Montiel", "Leandro Paredes", "Germán Pezzella",
                    "Rodrigo De Paul", "Marcos Acuña", "Julián Alvarez",
                    "Lionel Messi", "Angel Di María", "Gerónimo Rulli",
                    "Cristian Romero", "Exequiel Palacios", "Angel Correa",
                    "Thiago Almada", "Alejandro Gómez", "Guido Rodríguez",
                    "Nicolás Otamendi", "Alexis Mac Allister", "Paulo Dybala",
                    "Lautaro Martínez", "Emiliano Martínez", "Enzo Fernández",
                    "Lisandro Martínez", "Nahuel Molina", "Lionel Scaloni",
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
    printf("Removing 'Ángel Correa'...\n");
    undef("Ángel Correa");
    printf("Removing 'Gerónimo Rulli'...\n");
    undef("Gerónimo Rulli");
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
