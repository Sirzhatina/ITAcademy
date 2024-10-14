#include <cmath>
#include <memory>
#include <iostream>
#include <print>

class IDeliveryStrategy {
public:
    virtual ~IDeliveryStrategy() = default;

    virtual double calculateCost(float weight, float distance) = 0;
};

class GroundDelivery : public IDeliveryStrategy {
public:
    GroundDelivery(float costPerkM) : m_costPerkM{costPerkM} { }

    double calculateCost(float weight, float distance) override {
        return m_costPerkM * distance + weight;
    }

private:
    float m_costPerkM;
};

class AirDelivery : public IDeliveryStrategy {
public:
    AirDelivery(float costPerKmKg) : m_costPerKmKg{costPerKmKg} { }

    double calculateCost(float weight, float distance) override {
        return m_costPerKmKg * (distance + WEIGHT_COEFFICIENT * weight);
    }
private:
    static constexpr float WEIGHT_COEFFICIENT = 0.7f;

    float m_costPerKmKg;
};

class ExpressDelivery : public IDeliveryStrategy {
public:
    ExpressDelivery(float costPerKmKg) : m_doubledCostPerKmKg{2.0f * costPerKmKg} { }

    double calculateCost(float weight, float distance) override {
        return m_doubledCostPerKmKg * (weight + distance);
    }
private:
    float m_doubledCostPerKmKg;
};

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

int main(int argc, char* argv[])
{
    float weight = 10.0f;
    float distance = 100.0f; 

    DeliveryContext ctx(std::make_unique<GroundDelivery>(20.f));
    std::println(
        "Ground Delivery Cost: ${}", 
        ctx.calculateDeliveryCost(weight, distance)
    );
    
    ctx.resetStrategy(std::make_unique<AirDelivery>(30.0f));
    std::println("Air Delivery Cost: ${}", ctx.calculateDeliveryCost(weight, distance));

    ctx.resetStrategy(std::make_unique<ExpressDelivery>(30.0f));
    std::println("Express Delivery Cost: ${}", ctx.calculateDeliveryCost(weight, distance));

    return 0;
}