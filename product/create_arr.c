#include <stdio.h>
#include <stdlib.h>

int *create_arr(int n)
{
    // consolidate actual needed space
    int *p = (int *) malloc(sizeof (*p) * n);
    if (p == NULL) {
        printf("Error allocating memory.\n");
        return NULL;
    }

    // collect & validate array elements from user
    for (int i=0; i<n; i++) {
        printf("Enter element %d of my_arr: ", i);
        if (scanf("%d", p+i) != 1) {
            printf("Error reading number.\n");
            free(p);
            return NULL;
        }
    }

    return p;
}