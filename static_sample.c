#include <stdio.h>

// This program shows the use of static variables

// Function with plain local variables
void forgetPark(void) {
    int visits = 0;
    printf("Welcome to Forget Park! You have visited us %d times before\n",
    visits);
    visits = visits + 1;
}

// Function with a static variable
void rememberZoo(void) {
    static int visits = 0;
    printf("Welcome to Remember Zoo! You have visited us %d times before.\n", visits);
    visits = visits + 1;
}

int main()
{
    printf("visiting Forget Park for first time ...\n");
    forgetPark();
    printf("visiting Remember Zoo for first time ...\n");
    rememberZoo();
    printf("visiting Forget Park for second time ...\n");
    forgetPark();
    printf("visiting Remember Zoo for second time ...\n");
    rememberZoo();
    printf("visiting Forget Park for third time ...\n");
    forgetPark();
    printf("visiting Remember Zoo for third time ...\n");
    rememberZoo();

    return 0;
}
