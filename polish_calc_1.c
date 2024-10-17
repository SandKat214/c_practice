// System headers
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Macro definitions
#define MAXVAL 100
#define BUFSIZE 100
#define NUMBER '0'
#define MAXOP 100

// Global variables
int sp = 0, bufp = 0;
double val[MAXVAL];
char buf[BUFSIZE];

// Function prototypes
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
int getop(char []);

// Function definitions

int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF) {
        switch(type) {
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
                if (op2 != 0.0) {
                    push(pop() / op2);
                } else {
                    printf("Error: zero divisor\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n", pop());
                break;
            default:
                printf("Error: unknown command %s\n", s);
                break;
        }
    }
    return 0;
}

/**
 * Function to push a value on top of stack.
 */
void push(double f)
{
    if (sp < MAXVAL) {
        val[sp++] = f;
    } else {
        printf("Error: stack full, can't push %g\n", f);
    }
    return;
}

/**
 * Function to pop and return the top value from the stack.
 */
double pop(void)
{
    if (sp > 0) {
        return val[--sp];
    } else {
        printf("Error: stack empty\n");
        return 0.0;
    }
}

/**
 * Function to get a possibly pushed back character.
 */
int getch(void)
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

/**
 * Function to push a character back on input.
 */
void ungetch(int c)
{
    if (bufp >= BUFSIZE) {
        printf("ungetch: too many characters!\n");
    } else {
        buf[bufp++] = c;
    }
}

/**
 * Function gets the next operand in the expression.
 */
int getop(char s[])
{
    int i, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';

    // c is  not a number
    if (!isdigit(c) && c != '.') {
        return c;
    }
    i = 0;

    // collect integer part
    if (isdigit(c)) {
        while (isdigit(s[++i] = c = getch()));
    }

    // collect fraction part
    if (c == '.') {
        while (isdigit(s[++i] = c = getch()));
    }

    s[i] = '\0';
    if (c != EOF) {
        ungetch(c);
    }
    return NUMBER;
}
