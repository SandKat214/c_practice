#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define SIZE 100

int *create_arr(int n);
void print_arr(int *p, int n);
int prod_arr(int *p, int n);

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

void print_arr(int *p, int n)
{
    // print array values
    for (int i=0; i<n; i++) {
        printf("my_arr[%d] = %d\n", i, *(p+i));
    }
}

int prod_arr(int *p, int n)
{
    // multiply all array values
    int prod = 1;
    for (int i=0; i<n; i++) {
        prod *= *(p+i);
    }

    return prod;
}