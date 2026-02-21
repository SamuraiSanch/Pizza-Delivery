#ifndef STATISTICS_H
#define STATISTICS_H
#include <map>
#include <string>
#include "OrderQueue.h"
class Statistics {
private:
    OrderQueue& m_newOrders;
    OrderQueue& m_readyOrders;
    OrderQueue& m_deliveredOrders;

    std::vector<Order> m_allOrdersInDeliverQueue;
    std::vector<Order> m_allOrdersInChefQueue;
    std::vector<Order> m_allOrdersInWaiterQueue;

    int m_totalOrdersAccepted;
    int m_totalOrdersCooked;
    int m_totalOrdersDelivered;
    double m_averageCookingTime;
    double m_averageDeliveringTime;
    double m_averageTotalTime;

    std::map<int, int> eachChefCooked;
    std::map<std::string, int> eachPizzaPopularity;
    void calculateAllTime();
    void setTotalOrders();
    void setEachChefCooked();
    void setEachPizzaPopularity();
public:
    Statistics(OrderQueue& newOrders, OrderQueue& readyOrders, OrderQueue& deliveredOrders) : m_newOrders(newOrders), m_readyOrders(readyOrders), m_deliveredOrders(deliveredOrders){ 
        m_allOrdersInWaiterQueue = m_newOrders.getAllOrders();
        m_allOrdersInChefQueue = m_readyOrders.getAllOrders();
        m_allOrdersInDeliverQueue = m_deliveredOrders.getAllOrders(); 
        calculateAllTime();
        setTotalOrders();
        setEachChefCooked();
        setEachPizzaPopularity();
    }
    friend std::ostream& operator<< (std::ostream& out, Statistics& s);
};


#endif