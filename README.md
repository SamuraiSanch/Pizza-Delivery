# 🍕 Pizza Delivery Simulator

A multithreaded pizza restaurant simulation in C++ using `std::thread`, `std::mutex`, and `std::condition_variable`.

## 📋 Description

The program simulates a pizza restaurant with multiple roles working in parallel:
- **Waiters** — receive orders from customers
- **Chefs** — cook pizzas
- **Delivery Drivers** — deliver finished pizzas

All processes are synchronized through queues and condition variables.

## 🎯 Features

- ✅ 7+ parallel threads (2 waiters, 3 chefs, 2 delivery drivers)
- ✅ Synchronization via `std::condition_variable`
- ✅ Thread-safe queues with `std::mutex`
- ✅ Atomic order counter (`std::atomic`)
- ✅ Time measurement with `std::chrono`
- ✅ Detailed statistics after shutdown
- ✅ Colored terminal output (ANSI codes)

## 🛠️ Technologies

- **C++11/14** (thread, mutex, condition_variable, atomic, chrono)
- **ANSI Escape Codes** for colored output
- **Producer-Consumer Pattern** for queues

## 📊 Statistics

After completion, the program displays:
- Number of received/cooked/delivered orders
- Average cooking and delivery time
- Productivity of each chef
- Popularity of pizza types

## 🚀 How to Run

### Compilation (Visual Studio):
Open the project in Visual Studio and press `F5` (Run).

## 📸 Screenshots

![Demo](screenshots/demo1.png)
![Demo](screenshots/demo2.png)

## 📂 Project Structure
```
pizza-restaurant/
├── manager.cpp           # Main file
├── Order.h               # Order structure
├── OrderQueue.h/cpp      # Thread-safe queue
├── Waiter.h/cpp          # Waiters
├── Chef.h/cpp            # Chefs
├── Delivery.h/cpp        # Delivery drivers
├── Statistics.h/cpp      # Statistics collection
├── Colors.h              # ANSI codes for colors
├── README.md             # Documentation
└── screenshots/
    └── demo1.png/demo2.png  # Screenshots
```

## 🎓 What I Learned / Why This Program Is Useful

- Working with `std::thread` and thread lifecycle management
- Synchronization using `std::mutex` and `std::condition_variable`
- Avoiding race conditions and deadlocks
- Producer-Consumer pattern implementation
- Using `std::atomic` for thread-safe operations
- Time measurement with `std::chrono`

## 📝 License

MIT License — free to use and modify.

## 👤 Author

Oleksandr Kopii — [https://github.com/SamuraiSanch](https://github.com/SamuraiSanch)