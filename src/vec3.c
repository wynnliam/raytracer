// Liam Wynn, 5/21/2020, Raytracer

#include "vec3.h"

void vec3_add(const vec3* a, const vec3* b, vec3* out) {
    out->_e0 = a->_e0 + b->_e0;
    out->_e1 = a->_e1 + b->_e1;
    out->_e2 = a->_e2 + b->_e2;
}
