#include <stdio.h>

void print_binary(int number) {
    if (number) {
        print_binary(number >> 1);
        putc((number & 1) ? '1' : '0', stdout);
    }
}

unsigned short swap_bytes(unsigned short i) {
    return ((0x0ff & i) << 8) | ((0xff00 & i) >> 8);
}

int main(void) {
    unsigned short x = 0x1234;  // 0001 0010 0011 0100
    x = swap_bytes(x);          // 0011 0100 0001 0010
    print_binary(x);
    printf("\n");
    printf("%hx\n", x);         // print hex
}
