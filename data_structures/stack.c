#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "stack.h"

struct node {
    Item data;
    struct node *next;
};

struct stack_type {
    struct node *top;
};

Stack stack__create(void) {
    Stack s = malloc(sizeof(struct stack_type));
    assert(s != NULL);
    s->top = NULL;
    return s;
}

void stack__destroy(Stack s) {
    stack__make_empty(s);
    free(s);
}

void stack__make_empty(Stack s) {
    while(!stack__is_empty(s)) {
        stack__pop(s); 
    }
}

bool stack__is_empty(Stack s) {
    return stack__size(s) == 0;
}

size_t stack__size(Stack s) {
    struct node *n = s->top;
    if (n == NULL) {
        return 0;
    }

    size_t count = 1;
    while(n->next != NULL) {
        count++;
        n = n->next;
    }
    return count;
}

bool stack__push(Stack s, Item v) {
    // Allocate
    struct node *new_node  = malloc(sizeof(struct node));
    if(new_node == NULL) {
        return false;
    }

    // Populate
    new_node->data = v;
    new_node->next = s->top;

    // Swap top
    s->top = new_node;

    return true;
}

int stack__pop(Stack s) {
    if (stack__is_empty(s)) {
        printf("*** Stack underflow; program terminated. ***\n");
        exit(EXIT_FAILURE);
    }

    struct node *old_top = s->top;
    Item out = old_top->data;
    s->top = old_top->next;
    free(old_top);

    return out;
}

