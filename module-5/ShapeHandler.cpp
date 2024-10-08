#include "ShapeHandler.h"
#include <iostream>
#include <format>
#include <type_traits>

namespace sh = hw5::Shapes;

sh::ShapeHandler::ShapeHandler(Shape sh) 
    : m_shape{sh} { }

sh::ShapeHandler::ShapeHandler(const std::string& shape) 
    : ShapeHandler(sh::toShape(shape)) { }

sh::Shape sh::ShapeHandler::asShape() const { 
    return m_shape; 
}

std::string sh::ShapeHandler::asString() const { 
    return sh::toString(m_shape); 
}

void sh::ShapeHandler::printShape() const {
    std::cout
        << std::format(
            "The shape passed: {}\n"
            "Its numeric representation: {}\n",
            this->asString(),
            static_cast<std::underlying_type_t<Shape>>(this->asShape())
        ) << std::endl; 
}
