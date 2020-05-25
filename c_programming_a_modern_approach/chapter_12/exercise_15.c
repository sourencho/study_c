#include <stdio.h>

void print_day(int n, int a[n]);
void print_day_from_days(int n, int m, int i, int a[n][m]);

int main(void) {
    int temperatures[2][7] = {{50, 60, 45, 25, 11, 88, 100}, {55, 25, 60, 52, 20, 59, 66}};
    print_day(7, temperatures[1]);
    print_day_from_days(2, 7, 1, temperatures);
}

void print_day(int n, int a[n]) {
    int *p;
    for(p = a; p < a + n; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}

void print_day_from_days(int n, int m, int i, int a[n][m]) {
    int *p;
    for(p = a[i]; p < a[i] + m; p++) {
        printf("%d ", *p);
    }
    printf("\n");
}
