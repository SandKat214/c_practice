#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

int main(int argc, char *argv[], char *envp[])
{
    int i = 0;
    char *myEnvVar;

    printf("\nInside the Child Process...\nArguments in argv:\n");
    for (char **p = &argv[0]; (*p!=0)&&(i<5); p++, i++) {
        printf("argv[%d] = %s\n", i, *p);
    }
    printf("\nArguments in environment variables:\n");
    i = 0;
    for (char **p = &envp[0]; (*p!=0)&&(i<5); p++, i++) {
        printf("envp[%d] = %s\n", i, *p);
    }

    return 0;
}