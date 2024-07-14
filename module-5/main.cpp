#include <string>
#include <iostream>
#include "ShapeHandler.h"


int main(int argc, char* argv[])
{
    namespace sh = hw5::Shapes;

    sh::ShapeHandler usefulShape{sh::Shape::TRIANGLE};
    usefulShape.printShape();

    std::string shapeInput;

    std::cout << "Enter the type of shape: ";
    std::getline(std::cin, shapeInput);
    
    sh::ShapeHandler importantShape{shapeInput};
    importantShape.printShape();

    return 0;
}