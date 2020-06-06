#include <stdio.h>

#define MK_COLOR(r, g, b) ((long) (r << 16) | (g << 8) | b)


void print_binary(int number) {
    if (number) {
        print_binary(number >> 1);
        putc((number & 1) ? '1' : '0', stdout);
    }
}

int main(void) {
    print_binary(MK_COLOR(1, 3, 7));
    printf("\n");
}
