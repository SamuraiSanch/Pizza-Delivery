#include "Waiter.h"
#include <random>
#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <string>

void Waiter::orderGenerate() {
    if (!m_stop) {
    std::cout << "[Waiter " << m_id << "] Receiving order.\n";
    std::string newPizza = getPizza(rand() % static_cast<int>(PIZZA_TOTAL));
    Order newOrder(newPizza, rand() % 4);
    std::this_thread::sleep_for(std::chrono::seconds(1 + rand()%2));
    m_newOrdersQueue.push(newOrder);
    std::cout << "[Waiter " << m_id << "] " << newOrder << " received." << '\n';
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
