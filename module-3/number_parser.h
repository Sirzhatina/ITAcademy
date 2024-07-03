#pragma once

#include <cstdint>
#include <string>

/// @brief waits for the positive number from the standard input.
/// In case the input doesn't meet requirements, the program exits instantly.
/// @return - the number user entered
std::uint32_t input();

/// @brief the function parses the number provided as an argument
/// and returns it as a string with all digits separated by whitespaces
/// at the same (direct) order
/// @param n - the number user passes to parse
/// @return the string containing the direct-ordered 
/// number with whitespace-separated digits
std::string parseNumber(std::uint32_t n);

/// @brief current task's main function to handle the appropriate user output
void mainParseNumberTask();
