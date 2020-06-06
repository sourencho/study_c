#include <stdio.h>

// Instead I implemented flip bit n

void print_binary(int number) {
    if (number) {
        print_binary(number >> 1);
        putc((number & 1) ? '1' : '0', stdout);
    }
}

int set_bit_n(int i, int n) {
    return i | (1 << n);
}

int clear_bit_n(int i, int n) {
    return i & ~(1 << n);
}

int flip_bit_n(int i, int n) {
    return i ^ (1 << n);
}

int main(void) {
    int z = 0xff;           // 11111111
    z = flip_bit_n(z, 6);   // 10111111
    print_binary(z);
    printf("\n");

    int y = 0xf0;           // 11110000
    y = set_bit_n(y, 2);    // 11110100
    print_binary(y);
    printf("\n");

    int x = 0xff;           // 11111111
    x = clear_bit_n(x, 4);  // 11101111
    print_binary(x);
    printf("\n");
}

