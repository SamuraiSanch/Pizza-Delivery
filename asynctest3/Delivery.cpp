#include "Delivery.h"
#include <iostream>
#include <thread>
#include <chrono>

extern std::mutex coutMutex;

void Delivery::deliverOrder() {
    while (!(*m_stop)) {
        Order toDeliver = m_inputQueue.pop();
        {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << "[Delivery " << m_id << "] Delivering " << toDeliver << '\n';
        }
        std::this_thread::sleep_for(std::chrono::seconds(toDeliver.preparationTime));
        m_outputQueue.push(toDeliver);
        toDeliver.deliveredAt = std::chrono::steady_clock::now();
        {
            std::lock_guard<std::mutex> lock(coutMutex);
            std::cout << "[Delivery " << m_id << "] " << toDeliver << " delivered!" << '\n';
        }
    }
}