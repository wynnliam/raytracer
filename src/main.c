// Liam Wynn, 5/21/2020, Raytracer

#include <stdio.h>

#include "scene.h"

int main() {
    fprintf(stderr, "Welcome to my raytracer!\n");

    initialize_renderer();
    render_scene();

    return 0;
}
