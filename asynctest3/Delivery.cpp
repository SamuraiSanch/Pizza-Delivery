#include "Delivery.h"
#include <iostream>
#include <thread>
#include <chrono>
#include "Colors.h"

extern std::mutex coutMutex;

void Delivery::deliverOrder() {
    while (!(*m_stop)) {
        Order toDeliver = m_inputQueue.pop();
        {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << MAGENTA << "[Delivery " << m_id << "] " << RESET << "Delivering " << toDeliver << '\n';
        }
        std::this_thread::sleep_for(std::chrono::seconds(toDeliver.preparationTime));
        toDeliver.deliveredAt = std::chrono::steady_clock::now();
        m_outputQueue.push(toDeliver);
        {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << MAGENTA << "[Delivery " << m_id << "] " << GREEN << toDeliver << RESET << " delivered!" << '\n';
        }
    }
}