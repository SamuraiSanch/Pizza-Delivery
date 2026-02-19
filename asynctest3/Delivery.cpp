#include "Delivery.h"
#include <iostream>
#include <thread>
#include <chrono>

void Delivery::deliverOrder() {
    if (!m_stop) {
        Order toDeliver = m_inputQueue.pop();
        std::cout << "[Delivery " << m_id << "] Delivering " << toDeliver << '\n';
        std::this_thread::sleep_for(std::chrono::seconds(toDeliver.preparationTime));
        m_outputQueue.push(toDeliver);
        std::cout << "[Delivery " << m_id << "] " << toDeliver << " delivered!" << '\n';
    }
}