// Liam Wynn, 6/2/2020, Raytracer

#ifndef MATERIAL
#define MATERIAL

#include "ray.h"

typedef struct {
    int (*scatter_check)(const ray* in, const hit_record* record, const color3* attenuation, ray* scattered);
} material;

#endif // MATERIAL
