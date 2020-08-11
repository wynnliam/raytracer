// Liam Wynn, 6/2/2020, Raytracer

#include "material.h"

int lambert_scatter(const ray* in, const hit_record* record, color3* attenuation, void* data, ray* scattered) {

    vec3 scattered_dir;
    vec3 rand_vec;

    vec3_rand_hemisphere(&rand_vec, &(record->normal));
    vec3_add(&(record->normal), &rand_vec, &scattered_dir);

    scattered->origin = record->point;
    scattered->direction = scattered_dir;

    *attenuation = ((lambert_data*)data)->albedo;

    return 1;
}

int metal_scatter(const ray* in, const hit_record* record, color3* attenuation, void* data, ray* scattered) {
    metal_data* accessible = (metal_data*)data;

    vec3 reflect;
    vec3 in_dir_unit;
    vec3 fuzz;

    vec3_unit(&(in->direction), &in_dir_unit);
    vec3_reflect(&in_dir_unit, &(record->normal), &reflect);

    vec3_rand_in_unit_sphere(&fuzz);
    vec3_scale(&fuzz, accessible->fuzz_factor);

    scattered->origin = record->point;
    vec3_add(&fuzz, &reflect, &(scattered->direction));
    *attenuation = accessible->albedo;

    return vec3_dot(&reflect, &(record->normal)) > 0.0;
}

int dialectric_scatter(const ray* in, const hit_record* record, color3* attenuation, void* data, ray* scattered) {
    attenuation->_R = 1.0;
    attenuation->_G = 1.0;
    attenuation->_B = 1.0;

    return 1;
}
