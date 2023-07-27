#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h> //for sin, cos, exp, log, pow functions

#define MAXOP 100
#define NUMBER '0'
#define MAXVAL 100
#define BUFSIZE 100

#define OP_NUM '0'
#define OP_TOP 't'
#define OP_DUP 'd'
#define OP_SWP 's'
#define OP_CLR 'c'
#define OP_POP 'p'

#define OP_SIN 'i'
#define OP_COS 'o'
#define OP_EXP 'e'
#define OP_LOG 'l'
#define OP_POW 'w'
#define OP_UNK 'u'

char buf[BUFSIZE];
int bufp = 0;

int sp = 0;
double val[MAXVAL];

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

void push(double f) {
    if (sp < MAXVAL)
        val[sp++] = f;
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
    if (sp > 0)
        return val[--sp];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

double print_top(void) {
    if (sp > 0)
        return val[sp - 1];
    else {
        printf("error: stack empty\n");
        return 0.0;
    }
}

void dup_top(void) {
    if (sp > 0)
        push(val[sp - 1]);
    else {
        printf("error: stack empty\n");
    }
}

void swap_top(void) {
    if (sp > 1) {
        double tmp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = tmp;
    } else {
        printf("error: not enough elements to swap\n");
    }
}

void clear(void) {
    sp = 0;
}


int getop(char s[]) {
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';


    if (!isdigit(c) && c != '.' && strlen(s) == 1)
        return c;


    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()));


    if (c == '.')
        while (isdigit(s[++i] = c = getch()));

    s[i] = '\0';


    if (c != EOF)
        ungetch(c);

    /* check if the string is a command */
    if (strlen(s) > 1) {
        if (!strcmp(s, "top"))
            return OP_TOP;
        else if (!strcmp(s, "dup"))
            return OP_DUP;
        else if (!strcmp(s, "swp"))
            return OP_SWP;
        else if (!strcmp(s, "clr"))
            return OP_CLR;
        else if (!strcmp(s, "pop"))
            return OP_POP;
        else if (!strcmp(s, "sin"))
            return OP_SIN;
        else if (!strcmp(s, "cos"))
            return OP_COS;
        else if (!strcmp(s, "exp"))
            return OP_EXP;
        else if (!strcmp(s, "log"))
            return OP_LOG;
        else if (!strcmp(s, "pow"))
            return OP_POW;
    }

    return NUMBER; /* it's a number */
}



int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop() - op2);
                break;
            case '/':
                op2 = pop();
                if (op2 != 0.0)
                    push(pop() / op2);
                else
                    printf("error: zero divisor\n");
                break;
            case OP_TOP:
                printf("\t%.8g\n", print_top());
                break;
            case OP_DUP:
                dup_top();
                break;
            case OP_SWP:
                swap_top();
                break;
            case OP_CLR:
                clear();
                break;
            case OP_POP:
                /* add the functionality of the "pop" command next excercise */
                break;
            case OP_SIN:
                /* add the functionality of the "sin" command next excercise */
                break;
            case OP_COS:
                /* add the functionality of the "cos" command next excercise */
                break;
            case OP_EXP:
                /* add the functionality of the "exp" command next excercise */
                 break;
            case OP_LOG:
              /* add the functionality of the "log" command next excercise */
                break;
            case OP_POW:
                /* add the functionality of the "pow" command next excercise */
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                break;
        }
    }

    return 0;
}
