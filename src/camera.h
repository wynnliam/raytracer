// Liam Wynn, 5/26/2020, Raytracer.

#ifndef CAMERA
#define CAMERA

#include "ray.h"

typedef struct {
    vec3 origin;
    vec3 horizontal, vertical;
    vec3 lower_left_corner;
    double aspect_ratio;
    double viewport_w, viewport_h;
    double focal_length;
} camera;

extern void ray_from_camera(const camera* cam, const double u, const double v, ray* result);

#endif // CAMERA
