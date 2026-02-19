#ifndef CHEF_H
#define CHEF_H
#include "OrderQueue.h"
class Chef {
private:
    int m_id;
    OrderQueue& m_inputQueue;
    OrderQueue& m_outputQueue;
    bool m_stop = false;
public:
    Chef(int id, OrderQueue& inputQueue, OrderQueue& outputQueue, bool stop) : m_id(id), m_inputQueue(inputQueue), m_outputQueue(outputQueue), m_stop(stop) {}
    void cookOrder();
};


#endif