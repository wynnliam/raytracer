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
    thing_list* list = (thing_list*)data;
    hit_record temp_record;
    int hit_anything = 0;
    double t_closest = t_max;
    int i;

    for(i = 0; i < list->len; i++) {
        void* thing_data = list->things[i]->data;
        if(list->things[i]->hit(ray, t_min, t_closest, thing_data, &temp_record)) {
            hit_anything = 1;
            t_closest = temp_record.t;
            *result = temp_record;
        }
    }

    return hit_anything;
}
