#include "doubly_linked_list.h"

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node {
    Node *next;
    Node *prev;
    int val;
};

struct dll {
    Node *head;
    Node *tail;
};

static Node *_node__create(int val) {
    Node *new_node = calloc(1, sizeof(Node));
    if (new_node == NULL) {
        printf("Out of memory.");
        return NULL;
    }
    new_node->val = val;
    return new_node;
}

static void _node__remove(DLL *dll, Node *node) {
    if (node->prev == NULL) {
        dll->head = node->next;
    } else {
        node->prev->next = node->next;
    }
    if (node->next == NULL) {
        dll->tail = node->prev;
    } else {
        node->next->prev = node->prev;
    }
    free(node);
}

static Node *_node__find(DLL *dll, int val) {
    Node *curr = dll->head;
    while (curr != NULL) {
        if (curr->val == val) {
            return curr;
        }
        curr = curr->next;
    }
    return NULL;
}

DLL *dll__create() {
    DLL *dll = calloc(1, sizeof(DLL));
    return dll;
}

void dll__destroy(DLL *dll) {
    while (dll->head != NULL) {
        _node__remove(dll, dll->head);
    }
    free(dll);
}

void dll__push_front(DLL *dll, int val) {
    Node *new_node = _node__create(val);
    if (new_node == NULL) {
        return;
    }

    if (dll->head == NULL) {
        dll->head = new_node;
        dll->tail = new_node;
        return;
    }

    new_node->next = dll->head;
    dll->head->prev = new_node;
    dll->head = new_node;
}

void dll__push_back(DLL *dll, int val) {
    Node *new_node = _node__create(val);
    if (new_node == NULL) {
        return;
    }

    if (dll->tail == NULL) {
        dll->head = new_node;
        dll->tail = new_node;
        return;
    }

    new_node->prev = dll->tail;
    dll->tail->next = new_node;
    dll->tail = new_node;
}

void dll__push_after(DLL *dll, int after_val, int val) {
    Node *curr = _node__find(dll, after_val);
    if (curr == NULL) {
        return;
    }

    if (curr->next == NULL) {
        dll__push_back(dll, val);
        return;
    }

    Node *new_node = _node__create(val);
    if (new_node == NULL) {
        return;
    }

    new_node->next = curr->next;
    curr->next->prev = new_node;
    curr->next = new_node;
}

void dll__remove(DLL *dll, int val) {
    Node *curr = _node__find(dll, val);
    if (curr != NULL) {
        _node__remove(dll, curr);
    }
}

void dll__clear(DLL *dll) {
    Node *curr = dll->head;
    Node *temp;
    while (curr != NULL) {
        temp = curr->next;
        _node__remove(dll, curr);
        curr = temp;
    }
}

bool dll__is_empty(DLL *dll) {
    return dll->head == NULL;
}

uint32_t dll__size(DLL *dll) {
    uint32_t size = 0;
    Node *curr = dll->head;
    while (curr != NULL) {
        size++;
        curr = curr->next;
    }
    return size;
}

void dll__print(DLL *dll) {
    Node *curr = dll->head;
    while (curr != NULL) {
        printf("%d ", curr->val);
        curr = curr->next;
    }
    printf("\n");
}