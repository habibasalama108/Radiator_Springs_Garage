Radiator Springs Garage 🚗🏁

A C++ Object-Oriented Programming project that simulates a garage management system for racing cars and support vehicles.

The program allows users to manage cars, update information, search for cars, generate reports, and save data using file handling.

---

📌 Project Description

Radiator Springs Garage is a console-based application built using C++.

The system manages different types of vehicles inside the garage:

- Racer Cars
- Support Vehicles

This project demonstrates important Object-Oriented Programming concepts such as:

- Encapsulation
- Inheritance
- Polymorphism
- Abstraction

---

✨ Features

🚘 Car Management

- Add new cars to the garage.
- Display all stored cars.
- Search for cars by:
  - Car number
  - Full name
- Update car information.
- Remove cars from the garage.

📊 Garage Report

The program displays:

- Total number of cars.
- Average performance score.
- Number of racers.
- Number of support vehicles.

💾 Data Storage

- Car data is saved in "garage.txt".
- Saved data is loaded automatically when the program starts.
- File handling is implemented using C++ file streams.

---

🏎️ Vehicle Types

Racer

Additional information:

- Races completed.
- Laps completed.

Performance calculation:

Performance = Speed × 10 + Capacity

---

Support Vehicle

Additional information:

- Crew size.
- Reliability rating.

Performance calculation:

Performance = (Speed × 5) + (Capacity × 5)

---

🧠 OOP Concepts Used

Encapsulation

- Data members are declared as private.
- Setters and getters are used to access and modify data.

Inheritance

The derived classes inherit from the base class:

- "Racer"
- "SupportVehicle"

Both inherit from:

- "Car"

Polymorphism

Virtual functions are used to provide different implementations:

- "calculatePerformance()"
- "displayInfo()"
- "update()"
- "saveToFile()"

Abstraction

The "Car" class is an abstract class containing pure virtual functions.

---

🛠️ Technologies Used

- C++
- Object-Oriented Programming (OOP)
- File Handling
- Vector Data Structure
- Dynamic Memory Allocation

---

▶️ How to Run

1. Clone the repository

git clone https://github.com/habibasalama108/Radiator_Springs_Garage.git

2. Compile the program

g++ main.cpp -o garage

3. Run the program

./garage

---

📂 Project Structure

Radiator_Springs_Garage
│
├── main.cpp
├── garage.txt
└── README.md

---

👩‍💻 Author

Habiba Salama