// Liam Wynn, 5/25/2020, Raytracer

#include "ray.h"

typedef struct {
    vec3 center;
    double radius;
} sphere;

//static double hit_sphere_DEP(const vec3* center, const double radius, const ray* ray) {
int hit_sphere (const ray* ray, const double t_min, const double t_max, void* data, hit_record* result);
