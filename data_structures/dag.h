/**
 * Directed Acyclic Graph where each node can only point to one other node.
 */

#pragma once

#include <stdbool.h>
#include <stdlib.h>

#define MAX_NODES 100
#define MAX_EDGES_PER_NODE 3

typedef struct _dag Dag;

typedef struct _node Node;

enum _search_kind { BFS, DFS };
typedef enum _search_kind SearchKind;

Dag *dag__create();
void dag__destroy(Dag *d);
bool dag__add_node(Dag *d, int v);
bool dag__add_edge(Dag *d, int src, int dest);
bool dag__contains(Dag *d, int a);
void dag__traverse(Dag *d, int v, SearchKind search_kind);
void dag__dfs(Dag *d, int v);
void dag__bfs(Dag *d, int v);
