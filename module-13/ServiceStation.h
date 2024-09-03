#pragma once

#include "ICar.h"
#include <concepts>
#include <vector>
#include <memory>
#include <iostream>

namespace hw13 {
    /// @brief service station class repairing the vehicles. The class expects any type parameter passed
    /// to be derived from ICar.
    template <std::derived_from<ICar> C>
    class ServiceStation {
        static constexpr std::size_t STATION_CAPACITY = 5;
    public:
        /// @brief default constructor. Initializes an empty garage for vehicles to repair.
        ServiceStation() = default;
        /// @brief base case for the recursive template method.
        /// @param car - a car to add to the garage.
        void addCar(std::unique_ptr<C> car) {
            if (m_carsOnRepair.size() >= STATION_CAPACITY) {
                std::cout << "Sorry, the station is full, come back later\n";
                return;
            }
            m_carsOnRepair.push_back(std::move(car));
        }
        /// @brief method to add cars to the garage to repair them.
        /// If the garage is full, the rest of the cars won't be added.
        /// @tparams ...Args - all passed types are same as C which in turn are derived from ICar.
        /// @param car - fixed argument for base case.
        /// @param ...cars - cars to be added in a recursive manner.
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
        /// @brief method repairs all the cars held in garage and releases them afterwars,
        /// passing ownership to the caller.
        /// @return vector of pointers to repaired cars. 
        std::vector<std::unique_ptr<C>> repairAll() {
            std::cout << "All the cars have been repaired\n";
            return std::move(m_carsOnRepair);
        }

        std::size_t availableSpace() const { return STATION_CAPACITY - m_carsOnRepair.size(); }

    private:

        std::vector<std::unique_ptr<C>> m_carsOnRepair;
    };
}