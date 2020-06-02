// Liam Wynn, 6/2/2020, Raytracer

#include "material.h"

int lambert_scatter(const ray* in, const hit_record* record, color3* attenuation, void* data, ray* scattered) {
    vec3 scattered_dir;
    vec3 rand_vec;

    vec3_rand(&rand_vec);
    vec3_add(&(record->normal), &rand_vec, &scattered_dir);

    scattered->origin = record->point;
    scattered->direction = scattered_dir;

    *attenuation = ((lambert_data*)data)->albedo;

    return 1;
}
