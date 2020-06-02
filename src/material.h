// Liam Wynn, 6/2/2020, Raytracer

#ifndef MATERIAL
#define MATERIAL

#include "ray.h"

struct material {
    // Use this to store whatever information you want
    // when doing a computation.
    void* data;
    int (*scatter_check)(const ray* in, const hit_record* record, color3* attenuation, void* data, ray* scattered);
};

typedef struct {
    color3 albedo;
} lambert_data;

int lambert_scatter(const ray* in, const hit_record* record, color3* attenuation, void* data, ray* scattered);

#endif // MATERIAL
