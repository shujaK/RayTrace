#pragma once

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
    public:
        double vec[3];

        vec3() : vec{0, 0, 0} {}
        vec3(double x, double y, double z) : vec{x, y, z} {}

        double x() const {return vec[0];}
        double y() const {return vec[1];}
        double z() const {return vec[2];}

        vec3 operator-() const {return vec3(-vec[0], -vec[1], -vec[2]);}
        double operator[](int i) const {return vec[i];}
        double& operator[](int i) {return vec[i];}

        vec3& operator+=(const vec3 &v) {
            vec[0] += v.vec[0];
            vec[1] += v.vec[1];
            vec[2] += v.vec[2];

            return *this;
        }
        
        vec3& operator*=(double c) {
            vec[0] *= c;
            vec[1] *= c;
            vec[2] *= c;

            return *this;
        }

        vec3& operator/=(double c) {
            return *this *= 1/c;
        }

        double length_squared() const {
            return vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2];
        }

        double length() const {
            return sqrt(length_squared());
        }

};

