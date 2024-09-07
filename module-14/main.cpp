#include "Task1.h"
#include "Circle.h"
#include "utils.h"

double askForValue();

int main(int argc, char* argv[])
{
    hw14::Task1 t1{};
    if (auto code = t1.mainFlow(); code != 0) {
        return code;
    }

    hw14::Circle c{ askForValue() };
    try
    {
        itac::print("The calculated area is: {}", c.calculateArea());
    }
    catch (hw14::NegativeRadius& e) {
        std::cerr << e.what();
    }
    catch (hw14::NullRadius& e) {
        std::cerr << e.what();
    }
    catch (const std::exception&)
    {
        std::cout << "Some general error occured.\n";
    }
    catch (...) {
        std::cerr << "Unknown error.";
    }

    return 0;
}

double askForValue() {
    double res = 0.0;
    std::cout << "Enter the value: ";
    std::cin >> res;

    return res;
}