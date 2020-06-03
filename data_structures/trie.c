#include "trie.h"

#include <assert.h>
#include <stdint.h>
#include <stdio.h>

typedef struct _trie_node {
    char c;
    int val;
    struct _trie_node *next, *child;
} TrieNode;

struct _trie {
    TrieNode *root;
};

static void _node_destroy(TrieNode *node);
static void _node_add(TrieNode *node, char *key, int val);
static void _node_print(TrieNode *node, int level);
static const int *_node_get(TrieNode *node, char *key);
static bool _node_remove(Trie *trie, TrieNode *prev, TrieNode *node, char *key);

Trie *trie__create() {
    Trie *trie = calloc(1, sizeof(Trie));
    assert(trie != NULL);
    return trie;
}

void trie__destroy(Trie *trie) {
    _node_destroy(trie->root);
    free(trie);
}

void _node_destroy(TrieNode *node) {
    if (node == NULL) {
        return;
    }
    TrieNode *next = node->next;
    TrieNode *child = node->child;
    free(node);
    _node_destroy(next);
    _node_destroy(child);
}

void trie__add(Trie *trie, char *key, int val) {
    if (trie == NULL) {
        return;
    }

    if (trie->root == NULL) {
        trie->root = calloc(1, sizeof(TrieNode));
        assert(trie->root != NULL);
        trie->root->c = *key;
    }

    _node_add(trie->root, key, val);
}

void _node_add(TrieNode *node, char *key, int val) {
    if (*key == '\0' && node->c == '\0') {
        node->val = val;
        return;
    }

    if (*key != node->c) {
        // find next trie node that matches char
        if (node->next == NULL) {
            node->next = calloc(1, sizeof(TrieNode));
            assert(node->next);
            node->next->c = *key;
        }
        _node_add(node->next, key, val);
    } else {
        // move to child with next char
        if (node->child == NULL) {
            node->child = calloc(1, sizeof(TrieNode));
            assert(node->child != NULL);
            node->child->c = *(key + 1);
        }
        _node_add(node->child, key + 1, val);
    }
}

const int *trie__get(Trie *trie, char *key) {
    if (trie == NULL) {
        return NULL;
    }

    if (trie->root == NULL) {
        return NULL;
    }

    return _node_get(trie->root, key);
}

const int *_node_get(TrieNode *node, char *key) {
    if (*key == '\0') {
        return &node->val;
    }

    if (*key != node->c) {
        if (node->next == NULL) {
            return NULL;
        }
        return _node_get(node->next, key);
    } else {
        if (node->child == NULL) {
            return NULL;
        }
        return _node_get(node->child, key + 1);
    }
}

void trie__remove(Trie *trie, char *key) {
    if (trie == NULL) {
        return;
    }

    if (trie->root == NULL) {
        return;
    }

    _node_remove(trie, NULL, trie->root, key);
}

bool _node_remove(Trie *trie, TrieNode *prev, TrieNode *node, char *key) {
    if (node == NULL) {
        return false;
    }

    if (node->c == '\0') {
        free(node);
        return true;
    }

    if (node->c == *key) {
        if (_node_remove(NULL, NULL, node->child, key + 1)) {
            node->child = NULL;
            if (trie != NULL) {
                trie->root = node->next != NULL ? node->next : NULL;
            } else if (prev != NULL) {
                prev->next = node->next;
            }
            free(node);
            return true;
        }
    } else {
        _node_remove(NULL, node, node->next, key);
        return false;
    }
    return false;
}

void trie__print(Trie *trie) {
    if (trie->root == NULL) {
        return;
    }

    _node_print(trie->root, 1);
}

void _node_print(TrieNode *node, int level) {
    TrieNode *curr = node;
    while (curr != NULL) {
        printf("%d", level);
        printf("%*c", level, ' ');
        printf("%c", curr->c);
        if (curr->c == '\0') {
            printf("%d", curr->val);
        }
        printf("\n");
        _node_print(curr->child, level + 1);
        curr = curr->next;
    }
}