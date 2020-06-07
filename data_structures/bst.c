#include "bst.h"

#include <stdlib.h>

typedef struct _node Node;

struct _node {
    int val;
    Node *left;
    Node *right;
};

struct _bst {
    Node *head;
};

static Node *_node__rot_l(Node *head) {
    Node *new_head = head->right;
    head->right = new_head->left;
    new_head->left = head;
    return new_head;
}

static Node *_node__rot_r(Node *head) {
    Node *new_head = head->left;
    head->left = new_head->right;
    new_head->right = head;
    return new_head;
}

static void _node__destroy(Node *node) {
    if (node == NULL) {
        return;
    }
    _node__destroy(node->left);
    _node__destroy(node->right);
    free(node);
}

static Node *_node__insert(Node *node, int val) {
    if (node == NULL) {
        Node *new_node = calloc(1, sizeof(Node));
        if (new_node == NULL) {
            printf("Out of memory");
            exit(1);
        }
        new_node->val = val;
        return new_node;
    } else if (val >= node->val) {
        node->right = _node__insert(node->right, val);
        node = _node__rot_l(node);
    } else if (val < node->val) {
        node->left = _node__insert(node->left, val);
        node = _node__rot_r(node);
    }
    return node;
}

static void _node__print(Node *node, int depth) {
    if (node == NULL) {
        printf("%*c", depth, ' ');
        printf("-\n");
        return;
    }

    printf("%*c", depth, ' ');
    printf("%d\n", node->val);
    _node__print(node->left, depth + 1);
    _node__print(node->right, depth + 1);
}

static bool _node__search(Node *node, int val) {
    if (node == NULL) {
        return false;
    }

    if (val > node->val) {
        return _node__search(node->right, val);
    } else if (val < node->val) {
        return _node__search(node->left, val);
    } else {
        return true;
    }
}

BST *bst__create() {
    BST *bst = calloc(1, sizeof(Node));
    return bst;
}

void bst__insert(BST *bst, int val) {
    if (bst == NULL) {
        return;
    }
    bst->head = _node__insert(bst->head, val);
}

bool bst__search(BST *bst, int val) {
    if (bst == NULL) {
        return false;
    }
    return _node__search(bst->head, val);
}

void bst__delete(BST *bst, int val) {
    // _node__delete(bst->head, val);
}

void bst__destroy(BST *bst) {
    if (bst == NULL) {
        return;
    }
    _node__destroy(bst->head);
    free(bst);
}

void bst__print(BST *bst) {
    if (bst == NULL) {
        return;
    }
    printf(">\n");
    _node__print(bst->head, 1);
    printf("\n");
}