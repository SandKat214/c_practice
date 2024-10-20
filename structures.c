#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    typedef struct patient_data {
        char name[20];      // Patient's first name
        int age;            // Patient's age in years
        float weight;       // Patient's weight in lbs
    } patient;

    patient tim = {"Tim", 35, 150.0};
    patient class[3];
    patient *p;
    patient *pa;

    printf("name: %s, age: %d, weight: %.2f\n", tim.name, tim.age, tim.weight);

    strcpy(tim.name, "Timothy");
    tim.age = 36;
    tim.weight = 180.0;
    
    printf("name: %s, age: %d, weight: %.2f\n", tim.name, tim.age, tim.weight);

    printf("\n");
    strcpy(class[0].name, "John");
    strcpy(class[1].name, "Jill");
    strcpy(class[2].name, "Jack");

    for (int i=0; i<3; i++) {
        class[i].age = 10*i + 10;
        class[i].weight = 180 - 10*i;
    }

    for (int i=0; i<3; i++) {
        printf("name: %s, age: %d, weight: %.2f\n", class[i].name, class[i].age, class[i].weight);
    }

    printf("\n");
    p = (patient *) calloc(3, sizeof (*p));
    pa = p;
    strcpy(pa->name, "Mary");
    strcpy((pa+1)->name, "Mark");
    strcpy((pa+2)->name, "Maya");

    for (int i=0; i<3; i++) {
        (pa+i)->age = 10*i + 15;
        (pa+i)->weight = 180 - 20*i;
    }

    for (int i=0; i<3; i++) {
        printf("name: %s, age: %d, weight: %.2f\n", (pa+i)->name, (pa+i)->age, (pa+i)->weight);
    }

    free(p);
}