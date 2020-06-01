#include "vector.h"

struct _vector {
    Item *items;
    size_t size;
    size_t capacity;
};

Vector *vector__create() {
    Vector *v = malloc(sizeof(struct _vector));
    v->items = malloc(INIT_CAP * sizeof(Item));
    v->size = 0;
    v->capacity = INIT_CAP;
    return v;
}

void vector__destroy(Vector *v) {
    free(v->items);
    free(v);
}

size_t vector__size(Vector *v) {
    return v->size;
}

void vector__clear(Vector *v) {
    v->size = 0;
}

void vector__push(Vector *v, Item i) {
    v->size++;
    if (v->size >= v->capacity) {
        v->capacity *= 2;
        v->items = realloc(v->items, v->capacity * sizeof(Item));
    }

    v->items[v->size - 1] = i;
}

Item vector__get(Vector *v, size_t i) {
    return v->items[i];
}

size_t vector__capacity(Vector *v) {
    return v->capacity;
}

void vector__map(Vector *v, void (*map)(Item *)) {
    for (int i = 0; i < v->size; i++) {
        Item *item = &(v->items[i]);
        (*map)(item);
    }
}