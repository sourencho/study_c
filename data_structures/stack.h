// Implementation of an int stack using a linked list.

#ifndef DATA_STRUCTURES_STACK_H_
#define DATA_STRUCTURES_STACK_H_

#include <stdlib.h>
#include <stdbool.h>

typedef int Item;

typedef struct stack_type *Stack;

Stack stack__create(void);
void stack__destroy(Stack s);
void stack__make_empty(Stack s);
bool stack__is_empty(Stack s);
size_t stack__size(Stack s);
bool stack__push(Stack s, Item v);
Item stack__pop(Stack s);

#endif  // DATA_STRUCTURES_STACK_H_
