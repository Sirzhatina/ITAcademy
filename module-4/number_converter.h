#pragma once

#include <bitset>


/// @brief class responsible for converting the given value
/// to another value depending on the condition
/// explained in the methods description.
/// The class keeps the value taken from user and uses it until
/// reset is called. Afterwards, the value should be given again.
class NumberConverter {
public:
    /// @brief Default constructor. Initial value for user's variable
    /// before setting it is -1.
    NumberConverter() = default;

    /// @brief takes a number from user as input and saves it
    /// for future conversion.
    /// Exits instantly if input error occurs.
    void userInput();
    /// @brief converts passed in userInput() method variable.
    /// Conversion rules are:
    /// if the value is positive and even it gets shifted left to 2 positions.
    /// otherwise, the value gets shifted right to 2 position. The method prints the warning,
    /// if the conversion occurs before value is set or after it's been reset.
    /// @return converted value.
    int convertValue() const;
    /// @brief prints the given value in an appropriate format.
    /// @param number - number to be printed.
    void printNumber(int number) const;
    /// @brief sets the instance of the class to unset state,
    /// meaning it doesn't keep a relevant value from the user yet.
    void reset();
    /// @brief tells whether the value is set or not.
    /// @return - true if the method userInput has been called
    /// the reset method hasn't yet. False otherwise.
    bool isSet() const;
    /// @brief returns the value saved inside, no matter whether set this value is or not.
    /// @return value saved inside.
    int currentNumber() const;

private:

    static constexpr auto BITS_IN_BYTE = 8;
    /// @brief constructs a bitset for given value to utilize its conversion to binary representation.
    /// @return new bitset from the passed integral parameter.
    auto AsBinary(std::integral auto n) const { return std::bitset<sizeof(n) * BITS_IN_BYTE>{static_cast<std::size_t>(n)}; }

    int m_userNumber = -1;
    bool m_isSet = false;
};