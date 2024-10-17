#include <stdio.h>
#include <math.h>

int main()
{
    float a, b, c;
    float *pa, *pb, *pc;

    pa = &a;
    pc = &c;
    pb = &b;

    printf("Please enter the length of the first side of the right triangle: ");
    scanf("%f", pa);

    printf("Please enter the length of the second side of the right triangle: ");
    scanf("%f", pb);

    *pc = (float) sqrt((*pa) * (*pa) + (*pb) * (*pb));
    printf("The sides of the right angle triangle are: (%.2f, %.2f)\n", a, b);
    printf("The hypoteneuse is: %.2f\n", c);

    return 0;
}