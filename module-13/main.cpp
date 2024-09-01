#include "ServiceStation.h"
#include "utils.h"

template <class C>
void addRepairShow();

int main(int argc, char* argv[])
{   
    addRepairShow<hw13::Truck>();

    addRepairShow<hw13::PassengerCar>();
    return 0;
}

template <class C>
void addRepairShow() {
    static auto spaceInfo = [](const auto& station) {
        itac::print("Available space for another vehicle: {}", station.availableSpace()) << std::endl;
    };

    hw13::ServiceStation<C> vehicleStation;

    vehicleStation.addCar(
        std::make_unique<C>(),
        std::make_unique<C>(),
        std::make_unique<C>(),
        std::make_unique<C>(),
        std::make_unique<C>(),
        std::make_unique<C>()
    );
    spaceInfo(vehicleStation);

    vehicleStation.repairAll();
    spaceInfo(vehicleStation);
}