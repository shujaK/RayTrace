#pragma once
#include "main_header.h"

class interval {
    public:
        double min, max;

        interval() : min(+infinity), max(-infinity) {}
        interval(double _min, double _max) : min(_min), max(_max) {}

        bool contains(double val) const {
            return (min <= val && val <= max);
        }

        bool surrounds(double val) const {
            return (min < val && val < max);
        }

        static const interval empty, universe;
};

const static interval empty(+infinity, -infinity);
const static interval universe(-infinity, +infinity);