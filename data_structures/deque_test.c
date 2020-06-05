#include "deque.h"

#include <assert.h>

int main() {
    Deque *deque = deque__create();

    deque__print(deque);

    deque__push_back(deque, 1);
    deque__push_front(deque, 99);

    deque__print(deque);

    deque__push_back(deque, 2);
    deque__push_back(deque, 3);
    deque__push_front(deque, 98);
    deque__push_front(deque, 97);
    deque__push_front(deque, 96);
    deque__push_front(deque, 95);

    deque__print(deque);

    deque__push_front(deque, 94);
    deque__push_back(deque, 4);
    deque__push_back(deque, 5);
    deque__push_back(deque, 6);
    deque__push_back(deque, 7);
    deque__push_back(deque, 8);
    deque__push_back(deque, 9);

    deque__print(deque);

    assert(deque__pop_front(deque) == 94);
    assert(deque__pop_back(deque) == 9);

    deque__print(deque);

    assert(deque__pop_front(deque) == 95);
    assert(deque__pop_front(deque) == 96);
    assert(deque__pop_front(deque) == 97);
    assert(deque__pop_front(deque) == 98);
    assert(deque__pop_front(deque) == 99);
    assert(deque__pop_front(deque) == 01);

    deque__print(deque);

    deque__destroy(deque);
}