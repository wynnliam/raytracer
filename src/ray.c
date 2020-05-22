// Liam Wynn, 5/22/2020, Raytracer

#include "ray.h"

void ray_at(const double t, const ray* ray, vec3* position) {
    vec3 scaled_dir = ray->direction;

    vec3_scale(&scaled_dir, t);
    vec3_add(&(ray->origin), &scaled_dir, position);
}
