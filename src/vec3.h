// Liam Wynn, 5/21/2020, Raytracer

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

extern void vec3_negate(vec3* vec);
extern void vec3_add(const vec3* a, const vec3* b, vec3* out);
extern void vec3_sub(const vec3* a, const vec3* b, vec3* out);
extern void vec3_scale(vec3* to_scale, const double scale_by);
extern double vec3_length(const vec3* vec);
extern double vec3_length_squared(const vec3* vec);

