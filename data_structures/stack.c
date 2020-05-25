#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void make_empty(struct stack **top) {
    while(!is_empty(top)) {
        pop(top); 
    }
};

int is_empty(struct stack **top) {
    return size(top) == 0;
}

bool push(struct stack **top, int v) {
    // Allocate
    struct stack *new_node;
    new_node = malloc(sizeof(struct stack));
    if(new_node == NULL) {
        return false;
    }

    // Populate
    new_node->value = v;
    new_node->next = *top;

    // Swap top
    *top = new_node;

    return true;
}

int pop(struct stack **top) {
    if (is_empty(top)) {
        printf("*** Stack underflow; program terminated. ***\n");
        exit(EXIT_FAILURE);
    }

    struct stack *temp = *top;
    int out = (*top)->value;
    *top = (*top)->next;
    free(temp);

    return out;
}

size_t size(struct stack **top) {
    size_t count = 0;
    struct stack *p = *top;
    while(p->next != NULL) {
        count++;
        p = p->next;
    }
    return count;
}
