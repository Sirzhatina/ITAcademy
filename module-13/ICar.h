#pragma once

namespace hw13 {
    class ICar {
    public:
        virtual void drive() = 0;
        virtual void stop() = 0;
    };

#define DefVehicle(ClassName)       \
class ClassName : public ICar {     \
public:                             \
    void drive() override { }       \
    void stop() override { }        \
};

DefVehicle(Truck)
DefVehicle(PassengerCar)

#undef DefVehicle
}