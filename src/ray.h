// Liam Wynn, 5/22/2020, Raytracer.

#include "vec3.h"

typedef struct {
    vec3 origin;
    vec3 direction;
} ray;

// Return the position of the ray at some moment in time.
// The formula for this is origin + direction * t.
extern void ray_at(const double t, const ray* ray, vec3* position);
