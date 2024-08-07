#pragma once

#include <vector>
#include <random>

#include "utility/StreamChecker.h"

namespace hw6 {
    class VectorGenerator;
}

/// @brief class used to internally store a vector with the size passed to the constructor.
/// Vector also can be sorted and printed.
class hw6::VectorGenerator {
public:
    /// @brief constructor used to initally pass the vector size.
    /// @param vecSize - size that the initialized vector will have
    explicit VectorGenerator(std::size_t vecSize);
    /// @brief method to print to the console the underlying vector values in one line with the whitespace as a delimeter.
    /// If the internal stream object sets in a fail state during the method execution, 
    /// the program will be stopped immidiately.
    /// @param msg - message inserted right before the printed vector.
    void printVector(const std::string& msg);
    /// @brief generates the random values for the underlying vector in the range from 1 to 100.
    void generate();
    /// @brief sorts the underlying vector.
    void sort();

private:

	std::vector<int> m_values;

    StreamChecker strchk{};


    std::random_device rd{};
    std::mt19937 mt{ rd() };
    std::uniform_int_distribution<int> distr{ 1, 100 };
};