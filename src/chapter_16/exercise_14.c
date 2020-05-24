#include <assert.h>
#include <stdio.h>

#define PI 3.14

// Note: only implementing circle

typedef enum {RECTANGLE, CIRCLE} ShapeKind;

struct point {
    int x;
    int y;
};

struct shape {
    ShapeKind shape_kind;         // RECTANGLE or CIRCLE
    struct point center;    // coord of center
    union {
        struct {
            int height;
            int width;
        } rectangle;
        struct {
            int radius;
        } circle;
    } u;
} s;

double area(struct shape s) {
    return 2. * PI * s.u.circle.radius * s.u.circle.radius;
}

struct shape move(struct shape s, int x, int y) {
    s.center.x += x;
    s.center.y += y;
    return s;
}

struct shape scale(struct shape s, int k) {
    s.u.circle.radius *= k;
    return s;
}

int main(void) {
    s = (struct shape) {
        .shape_kind = CIRCLE,
        .center = {.x = 5, .y = 10},
        .u = {.circle = {.radius = 4}},
    };
    assert(area(s) == 2. * PI * 4 * 4);
    assert(move(s, 4, -2).center.x == 9);
    assert(move(s, 4, -2).center.y == 8);
    assert(scale(s, 3).u.circle.radius == 12);
    printf("Done without errors.\n");
}




