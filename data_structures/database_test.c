#include "database.h"

#include <assert.h>
#include <string.h>

bool cool_filter(const Value *row) {
    const Value *value_ptr = row + 2;
    return value_ptr->val.bool_val == true;
}

bool small_filter(const Value *row) {
    const Value *value_ptr = row + 1;
    return value_ptr->val.int_val < 12;
}

int main() {
    // Create
    uint32_t n_fields = 3;
    Schema schema = {(Field){.tag = "name", .type = STR_TYPE},
                     (Field){.tag = "size", .type = INT_TYPE},
                     (Field){.tag = "cool", .type = BOOL_TYPE}};
    Database *db = db__create(schema, n_fields);

    // Insert
    Value row_1_values[] = {(Value){.type = STR_TYPE, .val = {"mario"}},
                            (Value){.type = INT_TYPE, .val = {5}},
                            (Value){.type = BOOL_TYPE, .val = {false}}};
    uint32_t row_1_id = db__insert(db, row_1_values);

    Value row_2_values[] = {(Value){.type = STR_TYPE, .val = {"luigi"}},
                            (Value){.type = INT_TYPE, .val = {10}},
                            (Value){.type = BOOL_TYPE, .val = {true}}};
    uint32_t row_2_id = db__insert(db, row_2_values);

    Value row_3_values[] = {(Value){.type = STR_TYPE, .val = {"taod"}},
                            (Value){.type = INT_TYPE, .val = {15}},
                            (Value){.type = BOOL_TYPE, .val = {true}}};
    uint32_t row_3_id = db__insert(db, row_3_values);

    // Get
    Value row_1_name = db__get_property(db, row_1_id, "name");
    Value row_1_size = db__get_property(db, row_1_id, "size");
    Value row_1_cool = db__get_property(db, row_1_id, "cool");

    assert(strcmp(row_1_name.val.str_val, "mario") == 0);
    assert(row_1_size.val.int_val == 5);
    assert(row_1_cool.val.bool_val == false);

    Value row_2_name = db__get_property(db, row_2_id, "name");
    Value row_2_size = db__get_property(db, row_2_id, "size");
    Value row_2_cool = db__get_property(db, row_2_id, "cool");

    assert(strcmp(row_2_name.val.str_val, "luigi") == 0);
    assert(row_2_size.val.int_val == 10);
    assert(row_2_cool.val.bool_val == true);

    // Filter
    uint32_t cool_ids[3];
    uint32_t n_cool_ids = db__filter(db, cool_filter, cool_ids);
    assert(n_cool_ids == 2);
    assert(cool_ids[0] == row_2_id);
    assert(cool_ids[1] == row_3_id);

    uint32_t small_ids[3];
    uint32_t n_small_ids = db__filter(db, small_filter, small_ids);
    assert(n_small_ids == 2);
    assert(small_ids[0] == row_1_id);
    assert(small_ids[1] == row_2_id);

    // Destroy
    db__destroy(db);
}