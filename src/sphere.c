// Liam Wynn, 5/25/2020, Raytracer

#include "sphere.h"

#include <math.h>

int hit_sphere (const ray* ray, const double t_min, const double t_max, void* data, hit_record* result) {
    vec3 sphere_center, cent_to_origin;
    double sphere_radius;
    double a, b, c;
    double discriminant;

    sphere_radius = ((sphere*)data)->radius;
    sphere_center = ((sphere*)data)->center;

    vec3_sub(&(ray->origin), &sphere_center, &cent_to_origin);
    a = vec3_dot(&(ray->direction), &(ray->direction));
    b = 2 * vec3_dot(&cent_to_origin, &(ray->direction));
    c = vec3_dot(&cent_to_origin, &cent_to_origin) - sphere_radius * sphere_radius;

    discriminant = b * b - 4 * a * c;

    if(discriminant < 0) {
        return 0;
    } else {
        // Return the value t such that
        //(P(t) - C) * (P(t) - C) = r^2
        // P is the ray, C is the center of the sphere,
        // and r is the sphere's radius.
        result->t = (-b -sqrt(discriminant)) / (2.0 * a);
        ray_at(result->t, ray, &(result->point));

        // Compute the normal
        vec3 normal;
        vec3_sub(&(result->point), &sphere_center, &normal);
        vec3_unit(&normal, &(result->normal));

        result->front_facing = vec3_dot(&(ray->direction), &(result->normal)) < 0.0;
        if(!result->front_facing)
            vec3_negate(&(result->normal));

        return 1;
    }
}
