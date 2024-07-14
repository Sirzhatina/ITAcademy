#include "ShapeHandler.h"
#include <iostream>
#include <format>

namespace sh = hw5::Shapes;

sh::ShapeHandler::ShapeHandler(Shape sh) 
    : m_shape{sh} { }

sh::ShapeHandler::ShapeHandler(const std::string& shape) 
    : m_shape{this->toShape(shape)} { }

sh::Shape sh::ShapeHandler::asShape() const { 
    return m_shape; 
}

std::string sh::ShapeHandler::asString() const { 
    return this->toString(m_shape); 
}

void sh::ShapeHandler::printShape() const {
    std::cout
        << std::format(
            "The shape passed: {}\n", 
            this->toString(m_shape)
        ) << std::endl; 
}

std::string sh::ShapeHandler::toString(Shape sh) const {
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

sh::Shape sh::ShapeHandler::toShape(const std::string& sh) {
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