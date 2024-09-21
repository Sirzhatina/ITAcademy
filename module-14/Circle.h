#pragma once

namespace hw14 {
    class NegativeRadius : public std::logic_error {
    public:
        NegativeRadius(const std::string& msg) : std::logic_error{ msg } { }
    };

    class NullRadius : public std::runtime_error {
    public:
        NullRadius(const std::string& msg) : std::runtime_error{ msg } { }
    };

    class Circle {
    public:
        Circle(double radius) : m_radius{ radius } { }

        double calculateArea() const;

    private:
        double m_radius;
    };
}