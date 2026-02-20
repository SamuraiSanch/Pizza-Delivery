#include "Waiter.h"
#include <random>
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <string>

extern std::mutex coutMutex;
int m_orderId = 0;

void Waiter::orderGenerate() {
    while (!(*m_stop)) {
    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "[Waiter " << m_id << "] Receiving order.\n";
    }
    std::string newPizza = getPizza(rand() % static_cast<int>(PIZZA_TOTAL));
    ++m_orderId;
    Order newOrder(m_orderId, newPizza, rand() % 4);
    std::this_thread::sleep_for(std::chrono::seconds(1 + rand()%2));
    m_newOrdersQueue.push(newOrder);
    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << "[Waiter " << m_id << "] " << newOrder << " received." << '\n';
    }
    }
}
std::string Waiter::getPizza(int num) {
    switch (num) {
    case MARGHERITA: return "Margherita";
    case PEPPERONI: return "Pepperoni";
    case HAWAIIAN: return "Hawaiian";
    default: return "Error!";
    }
}
