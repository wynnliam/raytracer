// Liam Wynn, 5/22/2020, Raytracer

#include "scene.h"

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
