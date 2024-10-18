#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

int strend(char *, char *);

int main()
{
    char *s1 = calloc(20, sizeof (*s1));
    char *s2 = calloc(20, sizeof (*s2));

    printf("Enter the first string: ");
    scanf("%s", s1);
    printf("Enter the second string: ");
    scanf("%s", s2);

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