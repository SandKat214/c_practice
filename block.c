#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void (*back_handler)(int); // generic pointer to a handler function with an int parameter

// Simple handler to display the messge received
static void myHandler(int sig)
{
    printf("Signal received: (%d) ==> %s\n", sig, strsignal(sig));
    close(2);
    exit(1);
}

int main(int argc, char *argv[])
{
    sigset_t blockedSet;                            // Set of signals to be blocked
    sigset_t pendingSet;                            // Set of signals that are pending
    sigset_t defaultSet;                            // Set of signals from start of process

    // Initializing blocked set of signals
    sigemptyset(&blockedSet);                       // empty set to start
    sigaddset(&blockedSet, SIGINT);                 // adding SIGINT
    sigaddset(&blockedSet, SIGQUIT);                // adding SIGQUIT

    // Section 1: Interrupts allowed
    if (signal(SIGINT, myHandler) == SIG_ERR) {
        printf("Could not initialize handler for SIGINT\n");
        exit(1);
    }
    if (signal(SIGQUIT, myHandler) == SIG_ERR) {
        printf("Could not initialize handler for SIGQUIT\n");
        exit(1);
    }
    printf("Working in Section 1...\n");
    sleep(5);

    // Section 2: Interrupts of SIGINT andSIGQUIT are blocked
    if (sigprocmask(SIG_BLOCK, &blockedSet, &defaultSet) == -1) {
        printf("Error trying to block signals SIGINT and SIGQUIT\n");
        exit(1);
    }
    printf("Working in Section 2. SIGINT(2) and SIGQUIT(3) are blocked...\n");
    sleep(5);
    printf("Before entering Section 3, the following signals were intercepted...\n");
    if (sigpending(&pendingSet) == -1) {
        printf("Error trying to retrieve pending signals\n");
        exit(1);
    }
    if (sigismember(&pendingSet, SIGINT)) printf("\nSIGIT(2) is pending\n");
    if (sigismember(&pendingSet, SIGQUIT)) printf("\nSIGQUIT(3) is pending\n");

    // Section 3: Allowing blocked signals to be delivered
    if (sigprocmask(SIG_SETMASK, &defaultSet, NULL) == -1) {
        printf("Could not restore original handler set of\n");
        exit(1);
    }
    printf("Working in Section 3. Interrupts allowed back...\n");
    sleep(5);
}
