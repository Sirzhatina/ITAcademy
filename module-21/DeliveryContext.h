#pragma once

#include <memory>
#include "IDeliveryStrategy.h"

class DeliveryContext {
public:
    DeliveryContext(std::unique_ptr<IDeliveryStrategy> strategy)
        : m_deliveryStrategy{ std::move(strategy) } { }

    double calculateDeliveryCost(float weight, float distance) {
        return m_deliveryStrategy->calculateCost(weight, distance);
    }

    std::unique_ptr<IDeliveryStrategy> resetStrategy(std::unique_ptr<IDeliveryStrategy> strategy) {
        auto old = std::move(m_deliveryStrategy);
        m_deliveryStrategy = std::move(strategy);
        return old;
    }
private:
    std::unique_ptr<IDeliveryStrategy> m_deliveryStrategy;
};