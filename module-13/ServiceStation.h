#pragma once

#include "ICar.h"
#include <concepts>
#include <vector>
#include <memory>
#include <iostream>

namespace hw13 {
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
}