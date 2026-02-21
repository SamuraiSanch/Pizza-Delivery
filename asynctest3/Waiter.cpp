#include "Waiter.h"
#include <random>
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <string>
#include <atomic>
#include "Colors.h"
extern std::mutex coutMutex;
std::atomic<int> orderId(0);

void Waiter::orderGenerate() {
    while (!(*m_stop)) {
    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << CYAN << "[Waiter " << m_id << "] " << RESET << "Receiving order.\n";
    }
    std::string newPizza = getPizza(rand() % static_cast<int>(PIZZA_TOTAL));
    ++orderId;
    Order newOrder(orderId, newPizza, rand() % 4);
    std::this_thread::sleep_for(std::chrono::seconds(1 + rand()%2));
    m_newOrdersQueue.push(newOrder);
    {
        std::lock_guard<std::mutex> lock(coutMutex);
        std::cout << CYAN << "[Waiter " << m_id << "] " << GREEN << newOrder << RESET << " received." << '\n';
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
