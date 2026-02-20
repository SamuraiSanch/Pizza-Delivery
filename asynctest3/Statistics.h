#ifndef STATISTICS_H
#define STATISTICS_H
#include <map>
#include <string>
#include "OrderQueue.h"
class Statistics {
private:
    int m_totalOrdersAccepted;
    int m_totalOrdersCooked;
    int m_totalOrdersDelivered;
    double m_totalAverageTime;

    std::map<int, int> eachChefCooked;
    std::map<std::string, int> eachPizzaPopularity;
    void setAverageTotalTime(const OrderQueue& q);
    void setTotalOrdersAccepted();
    void setTotalOrdersCooked();
    void setTotalOrdersDelivered();
public:
    double getAverageCookingTime();
    double getAverageDeliveringTime();
    std::map<int, int>& getEachChefCooked() const;
    std::map<std::string, int>& getEachPizzaPopularity() const;

};


#endif