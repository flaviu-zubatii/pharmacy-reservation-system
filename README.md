<div align="center">

# 💊 Pharmacy Reservation System

**Sistem CLI de gestiune a unei farmacii cu acces pe roluri, dezvoltat în C++.**

[![C++](https://img.shields.io/badge/C++-00599C?style=for-the-badge&logo=cplusplus&logoColor=white)](https://isocpp.org)

</div>

---

A command-line application developed in **C++** for managing pharmacy products and reservations, featuring role-based access and modular architecture.

---

## 📌 Overview

This project simulates a real-world pharmacy management system where:
- **Administrators** can manage product inventory  
- **Users** can search and reserve products  

The application is designed with a strong focus on **object-oriented programming**, **modularity**, and **data persistence**.

---

## ⚙️ Features

### 👤 User Functionality
- View available products  
- Search products by name  
- Reserve products  
- View current reservations  

### 🛠 Administrator Functionality
- Add new products  
- Remove existing products  
- Search products  
- Manage reservations  

### 💾 Data Persistence
- Stores products and reservations in **CSV files**
- Ensures data is preserved between program runs  

---

## 🧠 Architecture & Design

- Object-Oriented Design using classes:
  - `Product`
  - `Reservation`
  - `User`
  - `Administrator`

- Generic data management:
  - Implemented a reusable `Repository<T>` class using **templates**

- Modular structure:
  - Separation of concerns between user/admin logic and data handling  
  - Independent CLI entry points:
    - `main_user.cpp`
    - `main_admin.cpp`

---

## 🛠 Tech Stack

- **Language:** C++  
- **Concepts:**  
  - Object-Oriented Programming (OOP)  
  - Generic Programming (Templates)  
  - File Handling (CSV)  
  - Modular Design  

---

## 🚀 How to Run

### Compile:
```bash
g++ main_admin.cpp -o admin
g++ main_user.cpp -o user
```

### Run:
```bash
./admin    # Admin panel
./user     # User panel
```

---

## 👤 Autor

**Zubatîi Flaviu** — Universitatea de Vest din Timișoara
