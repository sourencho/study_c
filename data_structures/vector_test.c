#include "vector.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

int main(void) {
    Vector *v = vector__create();
    Item i_1 = (Item){.x = 10};
    Item i_2 = (Item){.x = 20};
    Item i_3 = (Item){.x = 30};
    vector__push(v, i_1);
    assert(vector__size(v) == 1);
    Item i_1v = vector__get(v, 0);
    assert(item_compar(&i_1v, &i_1) == 0);
    vector__push(v, i_2);
    vector__push(v, i_3);
    assert(vector__capacity(v) == 4);
    vector__clear(v);
    assert(vector__size(v) == 0);
    vector__destroy(v);
}