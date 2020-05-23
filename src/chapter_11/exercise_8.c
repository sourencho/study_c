#include <stdio.h>
#include <limits.h>

int *find_largest(int a[], int n);

int main(void) {
    int a[7] = {10, 5, 6, 1, 30, 8, 21};
    printf("%d\n", *find_largest(a, 7));
}

int *find_largest(int a[], int n) {
    if (n==0) {
        return 0;
    }
    int *l = &a[0];
    for(int i=1; i < n; i++) {
        if(a[i] > *l) {
            l = &a[i];
        }
    }
    return l;
}
