#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    pid_t myPID;
    pid_t childOutPID;                  // PID of returning child
    int nForks;                         // Number of requested forks
    int childrenExiting;                //Number of children finishing its tasks
    int time = 0;                       // Sleeping time for a child process
    int i;                              // Counter

    if (argc != 2 || ((nForks = atoi(argv[1])) < 1)) {
        printf("Invalid user. Should be:\n");
        printf("cyclefork #_of_forks\n");
        printf("#_of_forks should be an integer > 0\n");
        exit(1);
    }

    setbuf(stdout, NULL);               // Disabling buffering for stdout

    for (i = 0; i < nForks; i++) {      // Creating a child with decreasing wait time for each loop
        switch (fork()) {
            case -1:                    // If the call to fork did not work
                printf("There is a problem with fork.");
                exit (1);
            
            case 0:                     // Child prints, sleeps and exits
                myPID = getpid();
                printf("Process %d created. Waiting %d seconds. \n", myPID, nForks - i);
                sleep(nForks - i);
                _exit(EXIT_SUCCESS);    // Safe way to exit a copy (child)
            
            default:                    // Parent continues creating processes
                break;
        }
    }

    childrenExiting = 0;
    while (childrenExiting < nForks) {
        childOutPID = wait(NULL);
        if (childOutPID < 1) {
            printf("Unexpected Error.");
            exit(1);
        }
        childrenExiting++;
        printf("Child #%d (Pid=%d) exit acknowledged\n", childrenExiting, childOutPID);
    }
    printf("All children are back.\n");
    printf("Bye!\n");
    exit(EXIT_SUCCESS);
}