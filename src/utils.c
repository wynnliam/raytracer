// Liam Wynn, 5/26/2020, Raytracer

#include "utils.h"

#include <stdlib.h>

double rand_double() {
    return rand() / (RAND_MAX + 1.0);
}

// Random value t where min <= t < max
double rand_double_range(const double min_val,
                         const double max_val)
{
    return min_val + (max_val - min_val) * rand_double();
}
