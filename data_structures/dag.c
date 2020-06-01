#include "dag.h"

#include <stdio.h>

#include "stack.h"

struct _dag {
    int nodes[MAX_EDGES_PER_NODE][MAX_NODES];
    size_t edge_count[MAX_NODES];
};

Dag *dag__create() {
    Dag *d = calloc(1, sizeof(struct _dag));
    for (int i = 0; i < MAX_NODES; i++) {
        d->edge_count[i] =
            MAX_EDGES_PER_NODE + 1; // indicate that node doesn't exist
    }
    return d;
}

void dag__destroy(Dag *d) {
    free(d);
}

bool dag__add_node(Dag *d, int v) {
    if (v < MAX_NODES && !dag__contains(d, v)) {
        d->edge_count[v] = 0;
        return true;
    }
    return false;
}

bool dag__add_edge(Dag *d, int src, int dest) {
    if (dag__contains(d, src) && dag__contains(d, dest) &&
        d->edge_count[src] < MAX_EDGES_PER_NODE) {
        d->edge_count[src]++;
        d->nodes[src][d->edge_count[src] - 1] = dest;
        return true;
    }
    return false;
}

bool dag__contains(Dag *d, int v) {
    return d->edge_count[v] < MAX_EDGES_PER_NODE + 1;
}

void dag__traverse(Dag *d, int v, SearchKind search_kind) {
    if (search_kind == DFS) {
        printf("DFS from %d: ", v);
        dag__dfs(d, v);
        printf("\n");
    } else if (search_kind == BFS) {
        printf("BFS from %d: ", v);
        dag__bfs(d, v);
        printf("\n");
    } else {
        return;
    }
}

void dag__dfs(Dag *d, int v) {
    for (int i = 0; i < d->edge_count[v]; i++) {
        dag__dfs(d, d->nodes[v][i]);
    }
    printf("%d ", v);
}

void dag__bfs(Dag *d, int v) {
    Stack s = stack__create();
    stack__push(s, v);
    while (!stack__is_empty(s)) {
        int node = stack__pop(s);
        printf("%d ", node);
        for (int i = 0; i < d->edge_count[node]; i++) {
            stack__push(s, d->nodes[node][i]);
        }
    }

    stack__destroy(s);
}
