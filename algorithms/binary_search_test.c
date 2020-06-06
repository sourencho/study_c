#include "binary_search.h"

#include <assert.h>
#include <stdio.h>

int main() {
    int primes[] = {1, 2, 3, 5, 7, 11, 13};
    uint32_t n_primes = sizeof(primes) / sizeof(primes[0]);
    assert(binary_search(primes, n_primes, 11) == true);
    assert(binary_search(primes, n_primes, 1) == true);
    assert(binary_search(primes, n_primes, 13) == true);
    assert(binary_search(primes, n_primes, 4) == false);

    int empty[] = {};
    uint32_t n_empty = sizeof(empty) / sizeof(empty[0]);
    assert(binary_search(empty, n_empty, 11) == false);
    assert(binary_search(empty, n_empty, 4) == false);
    printf("Tests passed.\n");
}