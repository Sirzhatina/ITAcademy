#pragma once

#include <ios>
#include <source_location>

/// @brief class to check different states of the stream object
/// to ensure it's healthy or to early report about stream errors
/// to a user.
class StreamChecker {
public:
    /// @brief default constructor.
    StreamChecker() = default;

    /// @brief method to check whether the passed I/O stream object 
    /// is failed doing I/O operation or not. If the stream is in a fail state,
    /// the method prints info to the error stream and stops the program immediately.
    /// @param stream - object on which the method check if it's in a fail state or not.
    /// @param loc - object to locate to the call site if the object is in a fail state.
    void processStreamFailure(const std::ios& stream, std::source_location loc = std::source_location::current());
};