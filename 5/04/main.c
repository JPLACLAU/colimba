#include <stdio.h>

void p_strcat(char *s, char *t) {
    while (*s)
        s++;
    while ((*s++ = *t++))
        ;
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

    return 0;
}
