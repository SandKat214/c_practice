#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <signal.h>
#include <string.h>

void (*back_handler)(int); // generic pointer to a handler function with an int parameter

// Simple handler to display the message received
static void myHandler(int sig) 
{
    printf("Signal Received: (%d) ==> %s\n", sig, strsignal(sig));
    close(2);
    exit(1);    
}

int main(int argc, char *argv[])
{
    // Section 1: Interrupts allowed
    if (signal(SIGINT, myHandler) == SIG_ERR) {
        printf("Could not initialize handler for SIGINT\n");
        exit(1);
    }
    printf("Working in Section 1...\n");
    sleep(5);

    // Section 2: Interrupts of SIGINT are not allowed
    back_handler = signal(SIGINT, SIG_IGN);         // signal returns to the old function used in handler
    if (back_handler == SIG_ERR) {                  // if there was a problem back_handler receives an error
        printf("Could not ignore SIGINT\n");
        exit(1);
    }
    printf("Working in Section 2. No interrupts allowed...\n");
    sleep(5);

    // Section 3: Interrupts allowed back
    if (signal(SIGINT, back_handler) == SIG_ERR) {
        printf("Could not reset handler for SIGINT\n");
        exit(1);
    }
    printf("Working in Section 3. Interrupts allowed back...\n");
    sleep(5);

    // Section 4: Interrupts of SIGINT are not handled (the default).
    if (signal(SIGINT, SIG_DFL) == SIG_ERR) {
        printf("Could not unset handling of SIGINT\n");
        exit(1);
    }
    printf("Working in Section 4. Interrupts are not handled...\n");
    sleep(5);
}
