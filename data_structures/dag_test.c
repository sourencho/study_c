
#include "dag.h"

#include <assert.h>
#include <stdbool.h>

int main(void) {
    Dag *d = dag__create();

    dag__add_node(d, 1);
    dag__add_node(d, 2);
    dag__add_node(d, 3);
    dag__add_node(d, 4);
    dag__add_node(d, 5);
    dag__add_node(d, 6);
    dag__add_node(d, 7);

    assert(dag__add_edge(d, 1, 2) == true);
    assert(dag__add_edge(d, 1, 3) == true);
    assert(dag__add_edge(d, 1, 4) == true);
    assert(dag__add_edge(d, 1, 5) == false);
    assert(dag__add_edge(d, 1, 8) == false);

    assert(dag__add_edge(d, 2, 5) == true);
    assert(dag__add_edge(d, 2, 6) == true);

    assert(dag__add_edge(d, 3, 7) == true);

    dag__traverse(d, 1, BFS);
    dag__traverse(d, 1, DFS);

    dag__destroy(d);
}