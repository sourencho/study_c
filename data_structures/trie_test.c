#include "trie.h"

#include <assert.h>
#include <stdio.h>

int main(void) {
    Trie *trie = trie__create();

    char mario_key[] = "mario";
    int mario_val = 10;
    trie__add(trie, mario_key, mario_val);
    assert(*trie__get(trie, mario_key) == mario_val);

    char mart_key[] = "mart";
    int mart_val = 44;
    trie__add(trie, mart_key, mart_val);
    assert(*trie__get(trie, mart_key) == mart_val);

    char martik_key[] = "martik";
    int martik_val = 88;
    trie__add(trie, martik_key, martik_val);
    assert(*trie__get(trie, martik_key) == martik_val);

    char dog_key[] = "dog";
    int dog_val = 1337;
    trie__add(trie, dog_key, dog_val);
    assert(*trie__get(trie, dog_key) == dog_val);

    char peach_key[] = "peach";
    assert(trie__get(trie, peach_key) == NULL);

    trie__add(trie, "a", 1);
    assert(*trie__get(trie, "a") == 1);

    // This causes a crash, remove is unable to hand cases where '\0' has a
    // next.
    // trie__remove(trie, martik_key);
    // trie__remove(trie, dog_key);

    trie__print(trie);

    trie__destroy(trie);
}