#pragma once

//#include "stdafx.h"
using std::cout;

//Not the best way to define a constant pi
// evaluated at compile time line #define
constexpr double pi = 3.14159263;

//Not recommended for C++11 or later:
//macro defined conversion:
#define radians(deg) ((deg) * pi /180 )

//this is the preferred method for C++11 or later:
//compile-time type-checked constexpr for degreees to radians conversion:
constexpr double deg2rad(const double d) {
    return d * pi / 180;
}
