#include <stdio.h>
#include <assert.h>

#include "stack.h"

int main(void) {
    struct stack s = {};
    struct stack *top = &s;

    // push, size, !is_empty
    assert(push(&top, 4) == true);
    assert(size(&top) == 1);
    assert(is_empty(&top) == false);
    
    // pop, size, is_empty
    assert(pop(&top) == 4);
    assert(size(&top) == 0);
    assert(is_empty(&top) == true);

    // push, size, make_empty, is_empty
    assert(push(&top, 4) == true);
    assert(push(&top, 5) == true);
    assert(size(&top) == 2);
    make_empty(&top);
    assert(size(&top) == 0);
    assert(is_empty(&top) == true);

    printf("Done without errors.\n");
}
