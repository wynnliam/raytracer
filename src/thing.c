// Liam Wynn, 5/26/2020, Raytracer

#include "thing.h"

int add_thing_to_list(thing* to_add, thing_list* add_to) {
    if(add_to->len >= THING_LIST_SIZE)
        return 0;

    add_to->things[add_to->len] = to_add;
    add_to->len += 1;

    return 1;
}

int thing_list_hit(const ray* ray, const double t_min, const double t_max, void* data, hit_record* result) {
    return 0;
}
