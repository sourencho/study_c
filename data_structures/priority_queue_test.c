#include "priority_queue.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX_SIZE 100

int main(void) {
    // Create
    PriorityQueue *pq = priority_queue__create(MAX_SIZE, item_compar);

    // Empty
    assert(priority_queue__empty(pq) == true);

    // Insert
    priority_queue__insert(pq, (Item){.x = 10});
    priority_queue__insert(pq, (Item){.x = 20});
    priority_queue__insert(pq, (Item){.x = 5});
    priority_queue__insert(pq, (Item){.x = 30});
    priority_queue__insert(pq, (Item){.x = 15});

    // Size
    assert(priority_queue__size(pq) == 5);
    assert(priority_queue__empty(pq) == false);

    // Print
    // priority_queue__print(pq);

    // Pop
    Item p = priority_queue__pop(pq);
    assert(item_compar(&p, &(Item){.x = 30}) == 0);
    assert(priority_queue__size(pq) == 4);

    // Pop pop
    priority_queue__pop(pq);
    priority_queue__pop(pq);
    Item pppp = priority_queue__pop(pq);
    assert(item_compar(&pppp, &(Item){.x = 10}) == 0);
    assert(priority_queue__size(pq) == 1);

    // Print
    // priority_queue__print(pq);

    // Destroy
    priority_queue__destroy(pq);

    printf("Done without errors.\n");
}