#pragma once

#include "vec3.h"
#include <iostream>

using colour = vec3;

void write_colour(std::ostream &out, colour pixel_colour) {
    out << int(255.99 * pixel_colour.x()) << ' '
        << int(255.99 * pixel_colour.y()) << ' '
        << int(255.99 * pixel_colour.z()) << ' ' << std::endl;
}