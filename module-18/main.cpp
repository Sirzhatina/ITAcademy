#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <algorithm>
#include <format>
#include <iostream>
#include "utils.h"
#include "Order.h"


int main(int argc, char* argv[])
{
    using namespace std::chrono_literals;
    namespace rng = std::ranges;

    std::vector<Order> orders;
    orders.reserve(10);
    orders.push_back(Order{ 3'000 });
    orders.push_back(Order{ 5'000 });
    orders.push_back(Order{ 9'876 });
    std::this_thread::sleep_for(5s);
    
    orders.push_back(Order{ 1 });
    orders.push_back(Order{ 5'492 });

    rng::transform(orders, rng::begin(orders), [](auto element) {
        using namespace std::chrono_literals;

        if (element.elapsedSinceOrder() >= 5s) {
            element.startProcessing();
        }
        return element;
    });

    auto found = rng::find_if(orders, [](const Order& element) {
        return element.currentStatus() == Order::Status::Processing && element.orderCost() > 5000.0;
    });

    if (found != rng::end(orders)) {
        itac::print(
            "Found order number and cost: {}, {}", 
            found->orderNumber(), 
            found->orderCost()
        );
    }
    else {
        std::cout << "No elements with given criteria found";
    }
    std::cout << std::endl;

     return 0;
}