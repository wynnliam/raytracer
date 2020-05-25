// Liam Wynn, 5/22/2020, Raytracer.

#include "vec3.h"

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

// Return the position of the ray at some moment in time.
// The formula for this is origin + direction * t.
extern void ray_at(const double t, const ray* ray, vec3* position);
