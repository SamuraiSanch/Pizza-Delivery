#include <iostream>
#include <thread>
#include <time.h>
#include <cstdlib>
#include "Waiter.h"
#include "Chef.h"
#include "Delivery.h"
#include "Statistics.h"
#include "Colors.h"

std::mutex coutMutex;
const int workingTime = 10;

int main() {
    srand(static_cast<unsigned int>(time(0)));
    rand();
    OrderQueue newOrders;
    OrderQueue readyOrders;
    OrderQueue deliveredOrders;
    bool stop = false;
    Waiter w1(1, newOrders, &stop);
    Waiter w2(2, newOrders, &stop);
    Chef c1(1, newOrders, readyOrders, &stop);
    Chef c2(2, newOrders, readyOrders, &stop);
    Chef c3(3, newOrders, readyOrders, &stop);
    Delivery d1(1, readyOrders, deliveredOrders, &stop);
    Delivery d2(2, readyOrders, deliveredOrders, &stop);
    int counter = 0;

    std::thread wt1(&Waiter::orderGenerate, &w1);
    std::thread wt2(&Waiter::orderGenerate, &w2);
    std::thread ct1(&Chef::cookOrder, &c1);
    std::thread ct2(&Chef::cookOrder, &c2);
    std::thread ct3(&Chef::cookOrder, &c3);
    std::thread dt1(&Delivery::deliverOrder, &d1);
    std::thread dt2(&Delivery::deliverOrder, &d2);

    auto startedWorkingAt = std::chrono::steady_clock::now();
    while (true) {
        auto now = std::chrono::steady_clock::now();
        if (now - startedWorkingAt >= std::chrono::seconds(workingTime)) {
            {
                std::lock_guard<std::mutex> lock(coutMutex);
                std::cout << RED << "\nNo time remains\n\n" << RESET;
            }
            stop = true;
            newOrders.stop();
            readyOrders.stop();
            deliveredOrders.stop();
            break;
        }
    }

    wt1.join();
    wt2.join();
    ct1.join();
    ct2.join();
    ct3.join();
    dt1.join();
    dt2.join();

    Statistics statistic(newOrders, readyOrders, deliveredOrders);
    std::cout << statistic;
    return 0;
}