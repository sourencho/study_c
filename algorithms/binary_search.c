#include "binary_search.h"

#include <stdio.h>

bool binary_search(const int *vals, uint32_t n_vals, int val) {
    int start = 0;
    int end = n_vals;
    int middle = (start + end) / 2;
    while (start <= end) {
        if (vals[middle] == val) {
            return true;
        } else if (vals[middle] < val) {
            start = middle + 1;
        } else {
            end = middle - 1;
        }
        middle = (start + end) / 2;
    }
    return false;
}
