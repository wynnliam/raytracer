// Liam Wynn, 5/21/2020, Raytracer

#include <stdio.h>

extern void render_scene();

int main() {
    fprintf(stderr, "Welcome to my raytracer!\n");

    render_scene();

    return 0;
}
