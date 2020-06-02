#include "map.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

static uint32_t _get_hash(char *key);
static void _destroy_buckets(Bucket *bucket);
static void _destroy_bucket(Bucket *bucket);
static void _create_and_insert_bucket(uint32_t hash, uint32_t index, char *key,
                                      void *val, uint32_t val_size,
                                      Bucket **buckets);

struct _map {
    uint32_t size;
    uint32_t load;
    Bucket **buckets;
};

struct _bucket {
    char *key;
    void *val;
    uint32_t val_size;
    uint32_t hash;
    Bucket *next;
};

Map *map__create(uint32_t size) {
    Map *map = calloc(1, sizeof(Map));
    map->buckets = calloc(size, sizeof(Bucket *));
    map->size = size;
    return map;
}

void map__destroy(Map *map) {
    for (int i = 0; i < map->size; i++) {
        _destroy_buckets(map->buckets[i]);
    }
    free(map->buckets);
    free(map);
}

void map__insert(Map *map, char *key, void *val, uint32_t val_size) {
    // Resize map if it's 2/3rds full
    if (3 * map->load > 2 * map->size) {
        // Double size
        uint32_t old_size = map->size;
        uint32_t new_size = old_size * 2;

        Bucket **old_buckets = map->buckets;
        Bucket **new_buckets = calloc(new_size, sizeof(Bucket *));
        assert(new_buckets != NULL);

        // Rehash and move all old buckets into new buckets
        for (int i = 0; i < old_size; i++) {
            Bucket *curr = old_buckets[i];
            while (curr != NULL) {
                uint32_t new_index = curr->hash % new_size;
                _create_and_insert_bucket(curr->hash, new_index, curr->key,
                                          curr->val, curr->val_size,
                                          new_buckets);
                curr = curr->next;
            }
            _destroy_buckets(old_buckets[i]);
        }
        free(old_buckets);
        map->buckets = new_buckets;
        map->size = new_size;
    }

    uint32_t hash = _get_hash(key);
    uint32_t index = hash % (map->size);

    // If value exists then overwrite
    Bucket *curr = map->buckets[index];
    while (curr != NULL) {
        if (strcmp(curr->key, key) == 0) {
            void *new_val = realloc(curr->val, val_size);
            assert(new_val != NULL);
            curr->val = new_val;
            curr->val_size = val_size;
            memcpy(new_val, val, val_size);
            return;
        }
        curr = curr->next;
    }

    _create_and_insert_bucket(hash, index, key, val, val_size, map->buckets);
    map->load++;
}

void *map__get(Map *map, char *key) {
    uint32_t hash = _get_hash(key);
    uint32_t index = hash % (map->size);

    // Search list for key value
    Bucket *bucket = map->buckets[index];
    while (bucket != NULL) {
        if (strcmp(key, bucket->key) == 0) {
            return bucket->val;
        }
        bucket = bucket->next;
    }

    return NULL;
}

bool map__remove(Map *map, char *key) {
    // Get linked list of buckets
    uint32_t hash = _get_hash(key);
    uint32_t index = hash % (map->size);

    // Check first bucket
    Bucket *prev = map->buckets[index];
    if (prev == NULL) {
        return false;
    }
    Bucket *next = prev->next;
    if (strcmp(prev->key, key) == 0) {
        map->buckets[index] = next;
        _destroy_bucket(prev);
        return true;
    }

    // Check other buckets
    while (next != NULL) {
        if (strcmp(next->key, key) == 0) {
            prev->next = next->next;
            _destroy_bucket(next);
            return true;
        }
        prev = next;
        next = next->next;
    }
    return false;
}

static uint32_t _get_hash(char *key) {
    uint32_t hash = 0;
    int c;
    while ((c = *key++) != '\0') {
        hash += c;
    }
    return hash;
}

static void _destroy_buckets(Bucket *bucket) {
    Bucket *curr = bucket;
    Bucket *temp;
    while (curr != NULL) {
        temp = curr->next;
        _destroy_bucket(curr);
        curr = temp;
    }
}

static void _destroy_bucket(Bucket *bucket) {
    free(bucket->val);
    free(bucket->key);
    free(bucket);
}

static void _create_and_insert_bucket(uint32_t hash, uint32_t index, char *key,
                                      void *val, uint32_t val_size,
                                      Bucket **buckets) {

    // Allocate and populate new bucket
    Bucket *new_bucket = malloc(sizeof(Bucket));
    assert(new_bucket != NULL);
    new_bucket->key = strdup(key);
    new_bucket->val = malloc(val_size);
    memcpy(new_bucket->val, val, val_size);
    new_bucket->val_size = val_size;
    new_bucket->hash = hash;

    // Insert into linked list of buckets
    Bucket *bucket = buckets[index];
    new_bucket->next = bucket;
    buckets[index] = new_bucket;
}