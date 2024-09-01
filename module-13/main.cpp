#include <concepts>
#include <vector>
#include <memory>
#include <iostream>
#include "utils.h"


class ICar {
public:
    virtual void drive() = 0;
    virtual void stop() = 0;
};

class SomePassengerCar : public ICar {
public:
    void drive() override { }
    void stop() override { }
};

class SomeTruck : public ICar {
public:
    void drive() override { }
    void stop() override { }
};

template <std::derived_from<ICar> C>
class ServiceStation {
    static constexpr std::size_t STATION_CAPACITY = 5;
public:
    ServiceStation() = default;

    void addCar(std::unique_ptr<C> car) {
        if (m_carsOnRepair.size() >= STATION_CAPACITY) {
            std::cout << "Sorry, the station is full, come back later\n";
            return;
        }
        m_carsOnRepair.push_back(std::move(car));
    }

    template <std::same_as<C>... Args>
    void addCar(std::unique_ptr<C> car, std::unique_ptr<Args>... cars) {
        if (m_carsOnRepair.size() >= STATION_CAPACITY) {
            std::cout << "Sorry, the station is full, come back later" << std::endl;
            return;
        }
        m_carsOnRepair.push_back(std::move(car));
        std::cout << "Added car successfully!" << std::endl;
        addCar(std::move(cars)...);
    }

    std::vector<std::unique_ptr<C>> repairAll() {
        std::cout << "All the cars have been repaired\n";
        return std::move(m_carsOnRepair);
    }

    std::size_t availableSpace() const { return STATION_CAPACITY - m_carsOnRepair.size(); }

private:

    std::vector<std::unique_ptr<C>> m_carsOnRepair;
};

template <class C>
void addRepairShow() {
    static auto spaceInfo = [](const auto& station) {
        itac::print("Available space for another vehicle: {}", station.availableSpace()) << std::endl;
    };

    ServiceStation<C> vehicleStation;

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

int main(int argc, char* argv[])
{   
    addRepairShow<SomeTruck>();

    addRepairShow<SomePassengerCar>();
    return 0;
}