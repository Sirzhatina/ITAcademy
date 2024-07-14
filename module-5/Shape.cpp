#include "Shape.h"

namespace sh = hw5::Shapes;

std::string sh::toString(Shape sh) {
    using enum Shape;

    switch (sh) {
    case CIRCLE: 
        return "circle";
    case SQUARE:
        return "square";
    case TRIANGLE:
        return "triangle";
    default:
        return "unknown";
    }
}

sh::Shape sh::toShape(const std::string& sh) {
    using enum Shape;

    if (sh == "circle") {
        return CIRCLE;
    } else if (sh == "square") {
        return SQUARE;
    } else if (sh == "triangle") {
        return TRIANGLE;
    } else {
        return Unkown;
    }
}
