#include "Statistics.h"

void Statistics::calculateAllTime() {

    if (m_allOrdersInQueue.empty()) {
        m_averageCookingTime = 0.0;
        m_averageDeliveringTime = 0.0;
        m_averageTotalTime = 0.0;
        throw "Can't get statistic!";
    }

    double tempCookingTotal = 0.0;
    double tempDeliveringTotal = 0.0;
    // Обчислення часу приготування та доставки замовлення
    for (const auto& element : m_allOrdersInQueue) {
        tempCookingTotal += std::chrono::duration<double>(element.cookedAt - element.orderedAt).count();
        tempDeliveringTotal += std::chrono::duration<double>(element.deliveredAt - element.cookedAt).count();
    }

    m_averageCookingTime = tempCookingTotal / m_allOrdersInQueue.size();
    m_averageDeliveringTime = tempDeliveringTotal / m_allOrdersInQueue.size();

    // Обчислення загального середнього часу
    m_averageTotalTime = m_averageCookingTime + m_averageDeliveringTime;
}
/*
double Statistics::getAverageCookingTime() const {
    return m_averageCookingTime;
}
double Statistics::getAverageDeliveringTime() const {
    return m_averageDeliveringTime;
}
double Statistics::getAverageTotalTime() const {
    return m_averageTotalTime;
}
*/
void Statistics::setTotalOrders() {
    m_totalOrdersAccepted = m_newOrders.getSize();
    m_totalOrdersCooked = m_readyOrders.getSize();
    m_totalOrdersDelivered = m_deliveredOrders.getSize();
}
void Statistics::setEachChefCooked() {
    for (const auto& element : m_allOrdersInQueue) {
        ++eachChefCooked[element.chefId];
    }
}
void setEachPizzaPopularity() {

}