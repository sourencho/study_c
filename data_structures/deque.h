/**
 * Deque (Double-ended queue) implemented with a dynamic circular buffer.
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

static const uint32_t INIT_CAP = 5;

typedef struct _deque Deque;

Deque *deque__create();

void deque__destroy(Deque *deque);

void deque__push_back(Deque *deque, int v);

void deque__push_front(Deque *deque, int v);

int deque__pop_back(Deque *deque);

int deque__pop_front(Deque *deque);

bool deque__is_empty(Deque *deque);

void deque__print(Deque *deque);