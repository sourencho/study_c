// Implementation of a priority queue using an array

#ifndef DATA_STRUCTURES_PRIORITY_QUEUE_H
#define DATA_STRUCTURES_PRIORITY_QUEUE_H

#include <stdbool.h>
#include <stdlib.h>

#include "item.h"

typedef struct PriorityQueue PriorityQueue;

void priority_queue__fix_up(PriorityQueue *pq, int k);
void priority_queue__fix_down(PriorityQueue *pq, int k);

PriorityQueue *priority_queue__create(size_t max_size,
                                      int (*compar)(const void *,
                                                    const void *));
bool priority_queue__empty(PriorityQueue *pq);
void priority_queue__insert(PriorityQueue *pq, Item v);
Item priority_queue__pop(PriorityQueue *pq);
void priority_queue__destroy(PriorityQueue *pq);
size_t priority_queue__size(PriorityQueue *pq);
void priority_queue__print(PriorityQueue *pq);

#endif // DATA_STRUCTURES_PRIORITY_QUEUE_H