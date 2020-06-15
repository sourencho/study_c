#pragma once

#include <stdbool.h>
#include <stdint.h>

static const uint32_t NODE_POINT_CAP = 4;

typedef struct _quadtree Quadtree;

typedef struct _point {
    float x, y;
} Point;

typedef struct _aabb {
    Point center;
    float half_size;
} AABB;

bool AABB__contains(const AABB *aabb, const Point *p);
bool AABB__overlap(const AABB *a, const AABB *b);

Quadtree *quadtree__create(AABB boundary);
void quadtree__destroy(Quadtree *qt);

void quadtree__insert(Quadtree *qt, Point p);

void quadtree__print(Quadtree *qt, uint32_t level);
