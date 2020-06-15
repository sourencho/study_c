#include "quadtree.h"

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

int main() {
    // create
    AABB boundary = {.center = {.x = 6., .y = 6.}, .half_size = 6.};
    Quadtree *qt = quadtree__create(boundary);

    // insert
    Point point_tl_1 = {.x = 2, .y = 2};
    Point point_tl_2 = {.x = 4, .y = 4};
    Point point_tr_1 = {.x = 7, .y = 2};
    Point point_bl_1 = {.x = 2, .y = 7};
    Point point_br_1 = {.x = 7, .y = 7};
    Point point_ob_1 = {.x = -2, .y = -2};
    Point point_ob_2 = {.x = 13, .y = 13};
    quadtree__insert(qt, point_tl_1);
    quadtree__insert(qt, point_tr_1);
    quadtree__insert(qt, point_bl_1);
    quadtree__insert(qt, point_br_1);
    quadtree__insert(qt, point_ob_1);
    quadtree__insert(qt, point_ob_2);

    quadtree__insert(qt, point_tl_1);
    quadtree__insert(qt, point_tl_1);
    quadtree__insert(qt, point_tl_2);
    quadtree__insert(qt, point_tl_2);

    // print
    quadtree__print(qt, 0);

    // search
    // todo

    // destroy
    quadtree__destroy(qt);
}