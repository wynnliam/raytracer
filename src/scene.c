// Liam Wynn, 5/22/2020, Raytracer

#include "scene.h"

#include <stdio.h>

/*
    NOTES ABOUT Coordinate system.

    x axis increases to the right.
    y axis increases upwards.
    z axis increases to the left.

    The viewport will be centered at (0, 0, -1)
    and the camera at (0, 0, 0). So as you increase the z
    value, you zoom out because you increase away from the viewport
*/

// Image width / image height
#define ASPECT_RATIO 16.0 / 9.0

#define VIEWPORT_H      2
#define VIEWPORT_W      ASPECT_RATIO * VIEWPORT_H

// Distance from the camera position
// to the viewport in space.
#define FOCAL_LENGTH    1

// Renders scene to image file.
// TODO: Split rendering and file writing logic
void render_scene() {
    const int image_width = 256;
    const int image_height = 256;

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
