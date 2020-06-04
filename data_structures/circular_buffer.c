#include "circular_buffer.h"

struct _circular_buffer {
    uint32_t cap;
    int *buff;
    uint32_t tail;
    uint32_t head;
};

static bool _cb__is_full(CircularBuffer *cb);
static void _cb__resize(CircularBuffer *cb);

CircularBuffer *cb__create(uint32_t init_cap) {
    CircularBuffer *cb = malloc(sizeof(CircularBuffer));
    if (cb == NULL) {
        fprintf(stderr, "Out of memory.\n");
        return NULL;
    }
    cb->cap = init_cap + 1;
    cb->buff = calloc(cb->cap, sizeof(int)); // calloc for debugging
    if (cb->buff == NULL) {
        free(cb);
        fprintf(stderr, "Out of memory.\n");
        return NULL;
    }
    cb->tail = 0;
    cb->head = 0;
    return cb;
}

void cb__destroy(CircularBuffer *cb) {
    free(cb->buff);
    free(cb);
}

void cb__push(CircularBuffer *cb, int v) {
    if (_cb__is_full(cb)) {
        _cb__resize(cb);
    }
    uint32_t next_head = (cb->head + 1) % cb->cap;
    cb->buff[cb->head] = v;
    cb->head = next_head;
}

int cb__pop(CircularBuffer *cb) {
    if (cb__is_empty(cb)) {
        fprintf(stderr, "Buffer empty. Pop failed.\n");
        exit(1);
    }
    int out = cb->buff[cb->tail];
    cb->tail = (cb->tail + 1) % cb->cap;
    return out;
}

bool cb__is_empty(CircularBuffer *cb) {
    return cb->tail == cb->head;
}

void cb__print(CircularBuffer *cb) {
    for (int i = 0; i < cb->cap; i++) {
        printf("%02d ", cb->buff[i]);
    }
    printf("\n");
    for (int i = 0; i < cb->cap; i++) {
        if (i == cb->tail) {
            printf(" t ");
        } else if (i == cb->head) {
            printf(" h ");
        } else {
            printf("__ ");
        }
    }
    printf("\n");
}

static bool _cb__is_full(CircularBuffer *cb) {
    return cb->tail == (cb->head + 1) % cb->cap;
}

/**
 * Buffer is full
 * e.g.
 *  0 1 2 3 4
 *  ---------
 *  4 5 1 2 3
 *  _ h t _ _
 *
 * Double in capacity and move tail to end
 * e.g.
 *  0 1 2 3 4 5 6 7 8 9
 *  -------------------
 *  4 5 _ _ _ _ _ 1 2 3
 *  _ h _ _ _ _ _ t _ _
 */
static void _cb__resize(CircularBuffer *cb) {
    uint32_t new_cap = cb->cap * 2;

    // realloc
    int *new_buff = realloc(cb->buff, new_cap * sizeof(int));
    if (new_buff == NULL) {
        fprintf(stderr, "Out of memory.\n");
        exit(1);
    }
    cb->buff = new_buff;

    // set new values to zero for debugging
    for (int i = cb->cap; i < new_cap; i++) {
        cb->buff[i] = 0;
    }

    // shift head or tail to end
    uint32_t end = cb->tail;
    cb->tail = cb->tail + cb->cap;

    uint32_t end_len = cb->cap - end;
    for (int i = 0; i < end_len; i++) {
        cb->buff[end + cb->cap + i] = cb->buff[end + i];
    }
    cb->cap = new_cap;
}