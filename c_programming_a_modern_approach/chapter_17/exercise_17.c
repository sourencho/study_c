// Modifying this exercise slightly, going to sort the last 3 elements of an array of size 6 and 
// use my own comparison function for a custom struct.

#include <stdlib.h>
#include <stdio.h>

struct animal {
    char species[10];
    int weight;
};

int cmp_animal_weight (const void * a, const void * b) {
   return (((struct animal*)a)->weight - ((struct animal*)b)->weight);
}

int main(void) {
    struct animal animals[6] = {
        {.species="Bushpig", .weight=88},
        {.species="Blue Whale", .weight=136000},
        {.species="Giraffe", .weight=800},
        {.species="Yak", .weight=670},
        {.species="Kob", .weight=105},
        {.species="Coyote", .weight=13},
    };
    qsort(animals+3, 3, sizeof(struct animal), cmp_animal_weight);
    for(int i = 0; i < 6; i++) {
        printf("%s - %d\n", animals[i].species, animals[i].weight);
    }
}
