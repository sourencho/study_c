#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct _trie Trie;

Trie *trie__create();
void trie__destroy(Trie *trie);

void trie__add(Trie *trie, char *key, int val);

const int *trie__get(Trie *trie, char *key);

// Remove has a bug. It's unable to handle cases where there is a letter
// adjacent to a '\0' For example if you have dog and doggy, removing dog will
// crash.
// void trie__remove(Trie *trie, char *key);

void trie__print(Trie *trie);