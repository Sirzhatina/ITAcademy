#include <string>
#include <format>
#include <iostream>

namespace hw5 { }

namespace hw5::Shapes {
    enum class Shape {
        Unkown = -1,
        CIRCLE,
        SQUARE,
        TRIANGLE
    };

    std::string toString(Shape sh) {
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

    void printShape(Shape sh) {
        std::cout
            << std::format(
                "The shape passed: {}\n", 
                toString(sh)
            ) << std::endl; 
    }
}



int main(int argc, char* argv[])
{
    auto usefulShape = hw5::Shapes::Shape::SQUARE;
    hw5::Shapes::printShape(usefulShape);

    std::string shapeInput;

    std::cout << "Enter the type of shape: ";
    std::getline(std::cin, shapeInput);

    auto importantShape = hw5::Shapes::toShape(shapeInput);
    hw5::Shapes::printShape(importantShape);
    
    return 0;
}