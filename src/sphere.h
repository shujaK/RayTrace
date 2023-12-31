#pragma once

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
    public:
        // constructor
        sphere(point3 center, double radius) : m_center(center), m_radius(radius) {}

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            // determine t value to hit sphere through quadratic formula
            vec3 o_c = r.origin() - m_center;
            auto a = r.direction().length_squared(); 
            auto half_b = dot(o_c, r.direction());
            auto c = o_c.length_squared() - m_radius*m_radius;
            auto discriminant = (half_b*half_b) - (a*c);

            if (discriminant < 0) {return false;}
            auto sqrtd = sqrt(discriminant);

            // find closest root thats within range
            auto root = (-half_b - sqrtd) / a;
            if (!ray_t.surrounds(root)) {
                root = (-half_b + sqrtd) / a;
                if (!ray_t.surrounds(root))
                    return false;
            }

            // record the hit
            rec.t = root;
            rec.p = r.at(rec.t);
            vec3 outward_normal = (rec.p - m_center) / m_radius;
            rec.set_face_normal(r, outward_normal);

            return true;
        }

    private:
        point3 m_center;
        double m_radius;
};