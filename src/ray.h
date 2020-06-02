// Liam Wynn, 5/22/2020, Raytracer.

#include "vec3.h"

#ifndef RAY
#define RAY

#define THING_LIST_SIZE 100

struct material;

typedef struct {
    vec3 origin;
    vec3 direction;
} ray;

typedef struct {
    // Material of the object we hit
    struct material* mat;
    // The point on the object where the ray hit.
    vec3 point;
    // The normal of the surface where the ray hit.
    vec3 normal;
    // If you have the ray that hit the object, you can use
    // it plus this to derive point.
    double t;
    // If not 0, the ray hit the object from the outside. Otherwise,
    // we are inside the object
    int front_facing;
} hit_record;

// Return the position of the ray at some moment in time.
// The formula for this is origin + direction * t.
extern void ray_at(const double t, const ray* ray, vec3* position);

#endif // RAY
