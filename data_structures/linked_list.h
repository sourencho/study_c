// Implementation of a sorted linked list that stores unique ints

#ifndef DATA_STRUCTURES_LINKED_LIST_H_
#define DATA_STRUCTURES_LINKED_LIST_H_

#include <stdlib.h>

struct node {
    int value;
    struct node *next;
};

node *insert(node *first, int v);
node *search(node *first, int v);
size_t size(node *first);
void remove(node *first, int v);


#endif  // DATA_STRUCTURES_LINKED_LIST_H_
