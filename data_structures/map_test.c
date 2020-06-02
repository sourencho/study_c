#include "map.h"

#include <assert.h>
#include <stdio.h>
#include <string.h>

int main() {
    Map *map = map__create(1);

    char mario_data[] = "red";
    map__insert(map, "mario", mario_data, sizeof(mario_data));

    assert(strcmp(map__get(map, "mario"), mario_data) == 0);

    char luigi_data[] = "green";
    map__insert(map, "luigi", luigi_data, sizeof(luigi_data));

    char mario_data_2[] = "maroon";
    map__insert(map, "mario", mario_data_2, sizeof(mario_data_2));

    assert(strcmp(map__get(map, "mario"), mario_data_2) == 0);

    assert(map__remove(map, "luigi") == true);
    assert(map__remove(map, "peach") == false);

    assert(map__get(map, "luigi") == NULL);

    map__destroy(map);
}
