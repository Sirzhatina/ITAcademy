#pragma once

#include "IDeliveryStrategy.h"

class GroundDelivery : public IDeliveryStrategy {
public:
    GroundDelivery(float costPerkM) : m_costPerkM{ costPerkM } { }

    double calculateCost(float weight, float distance) override {
        return m_costPerkM * distance + weight;
    }

private:
    float m_costPerkM;
};