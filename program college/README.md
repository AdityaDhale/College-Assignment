# 🎓 College Programming Portfolio

A comprehensive repository containing college coursework, programming assignments, lab solutions, data structures & algorithms (DSA), and object-oriented projects developed across 1st, 2nd, and 3rd academic years.

---

## 🚀 Technologies & Languages

![C++](https://img.shields.io/badge/C%2B%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![Java](https://img.shields.io/badge/Java-ED8B00?style=for-the-badge&logo=openjdk&logoColor=white)
![Python](https://img.shields.io/badge/Python-3776AB?style=for-the-badge&logo=python&logoColor=white)
![Git](https://img.shields.io/badge/Git-F05032?style=for-the-badge&logo=git&logoColor=white)

---

## 📂 Repository Structure

```micro
program college/
├── 📁 PPS first year/        # Programming for Problem Solving (C++)
├── 📁 dsa second year/       # Data Structures & Algorithms (C++ & Python)
├── 📁 dsa second sem 2/      # Advanced DSA, Trees & Graphs (C++)
└── 📁 java third year/       # Object-Oriented Programming & Systems (Java)
```

---

## 📚 Curriculum & Program Breakdown

### 1️⃣ First Year: Programming for Problem Solving (PPS)
*Focus: Fundamentals of C++, Control Flow, Logic Building, Arrays, Functions, and Basic Games.*

* **Core Programs:** Factorial, Prime Check, Palindrome, Armstrong Number, Salary Calculation, Swap logic, Vowel identification, Array Average.
* **Student Record Management:** `Studentmarks.cpp`
* **Mini-Game:** `TikTakToe.cpp` (Console-based Tic-Tac-Toe game in C++)

---

### 2️⃣ Second Year: Data Structures & Algorithms (DSA - Part 1)
*Focus: Linear Data Structures, Searching, Sorting Algorithms in C++ & Python.*

* **Searching Algorithms:** Linear Search, Sequential Search, Binary Search, Fibonacci Search (`binary_fibonacci_search.py`).
* **Sorting Algorithms:** Bubble Sort, Selection Sort (`selection_bubble_sort.py`), Quick Sort (`quicksort.py`), Bucket Sort (`bucketsort.py`).
* **Linear Data Structures:**
  * Singly & Doubly Linked Lists (`linkedlist.cpp`, `singly_linked_list.cpp`, `book_linkedlist.cpp`)
  * Queues, Circular Queue & Deque (`queue.cpp`, `circular_queue.cpp`, `dequeue.cpp`)
  * Stacks & Applications: Parentheses Matching (`stack_parentesis.cpp`), Undo/Redo mechanism (`undo_redo.cpp`)
* **Mini Applications:** `cricket.py`, `studentmarks.py`

---

### 3️⃣ Second Year (Sem 2): Advanced Data Structures & Algorithms (DSA - Part 2)
*Focus: Non-Linear Data Structures, Trees, Graphs, Hashing, and File Systems in C++.*

* **Trees:**
  * General Tree (`general_tree.cpp`)
  * Binary Search Tree & General Trees (`tree.cpp`)
  * Self-Balancing AVL Tree (`Avl_tree.cpp`)
  * Optimal Binary Search Tree (OBST) (`obst.cpp`)
* **Graph Algorithms:**
  * Breadth-First Search & Depth-First Search (`BFS_DFS.cpp`)
  * Shortest Path: Dijkstra's Algorithm (`dijikstra.cpp`)
  * Minimum Spanning Tree: Prim's Algorithm (`prims_algo.cpp`)
* **Advanced Structures & Utilities:**
  * Abstract Data Types (`ADT.cpp`), Hash Tables (`hashing.cpp`), Priority Queues (`priority_queue.cpp`)
  * Expression Trees & Prefix Evaluation (`prefix.cpp`)
* **Projects / Applications:**
  * `smart_text_editor.cpp` (Text editor simulation using data structures)
  * `file_organiser.cpp` (File management system using trees/DS)

---

### 4️⃣ Third Year: Object-Oriented Programming & Systems (Java)
*Focus: Object-Oriented Design, Encapsulation, Polymorphism, Multi-threading, Streams, and Real-world Management Systems.*

* **System & Management Projects:**
  * 💰 `Personal_Finance_Tracker.java` – Income, expense tracking & financial analysis.
  * 📦 `smart_inventory.java` – Stock & inventory management system.
  * 🏥 `hospital_record.java` – Patient records & hospital administration module.
  * 🚗 `rental_vehicle.java` – Vehicle rental booking & fleet management.
  * 🏷️ `auction.java` – Bidding & online auction system.
  * 🎬 `movierating.java` – Movie review & rating management.
  * 📊 `grade_system.java` & `marks.java` – Academic grade & marks calculation systems.
* **Advanced Java Concepts:**
  * 🧵 `multithread.java` – Java Multi-threading, concurrency, & thread synchronization.
  * ⚡ `stream.java` – Java 8+ Functional Programming, Lambda Expressions & Stream API.

---

## 🛠️ How to Run the Programs

### C++ Programs
Using `g++` compiler:
```bash
# Navigate to the program folder
cd "dsa second sem 2"

# Compile
g++ Avl_tree.cpp -o Avl_tree

# Run
./Avl_tree       # On Linux/macOS
Avl_tree.exe     # On Windows
```

### Python Scripts
Requires Python 3.x:
```bash
cd "dsa second year"
python quicksort.py
```

### Java Programs
Requires JDK 8 or higher:
```bash
cd "java third year"
javac Personal_Finance_Tracker.java
java Personal_Finance_Tracker
```

---

## 💡 What to Exclude (Clean Upload)

This repository includes a `.gitignore` file to ensure binary files (`.exe`, `.out`, `.class`), compiler outputs, and temporary IDE files are excluded from git tracking.

---

## 🤝 Contributing & License

This repository is maintained for educational purposes and academic code reference. Feel free to fork, explore, or use the code snippets for learning.

---
*Created with ❤️ during College Engineering Coursework.*
