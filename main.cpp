#include <iostream>
#include "vec3.h"
#include "colour.h"
#include "ray.h"

double hit_sphere(const point3& center, double radius, const ray& r) {\
    // determine t value to hit sphere through quadratic formula
    vec3 o_c = r.origin() - center;
    auto a = r.direction().length_squared(); 
    auto half_b = dot(o_c, r.direction());
    auto c = o_c.length_squared() - radius*radius;
    auto discriminant = (half_b*half_b) - (a*c);
    if (discriminant < 0) {
        return -1.0;
    } else {
        return (-half_b - sqrt(discriminant)) / (2.0*a);
    }
}

colour ray_colour(const ray& r) {
    point3 sphere_center(0, 0, -1);
    auto t = hit_sphere(sphere_center, 0.5, r);
    if (t > 0) {
        auto intersection = r.at(t); // point on surface
        vec3 normal = unit_vector(intersection - sphere_center); // normal = centre to point
        return colour(normal + vec3(1, 1, 1)) * 0.5; // normalize vector
    }

    auto unit_dir = unit_vector(r.direction());
    auto lerp_val = 0.5 * (unit_dir.y() + 1.0);
    auto start = colour(1.0, 1.0, 1.0);
    auto end = colour(0.5, 0.7, 1.0);
    return ((1.0-lerp_val)*start) + (lerp_val*end);
}

int main() {
    // image dimensions
    auto aspect_ratio = 16.0/9.0; // this ratio is ideal, casting to int (rounding) will change it slightly
    int img_width = 400;
    int img_height = static_cast<int> (img_width / aspect_ratio);
    img_height = (img_height < 1) ? 1 : img_height; // ensure img height is at least 1
    auto real_aspect_ratio = static_cast<double> (img_width) / img_height; // this is the real aspect ratio after rounding

    // viewport / camera dimensions
    auto focal_length = 1.0;
    auto viewport_height = 2.0;
    auto viewport_width = viewport_height * real_aspect_ratio;
    auto camera_center = point3(0, 0, 0);

    // viewport vectors
    auto viewport_u = vec3(viewport_width, 0, 0);
    auto viewport_v = vec3(0, -viewport_height, 0);

    // delta vectors
    auto delta_u = viewport_u / img_width;
    auto delta_v = viewport_v / img_height;

    // location of upper left pixel
    auto viewport_upper_left = camera_center - vec3(0, 0, focal_length) - 0.5*viewport_u - 0.5*viewport_v;
    auto pixel00_loc = viewport_upper_left + 0.5*delta_u + 0.5*delta_v;

    // Render
    std::cout << "P3\n" << img_width << " " << img_height << "\n255" << std::endl;

    for (int y = 0; y < img_height; y++) {
        std::clog << "\rScanlines remaining: " << (img_height - y) << ' ' << std::flush;
        for (int x = 0; x < img_width; x++) {
            auto pixel_center = pixel00_loc + (y * delta_v) + (x * delta_u); // get real pixel locations through img pixel coordinates
            auto ray_direction = pixel_center - camera_center; // ray direction from "eye" to viewport
            ray r(camera_center, ray_direction);

            auto col = ray_colour(r);

            write_colour(std::cout, col);
        }
    }
    std::clog << "\rDone.                 \n";
}