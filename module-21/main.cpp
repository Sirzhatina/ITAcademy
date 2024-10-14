#include <memory>
#include <print>
#include "DeliveryContext.h"
#include "GroundDelivery.h"
#include "AirDelivery.h"
#include "ExpressDelivery.h"


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