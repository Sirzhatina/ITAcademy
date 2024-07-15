#pragma once

#include <string>

namespace hw5 {}

namespace hw5::Shapes {
    /// @brief Enumeration to labeling different kind of shapes.
    /// Besides the shapes, enum contains default value to indicate
    /// unknown shape.
    enum class Shape {
        Unknown = -1,
        CIRCLE,
        SQUARE,
        TRIANGLE
    };

    /// @brief function used to convert the shape instance to std::string.
    /// @param sh - a shape to convert.
    /// @return textual representation of the shape.
    std::string toString(Shape sh);
    /// @brief function making the reverse conversion from string
    /// to a respective Shape.
    /// @param sh - textual representation of the Shape to convert from.
    /// @return converted Shape. Returns Unknown if there's no such shape inside
    /// the enum.
    Shape toShape(const std::string& sh);
}