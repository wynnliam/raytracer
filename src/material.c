// Liam Wynn, 6/2/2020, Raytracer

#include "material.h"
#include "utils.h"
#include <math.h>

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

double schlick(const double cos, const double ref_index) {
    double r0 = (1 - ref_index) / (1 + ref_index);
    r0 = r0 * r0;
    return r0 + (1-r0) * pow((1 - cos), 5);
}

int dialectric_scatter(const ray* in, const hit_record* record, color3* attenuation, void* data, ray* scattered) {
    dialectric_data* accessible = (dialectric_data*)data;

    attenuation->_R = 1.0;
    attenuation->_G = 1.0;
    attenuation->_B = 1.0;

    double etai_over_etat = record->front_facing ? (1.0 / accessible->refract_index) : accessible->refract_index;

    vec3 unit_dir;
    vec3_unit(&(in->direction), &unit_dir);

    vec3 unit_dir_negative = unit_dir;
    vec3_negate(&unit_dir_negative);

    double cos_theta = fmin(vec3_dot(&unit_dir_negative, &record->normal), 1.0);
    double sin_theta = sqrt(1.0 - cos_theta * cos_theta);

    if(etai_over_etat * sin_theta > 1.0) {
        vec3 reflect;
        vec3_reflect(&unit_dir, &record->normal, &reflect);
        scattered->origin = record->point;
        scattered->direction = reflect;

        return 1;
    }

    double reflect_prob = schlick(cos_theta, etai_over_etat);
    if(rand_double() < reflect_prob) {
        vec3 reflect;
        vec3_reflect(&unit_dir, &record->normal, &reflect);
        scattered->origin = record->point;
        scattered->direction = reflect;

        return 1;
    }

    vec3 refract;
    vec3_refract(&unit_dir, &(record->normal), etai_over_etat, &refract);

    scattered->direction = refract;
    scattered->origin = record->point;

    return 1;
}
