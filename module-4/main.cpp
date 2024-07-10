#include <concepts>
#include <format>
#include <iostream>
#include <bitset>

constexpr auto bitsInByte = 8;
auto AsBinary(std::integral auto n) { return std::bitset<sizeof(n) * bitsInByte>{static_cast<std::size_t>(n)}; }

int main(int argc, char* argv[])
{
    int number = -1;

    std::cout << "Enter the number: ";
    std::cin >> number;
    std::cout << std::format(
        "Binary representation of this number: {}\n",
            AsBinary(number).to_string()
        );

    number = (number > 0 && (number & 1) == 0) ? number << 2 : number >> 2;

    std::cout 
        << std::format(
            "Shifted number is: {}\n"
            "Its binary representation is: {}",
            number, 
            AsBinary(number).to_string()
        ) << std::endl;
    return 0;
}