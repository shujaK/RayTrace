#pragma once

#include "vec3.h"

// parametric line (ray)
class ray{
    public:
        // default and parameterized constructors
        ray() {}
        ray(const point3& origin, const vec3& direction) : m_origin(origin), m_direction(direction) {}

        // data getters
        point3 origin() const {return m_origin;}
        vec3 direction() const {return m_direction;}

        // calculate point along the line
        point3 at(double t) const {
            point3 pt = m_origin;
            pt += t * m_direction;

            return pt;
        }

    private:
        // data
        point3 m_origin;
        vec3 m_direction;
};