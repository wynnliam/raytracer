// Liam Wynn, 5/26/2020, Raytracer

#include "camera.h"

void ray_from_camera(const camera* cam, const double u, const double v, ray* result) {
    result->origin = cam->origin;

    vec3 x_dir, y_dir;
    x_dir = cam->horizontal;
    vec3_scale(&x_dir, u);
    y_dir = cam->vertical;
    vec3_scale(&y_dir, v);

    vec3_add(&(cam->lower_left_corner), &x_dir, &(result->direction));
    vec3_add(&(result->direction), &y_dir, &(result->direction));
    vec3_sub(&(result->direction), &(cam->origin), &(result->direction));
    /*vec3_add(&(cam->lower_left_corner), &x_dir, &(ray->direction));
    vec3_add(&(ray->direction), &y_dir, &(ray->direction));
    vec3_sub(&(ray->direction), &(cam->origin), &(ray->direction));*/
}
