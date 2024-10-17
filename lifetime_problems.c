#include <stdio.h>
#include <string.h>



// This program shows some problems when lifetime of variables are not respected

// 1. This function is returning a local variable (newArray) past its lifetime
char* badCreateArray(void) {
    char newArray[10] = "My array";
    return newArray;
}

// 2. The following global variable is updated with a local variable (localString)
char *pointerToString = NULL;
void wrongLifetimeUse(void) {
    char localString[] = "Hello";
    pointerToString = localString; /* Dangerous */
}

void printGlobal(void) {
    printf("%s\n", pointerToString);
}

int main(void) {
    // Problem 1: getting a local variable from another scope
    char* a = badCreateArray();
    printf("%s\n", a);

    // Problem 2: Updating a global variable with a variable with local scope
    wrongLifetimeUse();
    printGlobal();
    
    return 0;
}
