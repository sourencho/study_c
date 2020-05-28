#include "priority_queue.h"

#include <assert.h>
#include <stdio.h>

struct PriorityQueue {
    Item *items;
    size_t size;
    int (*compar)(const void *, const void *);
};

void priority_queue__fix_up(PriorityQueue *pq, int k) {
    while (k > 1 && pq->compar(&(pq->items[k / 2]), &(pq->items[k])) < 0) {
        item_swap(pq->items, k, k / 2, pq->size);
        k = k / 2;
    }
}

void priority_queue__fix_down(PriorityQueue *pq, int k) {
    int j;
    while (2 * k <= pq->size) {
        j = 2 * k;
        if (j < pq->size &&
            pq->compar(&(pq->items[j]), &(pq->items[j + 1])) < 0) {
            j++;
        }
        if (pq->compar(&(pq->items[k]), &(pq->items[j])) >= 0) {
            break;
        }
        item_swap(pq->items, k, j, pq->size);
        k = j;
    }
}

PriorityQueue *priority_queue__create(size_t max_size,
                                      int (*compar)(const void *,
                                                    const void *)) {
    PriorityQueue *pq = malloc(sizeof(struct PriorityQueue));
    assert(pq != NULL);
    pq->items = malloc(sizeof(Item) * (max_size + 1));
    assert(pq->items != NULL);
    pq->size = 0;
    pq->compar = compar;
    return pq;
}

bool priority_queue__empty(PriorityQueue *pq) {
    return pq->size == 0;
}

void priority_queue__insert(PriorityQueue *pq, Item v) {
    pq->size++;
    pq->items[pq->size] = v;
    priority_queue__fix_up(pq, pq->size);
}

Item priority_queue__pop(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Can't pop from empty queue.");
        exit(EXIT_FAILURE);
    }
    item_swap(pq->items, 1, pq->size, pq->size);
    pq->size--;
    priority_queue__fix_down(pq, 1);
    return pq->items[pq->size + 1];
}

void priority_queue__destroy(PriorityQueue *pq) {
    free(pq->items);
    free(pq);
}

size_t priority_queue__size(PriorityQueue *pq) {
    return pq->size;
}

void priority_queue__print(PriorityQueue *pq) {
    for (int i = 0; i < pq->size; i++) {
        item_print(&(pq->items[i + 1]));
        printf(" ");
    }
    printf("\n");
}
