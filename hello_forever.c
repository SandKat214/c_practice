#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

static void myHandler(int sig) {
    printf("Signal Received: (%d) ==> %s\n", sig, strsignal(sig));
    close(1);
    exit(1);
}

int main(int argc, char *argv[]) 
{
    char msg[100];

    setbuf(stdout, NULL);                    // Disabling buffering for stdout

    if (signal(SIGINT, myHandler) == SIG_ERR) {
        printf("Could not initialize handler for Ctrl-C (SIGINT)\n");
        exit(1);
    }
    if (signal(SIGQUIT, myHandler) == SIG_ERR) {
        printf("Could not initialize handler for Ctrl-\\ (SIGQUIT)\n");
        exit(1);
    }
    if (signal(SIGTERM, SIG_IGN) == SIG_ERR) {
        printf("Could not initialize handler for SIGTERM\n");
        exit(1);
    }
    if (signal(SIGKILL, SIG_IGN) == SIG_ERR) {
        printf("Could not initialize handler for SIGKILL\n");
        exit(1);
    }

    strcpy(msg, "Hello ");
    if (argc > 1) strcat(msg, argv[1]);
    strcat(msg, "!");

    while (true) {
        printf("%s\n", msg);
        sleep(1);
    }
}