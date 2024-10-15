#include <stdio.h>
#include <string.h>

int main () {
    char *s1 = "Hello";
    char *s2 = "Bye bye";
    char s3[100];

    // s1[1] = 'a';
    // s2[7] = 'X';

    printf("%s %ld\n", s1, strlen(s1));
    printf("%s %ld\n", s2, strlen(s2));

    strcat(s3, s1);
    strcat(s3, s2);
    printf("%s %ld\n", s3, strlen(s3));

    // strcpy(s3, s2);
    memcpy(s3, s2, 3);
    printf("%s %ld\n", s3, strlen(s3));


    return 0;
}