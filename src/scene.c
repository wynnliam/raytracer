// Liam Wynn, 5/22/2020, Raytracer

#include "scene.h"

#include "vec3.h"

#include <stdio.h>

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
}

// Renders scene to image file.
// TODO: Split rendering and file writing logic
void render_scene() {
    const int image_width = 384;
    const int image_height = (int)(image_width / (ASPECT_RATIO));

    fprintf(stderr, "Writing image file...\n");
    printf("P3\n%d %d 255\n", image_width, image_height);

    int row, col;
    float r, g, b;
    int ir, ig, ib;
    for(row = image_height - 1; row >= 0; row--) {
        fprintf(stderr, "Rows left: %d\n", row);
        for(col = 0; col < image_width; col++) {
            r = (float)col / (image_width - 1);
            g = (float)row / (image_height - 1);
            b = 0.25f;

            ir = (int)(255 * r);
            ig = (int)(255 * g);
            ib = (int)(255 * b);

            printf("%d %d %d\n", ir, ig, ib);
        }
    }
    fprintf(stderr, "Done!\n");
}
