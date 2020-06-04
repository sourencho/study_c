/**
 * Circular buffer that grows dynamically in size.
 */

#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct _circular_buffer CircularBuffer;

CircularBuffer *cb__create(uint32_t init_cap);

void cb__destroy(CircularBuffer *cb);

void cb__push(CircularBuffer *cb, int v);

int cb__pop(CircularBuffer *cb);

bool cb__is_empty(CircularBuffer *cb);

void cb__print(CircularBuffer *cb);