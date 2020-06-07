#include "bst.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

int main() {
    // create
    BST *bst = bst__create();

    // insert
    bst__insert(bst, 2);
    bst__insert(bst, 5);
    bst__insert(bst, 4);
    bst__insert(bst, 1);

    bst__print(bst);

    // search
    assert(bst__search(bst, 4) == true);
    assert(bst__search(bst, 3) == false);

    // destroy
    bst__destroy(bst);
}