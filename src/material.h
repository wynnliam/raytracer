// Liam Wynn, 6/2/2020, Raytracer

#ifndef MATERIAL
#define MATERIAL

#include "ray.h"

typedef struct {
    // Use this to store whatever information you want
    // when doing a computation.
    void* data;
    int (*scatter_check)(const ray* in, const hit_record* record, const color3* attenuation, void* data, ray* scattered);
} material;

#endif // MATERIAL
