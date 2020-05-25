// Liam Wynn, 5/22/2020, Raytracer.

#include "vec3.h"

#ifndef RAY
#define RAY

typedef struct {
    vec3 origin;
    vec3 direction;
} ray;

typedef struct {
    // The point on the object where the ray hit.
    vec3 point;
    // The normal of the surface where the ray hit.
    vec3 normal;
    // If you have the ray that hit the object, you can use
    // it plus this to derive point.
    double t;
} hit_record;

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

// Return the position of the ray at some moment in time.
// The formula for this is origin + direction * t.
extern void ray_at(const double t, const ray* ray, vec3* position);

#endif // RAY
