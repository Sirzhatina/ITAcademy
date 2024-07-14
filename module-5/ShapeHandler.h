#pragma once

#include "Shape.h"
#include <string>

namespace hw5::Shapes {
    class ShapeHandler;
}

class hw5::Shapes::ShapeHandler {
public:
    ShapeHandler() = default;
    ShapeHandler(Shape sh);
    ShapeHandler(const std::string& shape);

    Shape asShape() const;
    std::string asString() const;

    void printShape() const;
    
private:

    std::string toString(Shape sh) const;

    Shape toShape(const std::string& sh);

    Shape m_shape = Shape::Unkown;
};