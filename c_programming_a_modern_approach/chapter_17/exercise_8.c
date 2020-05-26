#include <stdio.h>
#include <assert.h>
#include "../../data_structures/stack.h"

int main(void) {
    Stack s = stack__create();
    assert(stack__is_empty(s));
    printf("Implemented in \"data_structures/stack.h\".\n");
}
