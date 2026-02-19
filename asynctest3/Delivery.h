#ifndef DELIVERY_H
#define DELIVERY_H
#include "OrderQueue.h"

class Delivery {
private:
    int m_id;
    OrderQueue& m_inputQueue;
    OrderQueue& m_outputQueue;
    bool m_stop;
public:
    Delivery(int id, OrderQueue& inputQueue, OrderQueue& outputQueue, bool stop = false) : m_id(id), m_inputQueue(inputQueue), m_outputQueue(outputQueue), m_stop(stop) { }
    void deliverOrder();
};

#endif