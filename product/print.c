#include <stdio.h>

void print_arr(int *p, int n)
{
    // print array values
    for (int i=0; i<n; i++) {
        printf("my_arr[%d] = %d\n", i, *(p+i));
    }
}