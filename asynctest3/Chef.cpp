#include "Chef.h"
#include <iostream>
#include <thread>
#include <chrono>

extern std::mutex coutMutex;

void Chef::cookOrder() {
    while (!(*m_stop)) {
        Order toCook = m_inputQueue.pop();
        {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << "[Chef " << m_id << "] Cooking " << toCook << '\n';
        }
        toCook.chefId = m_id;
        std::this_thread::sleep_for(std::chrono::seconds(toCook.preparationTime));
        m_outputQueue.push(toCook);
        toCook.cookedAt = std::chrono::steady_clock::now();
        {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << "[Chef " << m_id << "] " << toCook << " is ready!" << '\n';
        }
    }
}