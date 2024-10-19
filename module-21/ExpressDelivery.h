#pragma once

#include "IDeliveryStrategy.h"

class ExpressDelivery : public IDeliveryStrategy {
public:
    ExpressDelivery(float costPerKmKg) : m_doubledCostPerKmKg{ 2.0f * costPerKmKg } { }

    double calculateCost(float weight, float distance) override {
        return m_doubledCostPerKmKg * (weight + distance);
    }
private:
    float m_doubledCostPerKmKg;
};