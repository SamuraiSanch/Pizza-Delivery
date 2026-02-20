#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H

#include "Order.h"
#include <queue>
#include <mutex>
#include <condition_variable>

class OrderQueue {
private:
    std::queue<Order> orders;
    std::mutex mtx;
    std::condition_variable cv;
    bool stopped = false;

public:
    // Добавлення нового ордера в чергу
    void push(Order& order);
    Order pop();
    // Зупинка при стопі
    void stop();
    bool isStopped() const;
};


#endif