#ifndef ORDERQUEUE_H
#define ORDERQUEUE_H

#include "Order.h"
#include <queue>
#include <mutex>
#include <condition_variable>

class OrderQueue {
private:
    int m_orderId = 0;
    std::queue<Order> orders;
    std::mutex mtx;
    std::condition_variable cv;
    bool stopped = false;

public:
    // Добавлення нового ордера в чергу
    void push(Order& order);
    // Видалення ордера з черги
    Order pop();  // Блокується якщо черга порожня
    // Зупинка при стопі
    void stop();  // Сигналізує про зупинку
    bool isStopped() const;
};


#endif