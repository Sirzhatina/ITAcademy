#pragma once
#include <chrono>


class Order {
    static inline auto ordersCreated = 0;
public:
    enum class Status {
        New,
        Processing,
        Shipped
    };

public:
    explicit Order(double cost);

    Order(const Order& o);

    ~Order();

    void startProcessing();

    [[nodiscard]] Status currentStatus() const;

    [[nodiscard]] int orderNumber() const;

    [[nodiscard]] std::chrono::year_month_day orderDate() const;

    [[nodiscard]] double orderCost() const;

    [[nodiscard]] std::chrono::seconds elapsedSinceOrder() const;

private:
    std::chrono::system_clock::time_point m_orderCreation;

    int m_orderNumber;
    double m_orderCost;
    Status m_orderStatus;

    std::chrono::year_month_day m_orderDate;
    std::chrono::hh_mm_ss<std::chrono::seconds> m_orderTime;
};