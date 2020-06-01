#pragma once

#include <stdlib.h>

#include "item.h"

#define INIT_CAP 2

typedef struct _vector Vector;

Vector *vector__create();
void vector__destroy(Vector *v);
size_t vector__size(Vector *v);
void vector__clear(Vector *v);
void vector__push(Vector *v, Item i);
Item vector__get(Vector *v, size_t i);
size_t vector__capacity(Vector *v);