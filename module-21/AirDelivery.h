#pragma once

#include "IDeliveryStrategy.h"

class AirDelivery : public IDeliveryStrategy {
public:
    AirDelivery(float costPerKmKg) : m_costPerKmKg{ costPerKmKg } { }

    double calculateCost(float weight, float distance) override {
        return m_costPerKmKg * (distance + WEIGHT_COEFFICIENT * weight);
    }
private:
    static constexpr float WEIGHT_COEFFICIENT = 0.7f;

    float m_costPerKmKg;
};