#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <chrono>

struct Order {
    int id = 0;
    std::string pizzaType;
    int preparationTime;
    int chefId = 0;

    std::chrono::steady_clock::time_point orderedAt;
    std::chrono::steady_clock::time_point cookedAt;
    std::chrono::steady_clock::time_point deliveredAt;

    Order (int oid, std::string type, int prepTime)
        :  id(oid), pizzaType(type), preparationTime(prepTime) {
        orderedAt = std::chrono::steady_clock::now();
    }
   
};
inline std::ostream& operator<< (std::ostream& out, const Order& o) {
    out << "Order #" << o.id << ": " << o.pizzaType;
    return out;
}
#endif