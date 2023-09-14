#pragma once

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3 {
    public:
        // use a double array as the underlying data structure
        double vec[3];

        // default and parameterized constructors
        vec3() : vec{0, 0, 0} {}
        vec3(double x, double y, double z) : vec{x, y, z} {}

        // component vector getters
        double x() const {return vec[0];}
        double y() const {return vec[1];}
        double z() const {return vec[2];}

        // negative vector and vector indexing 
        vec3 operator-() const {return vec3(-vec[0], -vec[1], -vec[2]);}
        double operator[](int i) const {return vec[i];}
        double& operator[](int i) {return vec[i];}

        // vector addition
        vec3& operator+=(const vec3 &v) {
            vec[0] += v.vec[0];
            vec[1] += v.vec[1];
            vec[2] += v.vec[2];

            return *this;
        }
        
        // scalar multiplication
        vec3& operator*=(double c) {
            vec[0] *= c;
            vec[1] *= c;
            vec[2] *= c;

            return *this;
        }

        //scalar division
        vec3& operator/=(double c) {
            return *this *= 1/c;
        }

        // vector length helper
        double length_squared() const {
            return vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2];
        }

        // vector length getter 
        double length() const {
            return sqrt(length_squared());
        }

};

using point3 = vec3;

