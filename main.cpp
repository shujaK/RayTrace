#include <iostream>


int main() {
    // Dimensions
    int img_width = 256;
    int img_height = 256;

    // Render
    std::cout << "P3\n" << img_width << " " << img_height << "\n255" << std::endl;

    for (int y = 0; y < img_height; y++) {
        std::clog << "\rScanlines remaining: " << (img_height - y) << ' ' << std::flush;
        for (int x = 0; x < img_width; x++) {
            auto r = double(x) / (img_width - 1);
            auto g = double(y) / (img_height - 1);
            auto b = 0;

            int ir = int(r * 255.99);
            int ig = int(g * 255.99);
            int ib = int(b * 255.99);

            std::cout << ir << ' ' << ig << ' ' << ib << std::endl;
            
        }
    }
    std::clog << "\rDone.                 \n";
}