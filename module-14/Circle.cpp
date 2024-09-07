#include "Circle.h"
#include <format>
#include <numbers>

double hw14::Circle::calculateArea() const {
    if (m_radius < 0.0) {
        throw NegativeRadius{ std::format("The radius is negative: {}", m_radius) };
    }
    if (double eps = 1e-3; std::abs(m_radius) < eps) {
        throw NullRadius{ std::format("The radius is rounded up to zero, its value: {}", m_radius) };
    }
    return std::numbers::pi * std::pow(m_radius, 2);
}