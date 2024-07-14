#pragma once

#include "Shape.h"
#include <string>
#include <iostream>
#include <format>

namespace hw5::Shapes {
    class ShapeHandler;
}

class hw5::Shapes::ShapeHandler {
public:
    ShapeHandler() = default;
    ShapeHandler(Shape sh) : m_shape{sh} { }
    ShapeHandler(const std::string& shape) : m_shape{this->toShape(shape)} { }

    Shape asShape() const { return m_shape; }
    std::string asString() const { return this->toString(m_shape); }

    void printShape() const {
        std::cout
            << std::format(
                "The shape passed: {}\n", 
                this->toString(m_shape)
            ) << std::endl; 
    }
    
private:

    std::string toString(Shape sh) const {
        switch (sh) {
        case Shape::CIRCLE: 
            return "circle";
        case Shape::SQUARE:
            return "square";
        case Shape::TRIANGLE:
            return "triangle";
        default:
            return "unknown";
        }
    }

    Shape toShape(const std::string& sh) {
        if (sh == "circle") {
            return Shape::CIRCLE;
        } else if (sh == "square") {
            return Shape::SQUARE;
        } else if (sh == "triangle") {
            return Shape::TRIANGLE;
        } else {
            return Shape::Unkown;
        }
    }

    Shape m_shape = Shape::Unkown;
};