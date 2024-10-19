#include <stdio.h>
#include <stdlib.h>
#include "product.h"

#define SIZE 100

int main(int argc, char *argv[])
{
    int *my_arr = NULL;
    int n;
    int prod;
    char msg[200];

    // Collect user input
    sprintf(msg, "How many elements in the array (1 - %d)? ", SIZE);
    printf("%s", msg);
    scanf("%d", &n);

    // validate user input
    if ((n<=0) || (n>SIZE)) {
        printf("Number of elements (%d) is invalid.\n", n);
        return 1;
    }

    my_arr = create_arr(n);
    if (my_arr == NULL) {
        printf("Error allocating memory.\n");
        return 1;
    }

    print_arr(my_arr, n);
    prod = prod_arr(my_arr, n);

    // free memory & print results
    free(my_arr);
    printf("The product of all elements on my_arr is %d\n", prod);
    return 0;
}
