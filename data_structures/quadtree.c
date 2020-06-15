#include "quadtree.h"

#include <stdio.h>
#include <stdlib.h>

struct _quadtree {
    // Represent boundaries quadtree with axis-aligned bounding box
    AABB boundary;

    // Points
    Point points[NODE_POINT_CAP];
    uint32_t n_points;

    // Children
    Quadtree *top_left;
    Quadtree *top_right;
    Quadtree *bot_left;
    Quadtree *bot_right;
};

bool AABB__contains(const AABB *aabb, const Point *p) {
    return (p->x >= aabb->center.x - aabb->half_size &&
            p->y >= aabb->center.y - aabb->half_size &&
            p->x < aabb->center.x + aabb->half_size &&
            p->y < aabb->center.y + aabb->half_size);
}

// Two axes aligned boxes (of any dimension) overlap if and only if the
// projections to all axes overlap. The projection to an axis is simply the
// coordinate range for that axis.
bool AABB__overlap(const AABB *a, const AABB *b) {
    float a_x_max = a->center.x + a->half_size;
    float a_x_min = a->center.x - a->half_size;
    float a_y_max = a->center.y + a->half_size;
    float a_y_min = a->center.y - a->half_size;
    float b_x_max = a->center.x + a->half_size;
    float b_x_min = a->center.x - a->half_size;
    float b_y_max = a->center.y + a->half_size;
    float b_y_min = a->center.y - a->half_size;

    bool is_overlap_x = a_x_max >= b_x_min && b_x_max >= a_x_min;
    bool is_overlap_y = a_y_max >= b_y_min && b_y_max >= a_y_min;
    return is_overlap_x && is_overlap_y;
}

Quadtree *quadtree__create(AABB boundary) {
    Quadtree *qt = calloc(1, sizeof(Quadtree));
    if (qt == NULL) {
        fprintf(stderr, "Failed to create Quadtree. Out of memory.\n");
        return NULL;
    }

    qt->boundary = boundary;
    return qt;
}

void quadtree__destroy(Quadtree *qt) {
    if (qt == NULL) {
        return;
    }
    quadtree__destroy(qt->top_left);
    quadtree__destroy(qt->top_right);
    quadtree__destroy(qt->bot_left);
    quadtree__destroy(qt->bot_right);
    free(qt);
}

void quadtree__insert(Quadtree *qt, Point p) {
    // If point isn't within bounds, don't insert
    if (!(AABB__contains(&qt->boundary, &p))) {
        return;
    }

    if (qt->n_points >= NODE_POINT_CAP) {
        if (qt->top_left == NULL) {
            // Create children
            float quarter_size = qt->boundary.half_size / 2.;
            qt->top_left = quadtree__create(
                (AABB){.center = {.x = qt->boundary.center.x - quarter_size,
                                  .y = qt->boundary.center.y - quarter_size},
                       .half_size = quarter_size});
            qt->top_right = quadtree__create(
                (AABB){.center = {.x = qt->boundary.center.x + quarter_size,
                                  .y = qt->boundary.center.y - quarter_size},
                       .half_size = quarter_size});
            qt->bot_left = quadtree__create(
                (AABB){.center = {.x = qt->boundary.center.x - quarter_size,
                                  .y = qt->boundary.center.y + quarter_size},
                       .half_size = quarter_size});
            qt->bot_right = quadtree__create(
                (AABB){.center = {.x = qt->boundary.center.x + quarter_size,
                                  .y = qt->boundary.center.y + quarter_size},
                       .half_size = quarter_size});

            // Insert points
            for (int i = 0; i < qt->n_points; i++) {
                quadtree__insert(qt->top_left, qt->points[i]);
                quadtree__insert(qt->top_right, qt->points[i]);
                quadtree__insert(qt->bot_left, qt->points[i]);
                quadtree__insert(qt->bot_right, qt->points[i]);
            }
        }

        // Insert new point
        quadtree__insert(qt->top_left, p);
        quadtree__insert(qt->top_right, p);
        quadtree__insert(qt->bot_left, p);
        quadtree__insert(qt->bot_right, p);
    } else {
        qt->points[qt->n_points++] = p;
    }
}

void quadtree__print(Quadtree *qt, uint32_t level) {
    if (qt->top_left == NULL) {
        printf("%*c- ", level, ' ');
        for (int i = 0; i < qt->n_points; i++) {
            printf("(%.2f, %.2f) ", qt->points[i].x, qt->points[i].y);
        }
        printf("\n");
    } else {
        quadtree__print(qt->top_left, level + 1);
        quadtree__print(qt->top_right, level + 1);
        quadtree__print(qt->bot_left, level + 1);
        quadtree__print(qt->bot_right, level + 1);
    }
}