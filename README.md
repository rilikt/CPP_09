# 💹 C++ Module 09 – STL Containers & Algorithmic Sorting

This final module of the C++ series focuses on building efficient algorithms using **STL containers** and understanding performance tradeoffs. It challenged me to apply advanced data structures, sort thousands of inputs, and design custom parsing logic. By far the most demanding module, both in logic and execution.

---

## 📁 Exercises Overview

### 💰 ex00 – Bitcoin Exchange

- Program: `btc`
- Reads Bitcoin prices from a CSV history and applies them to user inputs.
- Input format: `date | value`
- Uses the closest available date if the exact one is missing.
- Handles:
  - Invalid dates
  - Negative or overly large values
  - File parsing errors

Example:
```bash
$ ./btc input.txt
2011-01-03 => 3 = 0.9
2012-01-11 => 1 = 7.1
Error: too large a number.
Error: bad input => 2001-42-42
```

---

### ➗ ex01 – Reverse Polish Notation (RPN)

- Program: `RPN`
- Evaluates RPN math expressions passed as a single command-line string.
- Supports: `+`, `-`, `*`, `/`
- Validates input and prints errors to stderr.

Example:
```bash
$ ./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
42
$ ./RPN "(1 + 1)"
Error
```

---

### 🧮 ex02 – PmergeMe

- Program: `PmergeMe`
- Implements the **Ford-Johnson (merge-insertion) sort algorithm**.
- Sorts a list of positive integers passed as arguments.
- Uses **two STL containers** to compare performance (e.g. `vector` vs `deque`).
- Must sort at least 3000 elements efficiently.
- Displays:
  - Original sequence
  - Sorted sequence
  - Time taken for each container

Example:
```bash
$ ./PmergeMe 3 5 9 7 4
Before: 3 5 9 7 4
After: 3 4 5 7 9
Time to process a range of 5 elements with std::vector : 0.00031 us
Time to process a range of 5 elements with std::deque  : 0.00014 us
```

---

## 🛠️ Build Instructions

```bash
make
```

Each exercise is located in its own folder: `ex00/`, `ex01/`, `ex02/`

---
