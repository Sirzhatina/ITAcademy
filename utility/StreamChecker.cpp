#include "StreamChecker.h"

#include <iostream>
#include <format>

void StreamChecker::processStreamFailure(const std::ios& stream, std::source_location loc) {
    if (stream.fail()) {
        std::cerr
            << std::format(
                "{} failed to write.\n"
                "\tLine: {}\n"
                "\tFile: {}\n,",
                typeid(stream).name(),
                loc.line(),
                loc.file_name()
            ) << std::endl;
        std::exit(EXIT_FAILURE);
    }
}