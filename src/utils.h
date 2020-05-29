// Liam Wynn, 5/26/2020, Raytracer

#ifndef UTILITIES
#define UTILITIES

#define PI  3.1415926535897932385

// Random value t where 0 <= t < 1
extern double rand_double();
// Random value t where min <= t < max
extern double rand_double_range(const double min_val,
                                const double max_val);

#endif // UTILITIES
