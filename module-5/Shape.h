#pragma once

#include <string>

namespace hw5 {}

namespace hw5::Shapes {
    enum class Shape {
        Unkown = -1,
        CIRCLE,
        SQUARE,
        TRIANGLE
    };

    std::string toString(Shape sh);
    Shape toShape(const std::string& sh);
}