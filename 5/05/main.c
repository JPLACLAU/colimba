#include <stdio.h>

void p_strcat(char *s, char *t) {
    while (*s)
        s++;
    while ((*s++ = *t++))
        ;
}

void strncpy(char *s, char *t, int n) {
    int i = 0;
    while (i < n && (*s++ = *t++))
        i++;
    while (i < n) {
        *s++ = '\0';
        i++;
    }
}

void strncat(char *s, char *t, int n) {
    while (*s)
        s++;
    while (n-- > 0 && (*s++ = *t++))
        ;
    *s = '\0';
}

int strncmp(char *s, char *t, int n) {
    for (; n > 0; s++, t++, n--)
        if (*s != *t)
            return *s - *t;
    return 0;
}

int strend(char *s, char *t) {
    char *s_original = s;
    char *t_original = t;

    while (*s)
        s++;
    while (*t)
        t++;

    if (s - s_original < t - t_original)
        return 0;

    while (t > t_original)
        if (*--s != *--t)
            return 0;

    return 1;
}

int main() {
    char s[100] = "123";
    char t[] = "456";
    char u[] = "456";

    /* p_strcat */
    p_strcat(s, t);
    printf("s+t: %s\n", s);

    /* strend */
    int result = strend(s, u);
    printf("Does '%s' occur at the end of '%s'? %s\n", u, s, result ? "Yes" : "No");

    /* strncpy */
    strncpy(s, u, 2);
    printf("strncpy(s, u, 2): %s\n", s);

    /* strncat */
    strncat(s, t, 2);
    printf("strncat(s, t, 2): %s\n", s);

    /* strncmp */
    int compare_result = strncmp(s, u, 3);
    printf("strncmp(s, u, 3): %d\n", compare_result);

    return 0;
}
