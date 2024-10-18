#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define STR_SIZE 20

int strend(char *, char *);

int main()
{
    char *s1 = (char *) calloc(STR_SIZE, sizeof (*s1));
    char *s2 = (char *) calloc(STR_SIZE, sizeof (*s2));
    if (s1 == NULL || s2 == NULL) {
        printf("Memory could not be allocated for array.\n");
        return -1;
    }

    printf("Enter the first string: ");
    fgets(s1, STR_SIZE, stdin);
    printf("Enter the second string: ");
    fgets(s2, STR_SIZE, stdin);

    bool result = strend(s1, s2);
    printf("It is %s that the second string occurs at the end of the first string.\n", result ? "true" : "false");

    free(s1);
    free(s2);

    return 0;
}

int strend(char *s, char *t)
{
    int s_len = strlen(s);
    int t_len = strlen(t);

    if (s_len >= t_len) {
        int diff = s_len - t_len;
        s += diff;
        for (; *s == *t; s++, t++) {
            if (*s == '\0') {
                return 1;
            }
        }
    }

    return 0;
}