#pragma once

class IDeliveryStrategy {
public:
    virtual ~IDeliveryStrategy() = default;

    virtual double calculateCost(float weight, float distance) = 0;
};