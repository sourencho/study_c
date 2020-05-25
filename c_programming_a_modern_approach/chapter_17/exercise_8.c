#include <stdio.h>
#include <assert.h>
#include "../../data_structures/stack.h"

int main(void) {
    struct stack s = {};
    struct stack *top = &s;
    assert(is_empty(&top));
    printf("Implemented in \"data_structures/stack.h\".\n");
}
