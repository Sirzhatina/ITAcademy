#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include <algorithm>
#include <format>
#include <iostream>
#include "utils.h"

namespace chr = std::chrono;

chr::sys_days floorToCurrentDay(const chr::system_clock::time_point& tp) {
    return chr::floor<chr::days>(tp);
}

chr::hh_mm_ss<chr::seconds> retrieveTime(const chr::system_clock::time_point& tp) {
    auto day = floorToCurrentDay(tp);
    return chr::hh_mm_ss{ chr::duration_cast<chr::seconds>(tp - day) };
}

class Order {
    static inline auto ordersCreated = 0;
public:
    enum class Status {
        New,
        Processing,
        Shipped
    };

public:
    explicit Order(double cost) 
        : m_orderCreation{chr::system_clock::now()}
        , m_orderNumber{++ordersCreated}
        , m_orderCost{cost}
        , m_orderStatus{Status::New}
        , m_orderDate{floorToCurrentDay(m_orderCreation)}
        , m_orderTime{ chr::duration_cast<chr::seconds>(m_orderCreation - floorToCurrentDay(m_orderCreation)) } {
    }


    Order(const Order& o) {
        *this = o;
        ++ordersCreated;
    }


    ~Order() { 
        ordersCreated--; 
    }

    void startProcessing() {
        if (currentStatus() == Status::New) {
            m_orderStatus = Status::Processing;
        }
    }

    [[nodiscard]]
    Status currentStatus() const { return m_orderStatus; }

    [[nodiscard]]
    int orderNumber() const { return m_orderNumber; }

    [[nodiscard]]
    std::chrono::year_month_day orderDate() const { return m_orderDate; }

    [[nodiscard]]
    double orderCost() const {
        return m_orderCost;
    }

    [[nodiscard]]
    chr::seconds elapsedSinceOrder() const {
        return chr::duration_cast<chr::seconds>(chr::system_clock::now() - m_orderCreation);
    }

private:
    chr::system_clock::time_point m_orderCreation;

    int m_orderNumber;
    double m_orderCost;
    Status m_orderStatus;

    chr::year_month_day m_orderDate;
    chr::hh_mm_ss<chr::seconds> m_orderTime;
};

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