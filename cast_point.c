#include <stdio.h>
// Program Name: CastingPointers.c
// Author: GT
// This program shows problems when casting incompatible pointer types
void g1(void) {
    int i = 0;
    int *ip = &i;
    (*ip)++;
    printf("Inside g1 int i increased with int* is %d\n", i);
}
void g2(void) {
    int i = 0;
    float *ip = (float *)&i;
    (*ip)++;
    printf("Inside g2 int i increased with float* is %d\n", i);
}
void g3(void) {
    float f = 0.0;
    int *ip = (int *)&f;
    (*ip)++;
    printf("Inside g3 float f increased with int* is %f\n", f);
}
void g4(void) {
    float f = 0.0;
    float *ip = &f;
    (*ip)++;
    printf("Inside g2 float f increased with float* is %f\n", f);
}
int main()
{
    g1();
    g2();
    g3();
    g4();
}
