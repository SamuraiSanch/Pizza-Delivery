#include "OrderQueue.h"

void OrderQueue::push(Order &order) {
    std::unique_lock<std::mutex> lock(mtx);
    orders.push(order);
    cv.notify_one();
}
Order OrderQueue::pop() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [this] { return !orders.empty() || stopped; });
    if (stopped && orders.empty())
        throw std::runtime_error("Queue is stopped");
    Order newOrder = orders.front();
    orders.pop();
    return newOrder;
}
void OrderQueue::stop() {
    std::unique_lock<std::mutex> lock(mtx);
    stopped = true;
    cv.notify_all();
}
bool OrderQueue::isStopped() const {
    return stopped;
}
std::vector<Order> OrderQueue::getAllOrders() {
    std::unique_lock<std::mutex> lock(mtx);
    std::vector<Order> result;
    std::queue<Order> temp = orders;
    while (!temp.empty()) {
        result.push_back(temp.front());
        temp.pop();
    }
    return result;
}
int OrderQueue::getSize() const {
    return orders.size();
}