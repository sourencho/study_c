
#include "database.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct _Database {
    Field *schema;
    uint32_t n_fields;
    uint32_t n_rows;
    Value *data;
};

static uint32_t _db__tag_index(Database *db, char *tag) {
    uint32_t tag_index;
    for (tag_index = 0; tag_index <= db->n_fields; tag_index++) {
        if (strcmp(db->schema[tag_index].tag, tag) == 0) {
            break;
        }
    }
    return tag_index;
}

Database *db__create(Schema schema, uint32_t n_fields) {
    Database *db = malloc(sizeof(Database));
    if (db == NULL) {
        printf("Failed to create database. Out of memory.\n");
        return NULL;
    }
    db->schema = schema;
    db->n_fields = n_fields;
    db->n_rows = 0;
    db->data = NULL;
    return db;
}

void db__destroy(Database *db) {
    if (db == NULL) {
        return;
    }

    free(db->data);
    free(db);
}

uint32_t db__insert(Database *db, Value *values) {
    // Allocate row memory
    Value *new_data =
        realloc(db->data, (++(db->n_rows)) * db->n_fields * sizeof(Value));
    if (new_data == NULL) {
        printf("Failed to insert row. Out of memory.\n");
        return 0;
    }
    db->data = new_data;

    // Populate row values
    Value *row_ptr = db->data + ((db->n_rows - 1) * db->n_fields);
    memcpy(row_ptr, values, sizeof(Value) * db->n_fields);
    return db->n_rows - 1;
}

Value db__get_property(Database *db, uint32_t row_id, char *tag) {
    uint32_t tag_index = _db__tag_index(db, tag);
    if (tag_index == db->n_fields) {
        printf("Failed to get property. Tag not in schema.");
        return (Value){};
    }

    Value *value_ptr = db->data + (row_id * db->n_fields) + tag_index;
    return *value_ptr;
}

uint32_t db__filter(Database *db, bool (*filter)(const Value *),
                    uint32_t *ids) {
    uint32_t count = 0;
    for (int row_id = 0; row_id < db->n_rows; row_id++) {
        Value *value_ptr = db->data + (row_id * db->n_fields);
        if ((*filter)(value_ptr)) {
            ids[count++] = row_id;
        }
    }
    return count;
}
