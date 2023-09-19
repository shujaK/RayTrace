#pragma once

#include "ray.h"

class hit_record {
    public:
        point3 p;
        vec3 normal;
        double t;
        bool front_face;

        // flip normal based on incident ray assuming outward_normal is of unit length
        void set_face_normal(const ray& r, const vec3& outward_normal) {
            front_face = dot(r.direction(), outward_normal) < 0;
            normal = front_face ? outward_normal : -outward_normal;
        }
};

class hittable {
    public:
        virtual ~hittable() = default;

        virtual bool hit(const ray& r, double r_tmin, double r_tmax, hit_record& rec) const = 0;
};