#include "Chef.h"
#include <iostream>
#include <thread>
#include <chrono>
#include "Colors.h"

extern std::mutex coutMutex;

void Chef::cookOrder() {
    while (!(*m_stop)) {
        Order toCook = m_inputQueue.pop();
        {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << YELLOW << "[Chef " << m_id << "] " << RESET << "Cooking " << toCook << '\n';
        }
        toCook.chefId = m_id;
        std::this_thread::sleep_for(std::chrono::seconds(toCook.preparationTime));
        toCook.cookedAt = std::chrono::steady_clock::now();
        m_outputQueue.push(toCook);
        {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << YELLOW << "[Chef " << m_id << "] " << GREEN << toCook << RESET << " is ready!" << '\n';
        }
    }
}