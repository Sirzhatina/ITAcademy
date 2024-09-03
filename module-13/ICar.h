#pragma once

namespace hw13 {
    /// @brief helper interface class representing a car for ServiceStation template class. 
    class ICar {
    public:
        /// @brief dummy method imitating an action of the instance
        virtual void drive() = 0;
        /// @brief dummy method imitating an action of the instance
        virtual void stop() = 0;
    };

/// @brief macro defining the class that derives from helper class ICar and overrides its methods.
/// @param ClassName - the name of the future class
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