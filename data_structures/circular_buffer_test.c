#include "circular_buffer.h"

#include <assert.h>

int main() {
    uint32_t init_cap = 7;
    CircularBuffer *cb = cb__create(7);

    assert(cb__is_empty(cb) == true);

    int a = 1;
    int b = 2;
    cb__push(cb, a);
    cb__push(cb, b);
    assert(cb__is_empty(cb) == false);

    assert(cb__pop(cb) == a);
    assert(cb__pop(cb) == b);
    assert(cb__is_empty(cb) == true);

    for (int i = 0; i < init_cap; ++i) {
        cb__push(cb, i);
    }

    cb__print(cb);

    cb__push(cb, 7);
    cb__push(cb, 8);

    cb__print(cb);

    for (int i = 0; i < init_cap; ++i) {
        assert(cb__pop(cb) == i);
    }

    cb__print(cb);

    for (int i = 0; i < init_cap * 2; ++i) {
        cb__push(cb, i);
    }

    cb__print(cb);

    cb__destroy(cb);
}