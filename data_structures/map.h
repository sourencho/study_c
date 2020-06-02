#pragma once

#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct _map Map;
typedef struct _bucket Bucket;

Map *map__create(uint32_t size);
void map__destroy(Map *map);

/**
 * Insert to map.
 * Key and value will be copied and map will hold their memory.
 * If key already exists overwrite.
 * If map load is larger than 2/3 of the size then map is resized to double its
 * size and all existing items are reinserted with new hashes.
 */
void map__insert(Map *map, char *key, void *val, uint32_t val_size);

/**
 * Get pointer to value with key in map.
 * If key isn't present in map return NULL.
 */
void *map__get(Map *map, char *key);

/**
 * Remove item with key from map if present.
 * Return false if removal failed or if key not presnet.
 */
bool map__remove(Map *map, char *key);
