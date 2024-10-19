#include "Order.h"

namespace chr = std::chrono;

chr::sys_days floorToCurrentDay(const chr::system_clock::time_point& tp) {
    return chr::floor<chr::days>(tp);
}

chr::hh_mm_ss<chr::seconds> retrieveTime(const chr::system_clock::time_point& tp) {
    auto day = floorToCurrentDay(tp);
    return chr::hh_mm_ss{ chr::duration_cast<chr::seconds>(tp - day) };
}


Order::Order(double cost)
    : m_orderCreation{ chr::system_clock::now() }
    , m_orderNumber{ ++ordersCreated }
    , m_orderCost{ cost }
    , m_orderStatus{ Status::New }
    , m_orderDate{ floorToCurrentDay(m_orderCreation) }
    , m_orderTime{ chr::duration_cast<chr::seconds>(m_orderCreation - floorToCurrentDay(m_orderCreation)) } {
}


Order::Order(const Order& o) {
    *this = o;
    ++ordersCreated;
}


Order::~Order() {
    ordersCreated--;
}

void Order::startProcessing() {
    if (currentStatus() == Status::New) {
        m_orderStatus = Status::Processing;
    }
}

Order::Status Order::currentStatus() const { return m_orderStatus; }

int Order::orderNumber() const { return m_orderNumber; }

chr::year_month_day Order::orderDate() const { return m_orderDate; }

double Order::orderCost() const {
    return m_orderCost;
}

chr::seconds Order::elapsedSinceOrder() const {
    return chr::duration_cast<chr::seconds>(chr::system_clock::now() - m_orderCreation);
}