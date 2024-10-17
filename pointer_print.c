#include <stdio.h>

int main()
{
    int a[] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50};
    int *pa;
    pa = a;
    int x;

    size_t size_a = sizeof (a);
    size_t size_el = sizeof (a[0]);
    int arr_len = size_a / size_el;

    printf("Contents of a[i] = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50}\n");
    for (int i=0; i<arr_len; i++) {
        printf("a[%d] = %d, %p\n", i, a[i], &a[i]);
    }

    printf("Contents of *(pa + i) = {5, 10, 15, 20, 25, 30, 35, 40, 45, 50}\n");
    for (int i=0; i<arr_len; i++) {
        printf("*(pa + %d) = %d, %p\n", i, *(pa + i), pa + i);
    }

    printf("Assign a contents to x using dereferenced p\n");
    for (; pa<&a[arr_len]; pa++) {
        x = *pa;
        printf("x = %d\n", x);
    }
}