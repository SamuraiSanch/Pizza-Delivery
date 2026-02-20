#ifndef WAITER_H
#define WAITER_H
#include "OrderQueue.h"

class Waiter {
private:
    int m_id;
    bool* m_stop;
    OrderQueue& m_newOrdersQueue;
    enum Pizza {
        MARGHERITA,
        PEPPERONI,
        HAWAIIAN,
        PIZZA_TOTAL
    };
    std::string getPizza(int num);

public:
    Waiter(int id, OrderQueue& newOrdersQueue, bool* stop) : m_id(id), m_newOrdersQueue(newOrdersQueue), m_stop(stop) {  }
    void orderGenerate();
};

#endif