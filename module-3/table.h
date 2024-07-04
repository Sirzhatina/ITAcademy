#pragma once

/// @brief main function for the current task, called in target's main() function
/// directly and responsible for showing the multiplication table in an appropriate format
void mainTableTask();

/// @brief Prints in one line expressions separated by tabs 
/// with one operand variating from lowerBound to upperBound (exclusively)
/// in each expression, multiplied by constant operand as a second one
/// @param lowerBound - first operand of the expressions, each of which has it
/// incremented
/// @param upperBound - value to which lowerBound operand will exclusively be incrementing
/// @param factor - second operand of the expressions, stays the same for all of them
void printLine(int lowerBound, const int upperBound, const int factor);

/// @brief iteratively calls printLine() passing it its own arguments
/// and incrementing factor for each call from 1 to 10
/// @param lowerBound - parameter passed for internally called printLine()
/// and serving the same purpose as for that function
/// @param upperBound - same as lowerBound: internally passed for printLine()
void printColumns(int lowerBound, const int upperBound);
