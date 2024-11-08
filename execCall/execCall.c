#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[], char *envp[])
{
    char *otherProg = "other";                          // program to call
    char *my_argv[] = {"A1", "A2", (char *) NULL};
    char *my_envp[] = {"E1", "E2", (char *) NULL};

    switch (fork()) {
        case -1:                                        // error
            printf("There is a problem with fork.");
            exit(1);
        case 0:                                         // child process
            printf("On child process... Calling process %s.\n", otherProg);
            if (execv(otherProg, my_argv) != 0) {       // execv, execve, execvp, execl, execle, execlp
                printf("Child process could not call process %s,\n", otherProg);
                _exit(1);
            }
        default:                                        // parent process
            break;
    }

    printf("Parent program ended.\n");
    exit(0);
}