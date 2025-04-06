# 🚚 Truck Route Optimizer – C++ Logistics System

An intelligent C++ application designed to optimize truck delivery routes based on destination data and dynamic capacity management. Built for a logistics company simulation as part of a software testing and algorithm course.

> 🧭 Implements pathfinding logic with data structures and custom resizing logic to assign deliveries efficiently.

---

## 🔍 Project Overview

This program simulates a delivery logistics scenario where trucks are dynamically assigned optimized delivery routes. It supports:

- 📦 Flexible truck capacity allocation
- 🧠 Shortest route calculations based on location data
- 🚫 Blocked route handling (rerouting logic)
- 🧪 Built-in software testing (black-box and white-box)

---

## 🧠 Key Features

- Dynamic truck assignment based on delivery load
- Efficient sorting and distribution of delivery addresses
- Built-in test cases for reliability and validation
- Easy-to-read console output for debugging and visual tracking

---

## 🛠️ Tech Stack

- 💻 C++
- 🔁 Custom Data Structures (Linked Lists, Queues)
- 🧪 Unit & integration testing frameworks
- 🧭 Algorithmic path optimization (custom)

---

## 📁 Files Included

- `main.cpp` – Entry point of the program
- `truck.h` / `truck.cpp` – Truck capacity and routing logic
- `delivery.h` / `delivery.cpp` – Address data handling
- `tests/` – Test scripts for key logic
- `README.md` – Documentation

---

## ✅ Sample Output

Truck #1 assigned to 3 deliveries 

Shortest optimized path: Warehouse ➝ Stop A ➝ Stop C ➝ Stop D Remaining capacity: 2 units

Truck #2 assigned to 2 deliveries Blocked path detected.

 Rerouting... New path: Warehouse ➝ Stop B ➝ Stop E

---

## 📦 How To Run

```bash
g++ main.cpp truck.cpp delivery.cpp -o truckRoute
./truckRoute
