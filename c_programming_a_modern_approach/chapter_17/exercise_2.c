#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

char *duplicate(const char *str) {
    char *d = malloc(sizeof(str) * (strlen(str) + 1));
    if (d == NULL) { 
        return NULL;
    }
    strcpy(d, str);
    return d;
}

int main(void) {
    char s[] = "hello";
    char *d = duplicate(s);
    assert(strcmp(s, d) == 0);
    printf("Done without errors.\n");
}
