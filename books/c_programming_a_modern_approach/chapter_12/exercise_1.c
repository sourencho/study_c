#include <stdbool.h>
#include <stdio.h>
#include <assert.h>


int main(void) {
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *p = &a[1], *q = &a[5];

    assert(*(p+3) == 14);
    assert(*(q-3) == 34);
    assert(q-p == 4);
    assert(p < q == true);
    assert(*p < *q == false);
    printf("Done without errors.\n");
}
