#include "item.h"

#include <stdio.h>

void item_swap(Item *items, int i, int j, size_t size) {
    Item temp = items[i];
    items[i] = items[j];
    items[j] = temp;
    // items_print(items, size);
};

int item_compar(const void *a, const void *b) {
    Item *ai = (Item *)a;
    Item *bi = (Item *)b;

    // printf("compare");
    // item_print(ai);
    // printf(" ");
    // item_print(bi);
    // printf("\n");

    if (ai->x < bi->x) {
        return -1;
    } else if (ai->x > bi->x) {
        return 1;
    } else {
        return 0;
    }
}

void item_print(const Item *i) {
    printf("%d", i->x);
}

void items_print(Item *items, size_t size) {
    for (int i = 0; i < size; i++) {
        item_print(&items[i]);
    }
}

char item_char(const Item *i) {
    printf("%c", (i->x) + '0');
    return (i->x) + '0';
}