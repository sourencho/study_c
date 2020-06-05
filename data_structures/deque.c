#include "deque.h"

#include <assert.h>

struct _deque {
    uint32_t cap;
    int *buff;
    uint32_t tail;
    uint32_t head;
};

static uint32_t _circ_incr(uint32_t i, uint32_t cap) {
    return (i + 1) % cap;
}
static uint32_t _circ_decr(uint32_t i, uint32_t cap) {
    return (i + cap - 1) % cap;
}

static bool deque__is_full(Deque *deque) {
    return _circ_incr(deque->head + 1, deque->cap) == deque->tail;
};

static void _deque__resize(Deque *deque);

Deque *deque__create() {
    Deque *deque = malloc(sizeof(Deque));
    if (deque == NULL) {
        fprintf(stderr, "Out of memory.\n");
        return NULL;
    }
    deque->cap = INIT_CAP + 1;
    deque->buff = calloc(deque->cap, sizeof(int)); // calloc for debugging
    if (deque->buff == NULL) {
        free(deque);
        fprintf(stderr, "Out of memory.\n");
        return NULL;
    }
    deque->tail = deque->cap / 2 - 1;
    deque->head = deque->cap / 2;
    return deque;
}

void deque__destroy(Deque *deque) {
    free(deque->buff);
    free(deque);
}

void deque__push_back(Deque *deque, int v) {
    if (deque__is_full(deque)) {
        _deque__resize(deque);
    }
    uint32_t next_head = _circ_incr(deque->head, deque->cap);
    deque->buff[deque->head] = v;
    deque->head = next_head;
}

void deque__push_front(Deque *deque, int v) {
    if (deque__is_full(deque)) {
        _deque__resize(deque);
    }
    uint32_t next_tail = _circ_decr(deque->tail, deque->cap);
    deque->buff[deque->tail] = v;
    deque->tail = next_tail;
}

int deque__pop_back(Deque *deque) {
    if (deque__is_empty(deque)) {
        fprintf(stderr, "Buffer empty. Pop failed.\n");
        exit(1);
    }
    deque->head = _circ_decr(deque->head, deque->cap);
    return deque->buff[deque->head];
}

int deque__pop_front(Deque *deque) {
    if (deque__is_empty(deque)) {
        fprintf(stderr, "Buffer empty. Pop failed.\n");
        exit(1);
    }
    deque->tail = _circ_incr(deque->tail, deque->cap);
    return deque->buff[deque->tail];
}

bool deque__is_empty(Deque *deque) {
    return _circ_incr(deque->tail, deque->cap) == deque->head;
}

void deque__print(Deque *deque) {
    for (int i = 0; i < deque->cap; i++) {
        printf("%02d ", deque->buff[i]);
    }
    printf("\n");
    for (int i = 0; i < deque->cap; i++) {
        if (i == deque->tail && i == deque->head) {
            printf("th ");
        } else if (i == deque->tail) {

            printf(" t ");
        } else if (i == deque->head) {
            printf(" h ");
        } else {
            printf("__ ");
        }
    }
    printf("\n");
}

/**
 * Buffer is full
 * e.g.
 *  0 1 2 3 4
 *  ---------
 *  4 5 1 2 3
 *  _ h t _ _
 *
 * Double in capacity and move tail to end if it's ahead of head
 * e.g.
 *  0 1 2 3 4 5 6 7 8 9
 *  -------------------
 *  4 5 _ _ _ _ _ 1 2 3
 *  _ h _ _ _ _ _ t _ _
 */
static void _deque__resize(Deque *deque) {
    deque__print(deque);
    assert(deque->tail != deque->head); // should resize before this happens

    uint32_t new_cap = deque->cap * 2;

    // realloc
    int *new_buff = realloc(deque->buff, new_cap * sizeof(int));
    if (new_buff == NULL) {
        fprintf(stderr, "Out of memory.\n");
        exit(1);
    }
    deque->buff = new_buff;

    // set new values to zero for debugging
    for (int i = deque->cap; i < new_cap; i++) {
        deque->buff[i] = 0;
    }

    if (deque->tail > deque->head) {
        for (int i = 0; i < deque->cap - deque->tail; i++) {
            deque->buff[deque->tail + deque->cap + i] =
                deque->buff[deque->tail + i];
        }
        deque->tail = (deque->tail + deque->cap) % new_cap;
    }

    deque->cap = new_cap;
}