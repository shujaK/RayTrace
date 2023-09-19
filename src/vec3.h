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

// 3d point class alias
using point3 = vec3;

// vector math
inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.vec[0] << ", " << v.vec[1] << ", " << v.vec[2];
}

inline vec3 operator+(const vec3& v1, const vec3& v2) {
    return vec3(v1.vec[0] + v2.vec[0], v1.vec[1] + v2.vec[1], v1.vec[2] + v2.vec[2]);
}

inline vec3 operator-(const vec3& v1, const vec3& v2) {
    return vec3(v1.vec[0] - v2.vec[0], v1.vec[1] - v2.vec[1], v1.vec[2] - v2.vec[2]);
}

inline vec3 operator*(const vec3& v1, const vec3& v2) {
    return vec3(v1.vec[0] * v2.vec[0], v1.vec[1] * v2.vec[1], v1.vec[2] * v2.vec[2]);
}

inline vec3 operator*(double c, const vec3 &v) {
    return vec3(c*v.vec[0], c*v.vec[1], c*v.vec[2]);
}

inline vec3 operator*(const vec3 &v, double c) {
    return c * v;
}

inline vec3 operator/(const vec3 &v, double c) {
    return (1/c) * v;
}

inline double dot(const vec3 &v1, const vec3 &v2) {
    return v1.vec[0] * v2.vec[0]
         + v1.vec[1] * v2.vec[1]
         + v1.vec[2] * v2.vec[2];
}

inline vec3 cross(const vec3& v1, const vec3& v2) {
    return vec3(v1.vec[1] * v2.vec[2] - v1.vec[2] * v2.vec[1],
                v1.vec[2] * v2.vec[0] - v1.vec[0] * v2.vec[2],
                v1.vec[0] * v2.vec[1] - v1.vec[1] * v2.vec[0]);
}

inline vec3 unit_vector(const vec3& v) {
    return v/v.length();
}