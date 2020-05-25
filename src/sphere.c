// Liam Wynn, 5/25/2020, Raytracer

#include "sphere.h"

#include <math.h>

int hit_sphere (const ray* ray, const double t_min, const double t_max, void* data, hit_record* result) {
    vec3 sphere_center, cent_to_origin;
    double sphere_radius;
    double a, b, c;
    double discriminant, root, t;

    sphere_radius = ((sphere*)data)->radius;
    sphere_center = ((sphere*)data)->center;

    vec3_sub(&(ray->origin), &sphere_center, &cent_to_origin);
    //a = vec3_dot(&(ray->direction), &(ray->direction));
    a = vec3_length_squared(&(ray->direction));
    b = vec3_dot(&cent_to_origin, &(ray->direction));
    c = vec3_length_squared(&cent_to_origin) - sphere_radius * sphere_radius;

    discriminant = b * b - a * c;

    if(discriminant < 0) {
        return 0;
    } else {
        root = sqrt(discriminant);
        t = (-b - root) / a;
        if(t < t_max && t > t_min) {
            result->t = t;
            ray_at(result->t, ray, &result->point);

            vec3 normal;
            vec3_sub(&(result->point), &sphere_center, &normal);
            vec3_unit(&normal, &(result->normal));

            return 1;
        }

        t = (-b + root) / a;
        if(t < t_max && t > t_min) {
            result->t = t;
            ray_at(result->t, ray, &result->point);

            vec3 normal;
            vec3_sub(&(result->point), &sphere_center, &normal);
            vec3_unit(&normal, &(result->normal));

            return 1;
        }
        // Return the value t such that
        //(P(t) - C) * (P(t) - C) = r^2
        // P is the ray, C is the center of the sphere,
        // and r is the sphere's radius.
        /*result->t = (-b - sqrt(discriminant)) / a;
        ray_at(result->t, ray, &(result->point));

        // Compute the normal
        vec3 normal;
        vec3_sub(&(result->point), &sphere_center, &normal);
        vec3_unit(&normal, &(result->normal));

        result->front_facing = vec3_dot(&(ray->direction), &(result->normal)) < 0.0;
        if(!result->front_facing)
            vec3_negate(&(result->normal));*/

        //return 1;
    }

    return 0;
}
