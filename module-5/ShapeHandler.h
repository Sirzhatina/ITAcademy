#pragma once

#include "Shape.h"
#include <string>

namespace hw5::Shapes {
    class ShapeHandler;
}

/// @brief helper class for the Shape enum
/// to handle basic operations with its instances.
/// The shape handler stores one shape instance and lets user
/// to get different forms of it using this class.
class hw5::Shapes::ShapeHandler {
public:
    /// @brief default constructor. Set the internal shape to Unknown instance.
    ShapeHandler() = default;

    /// @brief constructs the instance from the given shape.
    /// @param sh - the shape to construct from.
    ShapeHandler(Shape sh);

    /// @brief constructs the instance from the shape internally converted
    /// from the passed string.
    /// @param shape - string to convert the shape from. The shape sets to Unkown
    /// if an unrecognized sequence of characters is passed.
    ShapeHandler(const std::string& shape);
    
    /// @brief returns raw shape from the current instance.
    /// @return underlying Shape.
    Shape asShape() const;
    
    /// @brief return a string converted from the underlying Shape.
    /// @return textual representation of the underlying string.
    std::string asString() const;
    
    /// @brief prints the textual representation of the shape in 
    /// an internally chosen format.
    void printShape() const;
    
private:

    Shape m_shape = Shape::Unkown;
};