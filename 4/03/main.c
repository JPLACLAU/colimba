#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define MAXOP 100
#define NUMBER '0'

// Function prototypes
int getop(char []);
void push(double);
double pop(void);

// Helper function to check if a string represents a number
int isNumber(char s[]) {
    for (int i = 0; s[i] != '\0'; i++)
        if (!isdigit(s[i]) && s[i] != '.' && s[i] != '-')
            return 0;
    return 1;
}

int main() {
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUMBER:
                if (isNumber(s))
                    push(atof(s));
                else
                    printf("error: invalid number %s\n", s);
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
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}
