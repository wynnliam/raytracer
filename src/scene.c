// Liam Wynn, 5/22/2020, Raytracer

#include "scene.h"

#include "ray.h"
#include "sphere.h"

#include <stdio.h>
#include "math.h"

/*
    NOTES ABOUT Coordinate system.

    x axis increases to the right.
    y axis increases upwards.
    z axis increases to the left.

    The viewport will be centered at (0, 0, -1)
    and the camera at (0, 0, 0). So as you increase the z
    value, you zoom out because you increase away from the viewport.

    So the camera is positioned at (0, 0, 0) and faces the viewport
    which is centered at (0, 0, -1).
*/

// Image width / image height
#define ASPECT_RATIO 16.0 / 9.0

#define VIEWPORT_H      2
#define VIEWPORT_W      ASPECT_RATIO * VIEWPORT_H

// Distance from the camera position
// to the viewport in space.
#define FOCAL_LENGTH    1

static vec3 cam_pos;
static vec3 vertical, horizontal;
static vec3 viewport_lower_left_corner;

// Elements in the scene
static thing my_sphere;
static sphere my_sphere_data;

// Does linear interpolation (lerp) between
// a light blue and white.
static color3 ray_color(const ray* ray) {
    color3 result;
    double t;

    hit_record record;

    if(my_sphere.hit(ray, 0, 0, my_sphere.data, &record)) {
        result._R = record.normal._X + 1;
        result._G = record.normal._Y + 1;
        result._B = record.normal._Z + 1;
        vec3_scale(&result, 0.5);
        return result;
    }

    vec3 unit_direction = ray->direction;
    vec3_unit(&unit_direction, &unit_direction);
    t = 0.5 * (unit_direction._Y + 1.0);

    color3 white, a;
    white._R = 1.0; white._G = 1.0; white._B = 1.0;
    vec3_scale(&white, 1.0 - t);

    a._R = 0.5; a._G = 0.7; a._B = 1.0;
    vec3_scale(&a, t);

    vec3_add(&white, &a, &result);

    return result;
}

void initialize_renderer() {
    cam_pos._X = 0.0; cam_pos._Y = 0.0; cam_pos._Z = 0.0;

    vertical._X = 0.0; vertical._Y = VIEWPORT_H; vertical._Z = 0.0;
    horizontal._X = VIEWPORT_W; horizontal._Y = 0.0; horizontal._Z = 0.0;

    viewport_lower_left_corner = cam_pos;
    vec3 to_sub = horizontal;
    vec3_scale(&to_sub, 0.5);
    vec3_sub(&viewport_lower_left_corner, &to_sub, &viewport_lower_left_corner);

    to_sub = vertical;
    vec3_scale(&to_sub, 0.5);
    vec3_sub(&viewport_lower_left_corner, &to_sub, &viewport_lower_left_corner);

    to_sub._X = 0.0; to_sub._Y = 0.0; to_sub._Z = FOCAL_LENGTH;
    vec3_sub(&viewport_lower_left_corner, &to_sub, &viewport_lower_left_corner);

    // Initialize objects in scene
    my_sphere.data = (void*)&my_sphere_data;
    my_sphere.hit = &(hit_sphere);
    my_sphere_data.center._X = 0;
    my_sphere_data.center._Y = 0;
    my_sphere_data.center._Z = -1;
    my_sphere_data.radius = 0.5;
}

// Renders scene to image file.
// TODO: Split rendering and file writing logic
void render_scene() {
    const int image_width = 384;
    const int image_height = (int)(image_width / (ASPECT_RATIO));

    fprintf(stderr, "Writing image file...\n");
    printf("P3\n%d %d 255\n", image_width, image_height);

    int row, col;
    int ir, ig, ib;

    // Defines the ray for the current row and col.
    ray curr_ray;
    color3 pixel_color;
    // Used to define the direction of curr_ray.
    // They are a percentage of the image width and height
    // respectively.
    double u, v;
    // What we add to lower_left_corner to get curr_ray's
    // direction.
    vec3 h_offset, v_offset;

    // All rays begin at the camera position.
    curr_ray.origin = cam_pos;

    for(row = image_height - 1; row >= 0; row--) {
        fprintf(stderr, "Rows left: %d\n", row);
        for(col = 0; col < image_width; col++) {
            // Compute the direction of the next ray.
            // This is the vector going from the origin
            // to the pixel at [row, col] on the viewport.

            // Compute the position of the pixel on the screen
            u = (double)col / (image_width - 1);
            v = (double)row / (image_height - 1);
            h_offset = horizontal; vec3_scale(&h_offset, u);
            v_offset = vertical; vec3_scale(&v_offset, v);

            // ray direction = pixel postion - camera position.
            // We don't turn this into a unit vector.
            curr_ray.direction = viewport_lower_left_corner;
            vec3_add(&curr_ray.direction, &h_offset, &curr_ray.direction);
            vec3_add(&curr_ray.direction, &v_offset, &curr_ray.direction);
            vec3_sub(&curr_ray.direction, &cam_pos, &curr_ray.direction);

            pixel_color = ray_color(&curr_ray);

            ir = (int)(255 * pixel_color._R);
            ig = (int)(255 * pixel_color._G);
            ib = (int)(255 * pixel_color._B);

            printf("%d %d %d\n", ir, ig, ib);
        }
    }
    fprintf(stderr, "Done!\n");
}
