#include "Book.h"

#include <iostream>
#include "utils.h"


int main(int argc, char* argv[])
{
    std::string author, title;
    std::uint16_t yearOfPublishing;

    std::cout << "Enter the book data.\nThe author: ";
    std::getline(std::cin, author);

    std::cout << "The title: ";
    std::getline(std::cin, title);

    std::cout << "The year of publishing: ";
    std::cin >> yearOfPublishing;

    hw8::Book b{ author, title, yearOfPublishing };

    b.printInfo();

    std::cout << "\n------\nOr, calling each getter:\n";
    itac::print(
        "The author: {}\n"
        "The title: {}\n"
        "The year of publishing: {}",
        b.getAuthor(),
        b.getTitle(),
        b.getYearOfPublishing()
    ) << std::endl;

    return 0;
}