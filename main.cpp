#include <iostream>

#include "src/main_header.h"
#include "src/hittable_list.h"
#include "src/camera.h"

int main() {
    // world objects
    hittable_list world;
    world.add(make_shared<sphere>(point3(0,0,-1), 0.5));
    world.add(make_shared<sphere>(point3(0,-100.5,-1), 100));

    camera cam;

    cam.aspect_ratio = 16.0/9.0;
    cam.image_width = 400;

    cam.render(world);

}