#ifndef ORDER_H
#define ORDER_H
#include <iostream>
#include <chrono>

struct Order {
    int id = 0;                    // Унікальний номер замовлення
    std::string pizzaType;     // Тип піци (Margherita, Pepperoni, Hawaiian)
    int preparationTime;       // Час приготування в секундах (1-3)

    // Timestamps для статистики
    std::chrono::steady_clock::time_point orderedAt;
    std::chrono::steady_clock::time_point cookedAt;
    std::chrono::steady_clock::time_point deliveredAt;

    Order (std::string type, int prepTime)
        :  pizzaType(type), preparationTime(prepTime) {
        orderedAt = std::chrono::steady_clock::now();
    }
   
};
std::ostream& operator<< (std::ostream& out, Order& o) {
    out << "Order #" << o.id << ": " << o.pizzaType;
    return out;
}
#endif