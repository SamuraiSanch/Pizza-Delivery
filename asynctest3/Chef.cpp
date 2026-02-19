#include "Chef.h"
#include <iostream>
#include <thread>
#include <chrono>

void Chef::cookOrder() {
    if (!m_stop) {
        Order toCook = m_inputQueue.pop();
        std::cout << "[Chef " << m_id << "] Cooking " << toCook << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(toCook.preparationTime));
        m_outputQueue.push(toCook);
        std::cout << "[Chef " << m_id << "] " << toCook << " is ready!" << '\n';
    }
}