#include "Book.h"

#include <iostream>
#include "utils.h"
#include "StreamChecker.h"

template <class T>
concept Readable = requires (T t) { std::cin >> t; };

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