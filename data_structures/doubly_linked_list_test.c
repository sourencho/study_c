#include "doubly_linked_list.h"

#include <assert.h>

int main() {
    DLL *dll = dll__create();

    // Push front
    dll__push_front(dll, 2);
    dll__push_front(dll, 1);
    dll__print(dll); // 1 2

    // Push back
    dll__push_back(dll, 3);
    dll__push_back(dll, 4);
    dll__print(dll); // 1 2 3 4

    // Remove
    dll__remove(dll, 3);
    dll__print(dll); // 1 2 4

    // Push after
    dll__push_after(dll, 2, 3);
    dll__print(dll); // 1 2 3 4

    // Push after lots of modifications
    dll__push_front(dll, 0);
    dll__push_back(dll, 5);
    dll__print(dll); // 0 1 2 3 4 5

    // Size
    assert(dll__size(dll) == 6);

    // Clear
    dll__clear(dll);
    dll__push_front(dll, 0);
    dll__push_after(dll, 2, 3);
    assert(dll__size(dll) == 1);
    dll__print(dll); // 0

    dll__destroy(dll);
}