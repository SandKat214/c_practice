#include <stdio.h>
/*deletes each character in s1 that matches any character in s2*/
void squeeze(char s1[], char s2[])
{
    int i, j, k;
    for (i = 0; s2[i] != '\0'; i++)
    {
        for (j = k = 0; s1[j] != '\0'; j++)
            if (s2[i] != s1[j])
                s1[k++] = s1[j];
        s1[k] = '\0';
    }
}

int main()
{
    char str1[] = "sandeen";
    char str2[] = "near";

    squeeze(str1, str2);
    printf("Here is what is left of s1: %s\n", str1);
}