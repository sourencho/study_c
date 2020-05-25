#include <stdio.h>
#include <assert.h>

int sum_array(const int a[], int n) {
    int sum;
    const int *p = a;

    sum = 0;
    while(p < a + n) {
        sum += *p++;
    }
    return sum;
}

int main(void) {
    int sum = sum_array((int []){1, 2, 3, 4}, 4);
    assert(sum == 1 + 2 + 3 + 4);
    printf("Done without errors.\n");
}
