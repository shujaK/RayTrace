#include <iostream>
#include "vec3.h"
#include "colour.h"

int main() {
    // Dimensions
    int img_width = 256;
    int img_height = 256;

    // Render
    std::cout << "P3\n" << img_width << " " << img_height << "\n255" << std::endl;

    for (int y = 0; y < img_height; y++) {
        std::clog << "\rScanlines remaining: " << (img_height - y) << ' ' << std::flush;
        for (int x = 0; x < img_width; x++) {
            colour col(double(x) / (img_width - 1), 
                       double(y) / (img_height - 1), 
                       0);

            write_colour(std::cout, col);
        }
    }
    std::clog << "\rDone.                 \n";
}