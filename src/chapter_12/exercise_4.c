#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#define STACK_SIZE 100

/* external variables */
int contents[STACK_SIZE];
int *top_ptr = contents;

void make_empty(void) {
    top_ptr = contents;
}

bool is_empty(void) {
    return top_ptr == contents;
}

bool is_full(void) {
    return top_ptr == contents + STACK_SIZE;
}

void push(int i) {
    if (is_full()) {
        fprintf(stderr, "Stack overflow\n");
        exit(-1);
    } else {
        *top_ptr++ = i;
    }
}

int pop(void) {
    if (is_empty()) {
        fprintf(stderr, "Stack underflow\n");
        exit(-1);
    } else {
        return *--top_ptr;
    }
}

int main() {
    push(1);
    push(2);
    int a = pop();
    int b = pop();
    bool empty = is_empty();
    assert(a == 2);
    assert(b == 1);
    assert(empty == true);
    printf("Done without errors.\n");
}
