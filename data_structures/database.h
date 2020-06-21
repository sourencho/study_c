#include <stdbool.h>
#include <stdint.h>

static const uint32_t MAX_STR_SIZE = 100;
static const uint8_t MAX_TAG_SIZE = 8;

typedef enum _Type { STR_TYPE, INT_TYPE, BOOL_TYPE } Type;

typedef struct _Field {
    char tag[MAX_TAG_SIZE];
    Type type;
} Field;

typedef struct _Value {
    Type type;
    union {
        char str_val[MAX_STR_SIZE];
        int int_val;
        bool bool_val;
    } val;
} Value;

typedef struct _Database Database;

typedef Field Schema[];

Database *db__create(Schema schema, uint32_t n_fields);
void db__destroy(Database *db);
uint32_t db__insert(Database *db, Value *values);
Value db__get_property(Database *db, uint32_t row_id, char *tag);
uint32_t db__filter(Database *db, bool (*filter)(const Value *), uint32_t *ids);