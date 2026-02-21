#include "Statistics.h"
#include "Colors.h"
void Statistics::calculateAllTime() {

    if (m_allOrdersInDeliverQueue.empty()) {
        m_averageCookingTime = 0.0;
        m_averageDeliveringTime = 0.0;
        m_averageTotalTime = 0.0;
        return;
    }

    double tempCookingTotal = 0.0;
    double tempDeliveringTotal = 0.0;
    int validCount = 0;
    // Обчислення часу приготування та доставки замовлення
    for (const auto& element : m_allOrdersInDeliverQueue) {
        if (element.cookedAt.time_since_epoch().count() > 0 &&
            element.deliveredAt.time_since_epoch().count() > 0) {
            tempCookingTotal += std::chrono::duration<double>(element.cookedAt - element.orderedAt).count();
            tempDeliveringTotal += std::chrono::duration<double>(element.deliveredAt - element.cookedAt).count();
            ++validCount;
        }
    } // m_allOrdersInChefQueue
    int cookCount = 0;
    for (const auto& element : m_allOrdersInChefQueue) {
        if (element.cookedAt.time_since_epoch().count() > 0) {
            tempCookingTotal += std::chrono::duration<double>(element.cookedAt - element.orderedAt).count();
            ++cookCount;
        }
    }
    if (validCount > 0) {
        m_averageCookingTime = tempCookingTotal / (cookCount + validCount);
        m_averageDeliveringTime = tempDeliveringTotal / validCount;
    }
    else {
        m_averageCookingTime = 0.0;
        m_averageDeliveringTime = 0.0;
    }
    // Обчислення загального середнього часу
    m_averageTotalTime = m_averageCookingTime + m_averageDeliveringTime;
}
void Statistics::setTotalOrders() {
    m_totalOrdersAccepted = m_newOrders.getSize() + m_readyOrders.getSize() + m_deliveredOrders.getSize();
    m_totalOrdersCooked = m_readyOrders.getSize() + m_deliveredOrders.getSize();
    m_totalOrdersDelivered = m_deliveredOrders.getSize();
}
void Statistics::setEachChefCooked() {
    for (const auto& element : m_allOrdersInDeliverQueue) {
        if (element.chefId > 0)
        ++eachChefCooked[element.chefId];
    }
    for (const auto& element : m_allOrdersInChefQueue) {
        if (element.chefId > 0)
            ++eachChefCooked[element.chefId];
    }
}
void Statistics::setEachPizzaPopularity() {
    for (const auto& element : m_allOrdersInDeliverQueue) {
        if (!element.pizzaType.empty())
        ++eachPizzaPopularity[element.pizzaType];
    }
    for (const auto& element : m_allOrdersInChefQueue) {
        if (!element.pizzaType.empty())
            ++eachPizzaPopularity[element.pizzaType];
    }
    for (const auto& element : m_allOrdersInWaiterQueue) {
        if (!element.pizzaType.empty())
            ++eachPizzaPopularity[element.pizzaType];
    }
}
std::ostream& operator<< (std::ostream& out, Statistics& s) {
    out << "\n" << BOLD << CYAN << "=== STATISTICS ===" << RESET
        << "\n Orders:\n Received: \t" << GREEN << s.m_totalOrdersAccepted << RESET
        << "\n Cooked: \t" << GREEN << s.m_totalOrdersCooked << YELLOW << " (" << s.m_totalOrdersAccepted - s.m_totalOrdersCooked << " still in preparation)" << RESET
        << "\n Delivered: \t" << GREEN << s.m_totalOrdersDelivered << YELLOW << " (" << s.m_totalOrdersCooked - s.m_totalOrdersDelivered << " still in delivery)" << RESET

        << "\n\n Average Times:\n Cooking: \t" << CYAN << s.m_averageCookingTime << "s" << RESET
        << "\n Delivery: \t" << CYAN << s.m_averageDeliveringTime << "s" << RESET
        << "\n Total: \t" << MAGENTA << s.m_averageTotalTime << "s" << RESET

        << "\n\n Chef productivity:\n Chef 1: \t" << GREEN << s.eachChefCooked[1] << RESET
        << "\n Chef 2: \t" << GREEN << s.eachChefCooked[2] << RESET
        << "\n Chef 3: \t" << GREEN << s.eachChefCooked[3] << RESET

        << "\n\n Popular pizzas:\n Margherita: \t" << YELLOW << s.eachPizzaPopularity["Margherita"] << RESET
        << "\n Pepperoni: \t" << YELLOW << s.eachPizzaPopularity["Pepperoni"] << RESET
        << "\n Hawaiian: \t" << YELLOW << s.eachPizzaPopularity["Hawaiian"] << RESET << "\n";

    return out;
}