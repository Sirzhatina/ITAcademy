#include <iostream>
#include <string>
#include <cstdlib>
#include <random>
#include <format>


constexpr auto quitValue = 0;
constexpr std::uint16_t lowerBound = 1;
constexpr std::uint16_t upperBound = 10;

constexpr auto greet  = "Welcome to the Guessing game!\n";
// can't initialize at compile-time :(
const auto prompt = std::format("Guess the number from {} to {} ({} to quit): ", lowerBound, upperBound, quitValue);

constexpr auto congratulation = "You've guessed the number!";
constexpr auto bye            = "Bye! See you next time.";

inline void greeting() { std::cout << greet; }

inline void congrats() { std::cout << congratulation << std::endl; }

inline void goodbye() { std::cout << bye << std::endl; }

std::uint16_t requestAttempt();

void checkForCinCoutGoodState();

int gameLoop(std::uint16_t attempt);

int main(int argc, char* argv[]) {
    greeting();

    auto initialValue = requestAttempt();
    return gameLoop(initialValue);
}


int gameLoop(std::uint16_t attempt) {
    auto generate = [rd = std::random_device{}] () mutable { return rd() % upperBound + lowerBound; };
    
    std::uint16_t guess = generate();

    while (attempt != guess) {
        checkForCinCoutGoodState();
        if (attempt == quitValue) {
            goodbye();
            return EXIT_SUCCESS;
        }
        if (attempt > upperBound || attempt < lowerBound) {
            std::cout << "Bounds are violated! Try again with the old value to guess.\n";            
        }
        else {
            std::cout << "Wrong! Let's try again\n";
            guess = generate();
        }
        attempt = requestAttempt();
    }
    congrats();
    goodbye();

    return EXIT_SUCCESS;
}

void checkForCinCoutGoodState() {
    const std::string msg = "Something went wrong with the standard ";
    
    if (!std::cin) {
        std::cerr << msg + "input";
        exit(EXIT_FAILURE);
    }
    if (!std::cout) {
        std::cerr << msg + "output";
        exit(EXIT_FAILURE);
    }

}

std::uint16_t requestAttempt() {
    std::cout << prompt;

    std::uint16_t result{0};
    std::cin >> result;

    return result;
}