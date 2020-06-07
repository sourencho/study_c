#pragma once

#include <stdbool.h>
#include <stdio.h>

typedef struct _bst BST;

BST *bst__create();
void bst__destroy(BST *bst);

void bst__insert(BST *bst, int val);
bool bst__search(BST *bst, int val);
void bst__print(BST *bst);
