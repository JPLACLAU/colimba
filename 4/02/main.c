#include <ctype.h>
#include <stdio.h>
#define MAXLINE 100


double atof(char s[]) {
    double val = 0.0, power = 1.0;
    int i, sign = 1, exp = 0, exp_sign = 1;

    /* ignore blanks */
    for (i = 0; isspace(s[i]); i++);

    /* check for sign */
    if (s[i] == '+' || s[i] == '-') {
        sign = (s[i] == '-') ? -1 : 1;
        i++;
    }

    /* convert integer  */
    for (; isdigit(s[i]); i++)
        val = 10.0 * val + (s[i] - '0');

    /* check for commas  */
    if (s[i] == '.') {
        i++;

        /* convert to fractional value */
        for (; isdigit(s[i]); i++) {
            val = 10.0 * val + (s[i] - '0');
            power *= 10.0;
        }
    }

    /* e is the equivalnce that a number if it is writen as 1.23e-4, it means 1.23 should be multiplied by 10^4. */
    if (s[i] == 'e' || s[i] == 'E') {
        i++;

        /* check for sign */
        if (s[i] == '+' || s[i] == '-') {
            exp_sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        /* convert the exponent */
        for (; isdigit(s[i]); i++)
            exp = 10 * exp + (s[i] - '0');
    }

    /* calculate the power of 10 for the exponent */
    while (exp > 0) {
        if (exp_sign > 0)
            power /= 10.0;
        else
            power *= 10.0;
        exp--;
    }

    return sign * val / power;
}

int getline(char s[], int lim) {
    int c, i;
    i = 0;
    while (--lim > 0 && (c=getchar()) != EOF && c != '\n')
        s[i++] = c;
    if (c == '\n')
        s[i++] = c;
    s[i] = '\0';
    return i;
}

/* rudimentary calculator */
int main() {
    double sum;
    char line[MAXLINE];
    sum = 0;

    while (getline(line, MAXLINE) > 0)
        printf("\t%g\n", sum += atof(line));

    return 0;
}
