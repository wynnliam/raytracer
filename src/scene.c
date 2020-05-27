// Liam Wynn, 5/22/2020, Raytracer

#include "scene.h"

#include "ray.h"
#include "sphere.h"

#include <stdio.h>
#include <math.h>

#include "utils.h"

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

static camera cam;

// Elements in the scene
static thing my_sphere;
static sphere my_sphere_data;

static thing my_floor;
static sphere floor_sphere_data;

// Does linear interpolation (lerp) between
// a light blue and white.
static color3 ray_color(const ray* ray) {
    color3 result;
    double t;

    hit_record record;

    if(my_sphere.hit(ray, 0, 50, my_sphere.data, &record) || my_floor.hit(ray, 0, 100, my_floor.data, &record)) {
    //if(my_floor.hit(ray, 0, 100, my_floor.data, &record)) {
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
    cam.aspect_ratio = 16.0 / 9.0;
    cam.viewport_h = 2.0;
    cam.viewport_w = cam.aspect_ratio * cam.viewport_h;
    cam.focal_length = 1.0;

    cam.origin._X = 0; cam.origin._Y = 0; cam.origin._Z = 0;

    cam.vertical._X = 0; cam.vertical._Y = cam.viewport_h; cam.vertical._Z = 0.0;
    cam.horizontal._X = cam.viewport_w; cam.horizontal._Y = 0.0; cam.horizontal._Z = 0.0;

    cam.lower_left_corner = cam.origin;
    vec3 to_sub = cam.horizontal;

    vec3_scale(&to_sub, 0.5);
    vec3_sub(&cam.lower_left_corner, &to_sub, &cam.lower_left_corner);
    to_sub = cam.vertical;
    vec3_scale(&to_sub, 0.5);
    vec3_sub(&cam.lower_left_corner, &to_sub, &cam.lower_left_corner);
    to_sub._X = 0.0; to_sub._Y = 0.0; to_sub._Z = cam.focal_length;
    vec3_sub(&cam.lower_left_corner, &to_sub, &cam.lower_left_corner);

    // Initialize objects in scene
    my_sphere.data = (void*)&my_sphere_data;
    my_sphere.hit = &(hit_sphere);
    my_sphere_data.center._X = 0;
    my_sphere_data.center._Y = 0;
    my_sphere_data.center._Z = -1;
    my_sphere_data.radius = 0.5;

    my_floor.data = (void*)&floor_sphere_data;
    my_floor.hit = &(hit_sphere);
    floor_sphere_data.center._X = 0;
    floor_sphere_data.center._Y = -100.5;
    floor_sphere_data.center._Z = -1;
    floor_sphere_data.radius = 100;
}

// Renders scene to image file.
// TODO: Split rendering and file writing logic
void render_scene() {
    const int image_width = 384;
    const int image_height = (int)(image_width / (cam.aspect_ratio));

    fprintf(stderr, "Writing image file...\n");
    printf("P3\n%d %d 255\n", image_width, image_height);

    int row, col, s;
    int ir, ig, ib;

    // Defines the ray for the current row and col.
    ray curr_ray;
    color3 pixel_color;
    // Used to define the direction of curr_ray.
    // They are a percentage of the image width and height
    // respectively.
    double u, v;

    // TODO: Finish me!

    for(row = image_height - 1; row >= 0; row--) {
        fprintf(stderr, "Rows left: %d\n", row);
        for(col = 0; col < image_width; col++) {
            pixel_color._R = 0;
            pixel_color._G = 0;
            pixel_color._B = 0;

            for(s = 0; s < SAMPLES_PER_PIXEL; s++) {
                // Compute the direction of the next ray.
                // This is the vector going from the origin
                // to the pixel at [row, col] on the viewport.

                // Compute the position of the pixel on the screen
                u = (col + rand_double()) / (image_width - 1);
                v = (row + rand_double()) / (image_height - 1);

                ray_from_camera(&cam, u, v, &curr_ray);

                vec3 temp_color = ray_color(&curr_ray);
                vec3_add(&pixel_color, &temp_color, &pixel_color);
            }

            //pixel_color = ray_color(&curr_ray);
            vec3_scale(&pixel_color, 1.0 / SAMPLES_PER_PIXEL);

            ir = (int)(255 * pixel_color._R);
            ig = (int)(255 * pixel_color._G);
            ib = (int)(255 * pixel_color._B);

            printf("%d %d %d\n", ir, ig, ib);
        }
    }
    fprintf(stderr, "Done!\n");
}
