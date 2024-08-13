#include "Book.h"

#include <iostream>
#include "utils.h"
#include "StreamChecker.h"

/// @brief The concept describing an object able to be read from the standard input.
template <class T>
concept Readable = requires (T t) { std::cin >> t; };

/// @brief Helper function for main to minimize code duplication.
/// The function effectively reads the generic readable object from the
/// standard input, writing the inviting message before reading, and returns this object.
/// @param msgBeforeInput - the message being written to the standard output before awaiting of input.
/// @return some readable object of generic type.
template <Readable T>
T readDataFromConsole(const char* msgBeforeInput) {
    T data{};

    std::cout << msgBeforeInput;
    std::cin >> data;

    StreamChecker check{};

    check.processStreamFailure(std::cout);
    check.processStreamFailure(std::cin);

    return data;
}
/// @brief std::string specialization of the corresponding primary template function.
/// This specialization reads the whole line of text before the '\n' character and
/// stores in inside std::string object. The rest of this spec is the same.
/// @return read from the standard input string.
template <>
std::string readDataFromConsole<std::string>(const char* msgBeforeInput) {
    std::string data;

    std::cout << msgBeforeInput;
    std::getline(std::cin, data);

    StreamChecker check{};

    check.processStreamFailure(std::cout);
    check.processStreamFailure(std::cin);

    return data;
}


int main(int argc, char* argv[])
{
    auto title = readDataFromConsole<std::string>("The title: ");
    auto author = readDataFromConsole<std::string>("The author: ");
    auto yOfp = readDataFromConsole<std::uint16_t>("The year of publishing: ");

    hw8::Book b{ title, author, yOfp };

    b.printInfo();

    std::cout << "\n------\nOr, calling each getter:\n";
    itac::print(
        "The title: {}\n"
        "The author: {}\n"
        "The year of publishing: {}",
        b.getTitle(),
        b.getAuthor(),
        b.getYearOfPublishing()
    ) << std::endl;

    return 0;
}