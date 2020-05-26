#include <stdio.h>
#include <assert.h>

#include "stack.h"

int main(void) {
    Stack s = stack__create();

    // push, size, !is_empty
    assert(stack__push(s, 4) == true);
    assert(stack__size(s) == 1);
    assert(stack__is_empty(s) == false);
    
    // pop, size, is_empty
    assert(stack__pop(s) == 4);
    assert(stack__size(s) == 0);
    assert(stack__is_empty(s) == true);

    // push, size, make_empty, is_empty
    assert(stack__push(s, 4) == true);
    assert(stack__push(s, 5) == true);
    assert(stack__size(s) == 2);
    stack__make_empty(s);
    assert(stack__size(s) == 0);
    assert(stack__is_empty(s) == true);

    stack__destroy(s);

    printf("Done without errors.\n");
}
