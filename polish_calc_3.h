// System headers
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Macro definitions
#define MAXVAL 100
#define BUFSIZE 100
#define NUMBER '0'
#define MAXOP 100

// Function prototypes
void push(double);
double pop(void);
int getch(void);
void ungetch(int);
int getop(char []);