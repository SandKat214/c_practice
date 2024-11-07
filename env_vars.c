#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

void showEnvVars(char *envp[], char *prefix);

int main(int argc, char *argv[])
{
    char *myEnvVar;
    char *prefix = "H";
    char **envp = environ;

    printf("\nOriginal Environment Variables with prefix %s...\n", prefix);
    showEnvVars(envp, "H");

    if (setenv("HELLO", "hello", 0) == -1) {
        printf("\nHELLO environment variable could not be added\n");
        exit(1);
    } else {
        printf("\nEnvironment variable HELLO was added.\n");
    }

    if ((myEnvVar = getenv("HELLO")) == NULL) myEnvVar = "Not Available";
    printf("Recovered Environment Variable HELLO ==> %s\n", myEnvVar);

    envp = environ;
    printf("\nEnvironment Variables After adding HELLO...\n");
    showEnvVars(envp, "H");

    return 0;    
}

void showEnvVars(char *envp[], char *prefix){
    for (char **p = &envp[0]; *p != 0; p++) {
        if ((*prefix == 0) || (strncmp(*p, prefix, strlen(prefix)) == 0)) {
            printf("%s\n", *p);
        }
    }
}
