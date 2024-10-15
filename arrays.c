#include <stdio.h>
#include <string.h>

#define SIZE 100

int main ()
{
    int my_arr[] = {20, 30, 40, 50, 60};
    int my_arr2[SIZE];
    int real_size = 5;

    // print my_arr
    for (int i=0; i<5; i++) {
        printf("my_arr[%d] = %d\n", i, my_arr[i]);
    }

    // copy my_arr into my_arr2
    // for (int i=0; i<real_size; i++) {
    //     my_arr2[i] = my_arr[i];
    // }
    memcpy(my_arr2, my_arr, real_size * sizeof(int));

    my_arr2[real_size] = 123;
    real_size++;

    // print my_arr2
    for (int i=0; i<real_size; i++) {
        printf("my_arr2[%d] = %d\n", i, my_arr2[i]);
    }

    return 0;
}