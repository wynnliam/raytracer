// Liam Wynn, 5/21/2020, Raytracer

#ifndef VECTOR_3
#define VECTOR_3

// You can optionally use these when referencing
// a color. I mean, you don't have to, but I think
// it makes readability easier.
#define _R  _e0
#define _G  _e1
#define _B  _e2

// If you prefer "x, y, z" over "e0, e1, e2"
#define _X  _e0
#define _Y  _e1
#define _Z  _e2

typedef struct {
    double _e0, _e1, _e2;
} vec3;

typedef vec3 color3;

// Vector with x, y, z randomly between 0 and 1.
extern void vec3_rand(vec3* result);
// Vector with x, y, z randomly between min and max.
extern void vec3_rand_range(const double min_val, const double max_val, vec3* result);
// Random vector in unit sphere using the "rejection method": choose random unit vector
// over and over again until it's inside the unit sphere.
extern void vec3_rand_in_unit_sphere(vec3* result);
// Chooses a random unit vector that is on the unit sphere and not in it.
extern void vec3_rand_unit(vec3* result);
extern void vec3_rand_hemisphere(vec3* result, const vec3* norm);

extern void vec3_negate(vec3* vec);

extern void vec3_add(const vec3* a, const vec3* b, vec3* out);
extern void vec3_sub(const vec3* a, const vec3* b, vec3* out);
extern void vec3_mul(const vec3* a, const vec3* b, vec3* out);

extern void vec3_scale(vec3* to_scale, const double scale_by);

extern double vec3_length(const vec3* vec);
extern double vec3_length_squared(const vec3* vec);
extern void vec3_unit(const vec3* vec, vec3* out);

extern double vec3_dot(const vec3* a, const vec3* b);
extern void vec3_cross(const vec3* a, const vec3* b, vec3* out);

#endif // VECTOR_3

