#pragma once

#include "hittable.h"
#include <memory>
#include <vector>

using std::shared_ptr;
using std::make_shared;

class hittable_list : public hittable {
    public:
        // base class
        std::vector<shared_ptr<hittable>> objects;

        // default and parameterized constructors
        hittable_list() {}
        hittable_list(shared_ptr<hittable> object) {add(object);}

        void add(shared_ptr<hittable> object){
            objects.push_back(object);
        }

        bool hit(const ray& r, interval ray_t, hit_record& rec) const override {
            hit_record temp_rec;
            bool hit_anything = false;
            auto closest = ray_t.max;

            for (const auto& object: objects) {
                if (object->hit(r, interval(ray_t.min, closest), temp_rec)) {
                    hit_anything = true;
                    closest = temp_rec.t;
                    rec = temp_rec;
                }
            }

            return hit_anything;
        }
};