Radiator Springs Garage 🚗🏁

A C++ Object-Oriented Programming project that simulates a garage management system for racing cars and support vehicles.
The program allows users to manage cars, update information, search, generate reports, and save data using file handling.

📌 Project Description

Radiator Springs Garage is a console-based application built using C++.
It manages different types of cars inside a garage:

- Racer Cars
- Support Vehicles

The project demonstrates the main concepts of Object-Oriented Programming (OOP) such as inheritance, polymorphism, encapsulation, and abstraction.

---

✨ Features

🚘 Car Management

- Add a new car to the garage.
- View all cars stored in the garage.
- Search for a car by:
  - Car number
  - Full name
- Update existing car information.
- Remove a car from the garage.

📊 Garage Report

The program generates statistics including:

- Total number of cars.
- Average performance score.
- Number of racers.
- Number of support vehicles.

💾 Data Storage

- Car information is saved automatically in "garage.txt".
- Data is loaded when the program starts.
- File handling is implemented using C++ streams.

---

🏎️ Car Types

Racer

Contains additional information:

- Number of completed races.
- Number of completed laps.

Performance calculation:

Performance = Speed × 10 + Capacity

---

Support Vehicle

Contains additional information:

- Crew size.
- Reliability rating.

Performance calculation:

Performance = (Speed × 5) + (Capacity × 5)

---

🧠 Object-Oriented Programming Concepts Used

Encapsulation

- Car attributes are private.
- Access is provided using setters and getters.

Inheritance

- "Racer" and "SupportVehicle" inherit from the base class "Car".

Polymorphism

Virtual functions are used:

- "calculatePerformance()"
- "displayInfo()"
- "update()"
- "saveToFile()"

Each derived class provides its own implementation.

Abstraction

The "Car" class is an abstract class containing pure virtual functions.

---

🛠️ Technologies Used

- C++
- Object-Oriented Programming (OOP)
- File Handling
- Vectors
- Dynamic Memory Allocation

---

▶️ How to Run

1. Clone the repository:

git clone https://github.com/habibasalama108/Radiator_Springs_Garage.git

2. Open the project in a C++ IDE such as:

- Visual Studio Code
- Code::Blocks
- Visual Studio

3. Compile the program:

g++ main.cpp -o garage

4. Run:

./garage

---

📂 Project Files

Radiator_Springs_Garage
│
├── main.cpp        # Main C++ source code
├── garage.txt      # Saved garage data
└── README.md       # Project documentation

---

👩‍💻 Author

Habiba Salama