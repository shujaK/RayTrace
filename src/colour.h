#pragma once

#include "vec3.h"
#include <iostream>

using colour = vec3;

// print pixel info to output stream
void write_colour(std::ostream &out, colour pixel_colour) {
    out << static_cast<int>(255.99 * pixel_colour.x()) << ' '
        << static_cast<int>(255.99 * pixel_colour.y()) << ' '
        << static_cast<int>(255.99 * pixel_colour.z()) << ' ' << std::endl;
}