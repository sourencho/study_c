#ifndef DATA_STRUCTURES_ITEM_H
#define DATA_STRUCTURES_ITEM_H

#include <stddef.h>

struct Item {
    int x;
};

typedef struct Item Item;

void item_swap(Item *items, int i, int j, size_t size);
int item_compar(const void *a, const void *b);
void item_print(const Item *i);
void items_print(Item *items, size_t size);
char item_char(const Item *i);

#endif // DATA_STRUCTURE_ITEM_H