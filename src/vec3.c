// Liam Wynn, 5/21/2020, Raytracer

#include "vec3.h"

#include <math.h>

void vec3_negate(vec3* vec) {
    vec->_e0 *= -1;
    vec->_e1 *= -1;
    vec->_e2 *= -1;
}

void vec3_add(const vec3* a, const vec3* b, vec3* out) {
    out->_e0 = a->_e0 + b->_e0;
    out->_e1 = a->_e1 + b->_e1;
    out->_e2 = a->_e2 + b->_e2;
}

void vec3_sub(const vec3* a, const vec3* b, vec3* out) {
    out->_e0 = a->_e0 - b->_e0;
    out->_e1 = a->_e1 - b->_e1;
    out->_e2 = a->_e2 - b->_e2;
}

void vec3_scale(vec3* to_scale, const double scale_by) {
    to_scale->_e0 *= scale_by;
    to_scale->_e1 *= scale_by;
    to_scale->_e2 *= scale_by;
}

double vec3_length(const vec3* vec) {
    return sqrt(vec3_length_squared(vec));
}

double vec3_length_squared(const vec3* vec) {
    double e0_sqrd, e1_sqrd, e2_sqrd;

    e0_sqrd = vec->_e0 * vec->_e0;
    e1_sqrd = vec->_e1 * vec->_e1;
    e2_sqrd = vec->_e2 * vec->_e2;

    return e0_sqrd + e1_sqrd + e2_sqrd;
}

