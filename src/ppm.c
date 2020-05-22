// Liam Wynn, 5/21/2020, Raytracer

#include <stdio.h>

void write_ppm() {
    const int image_width = 256;
    const int image_height = 256;

    printf("P3\n%d %d 255\n", image_width, image_height);

    int row, col;
    float r, g, b;
    int ir, ig, ib;
    for(row = image_height - 1; row >= 0; row--) {
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
}
