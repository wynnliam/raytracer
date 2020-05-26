// Liam Wynn, 5/26/2020, Raytracer

#ifndef THING
#define THING

#include "ray.h"

typedef struct {
    // Different objects will have this point
    // to different things.
    void* data;
    // TODO: Better arg list.
    // Returns 0 if no hit, and 1 if there
    // is a hit. All values t where t_min <= t <= t_max
    // are considered valid. data is a pointer
    // to whatever information is needed to determine
    // if a ray hit something. The resulting hit data
    // is put in result.
    int (*hit)(const ray* ray,
               const double t_min, const double t_max,
               void* data, hit_record* result);
} thing;

typedef struct {
    thing* things[THING_LIST_SIZE];
    int len;
} thing_list;

extern int add_thing_to_list(thing* to_add, thing_list* add_to);
extern int thing_list_hit(const ray* ray, const double t_min, const double t_max, void* data, hit_record* result);

#endif // THING
