// Implementation of an int stack using a linked list.

#ifndef DATA_STRUCTURES_STACK_H_
#define DATA_STRUCTURES_STACK_H_

#include <stdlib.h>
#include <stdbool.h>

struct stack {
    int value;
    struct stack *next;
};

/**
 * Empties stack.
 * Deallocates all node data.
 */
void make_empty(struct stack **top);

/**
 * Returns true if stack is empty.
 */
int is_empty(struct stack **top);

/**
 * Push onto the stack and update top.
 * Returns false if couldn't allocate memory.
 */
bool push(struct stack **top, int v);

/**
 * Pop off the stack and update top.
 * Deallocates node data.
 */
int pop(struct stack **top);

/**
 * Returns size of stack.
 */
size_t size(struct stack **top);

#endif  // DATA_STRUCTURES_STACK_H_
