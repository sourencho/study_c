#include <stdio.h>
#include <assert.h>

int count_spaces(const char *s);

int main(void) {
    char test[] = "There are three spaces";
    assert(count_spaces(test) == 3);
    printf("Done without errors.\n");
}

int count_spaces(const char *s) {
    int count = 0;

    while(*s) {
        if (*s++ == ' ') {
            count++;
        }
    }

    return count;
}
