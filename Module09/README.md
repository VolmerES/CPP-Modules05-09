# C++ Module 09

## 📝 Overview

This module is designed to help you understand the STL (Standard Template Library) in depth.

**Key Concepts:**

- STL Containers usage in specific contexts.
- Solving algorithmic problems.

## 📂 Exercises

### [Exercise 00: Bitcoin Exchange](./ex00/)

**Goal:** Data processing and CSV parsing.

> Create a program that outputs the value of a certain amount of bitcoin on a certain date.
> Use a database in CSV format.
> Use `std::map<date, price>` to store the database.
> Handle invalid dates and values.

### [Exercise 01: Reverse Polish Notation](./ex01/)

**Goal:** Stack usage.

> Create a program `RPN` that evaluates a Reverse Polish Notation mathematical expression.
> `My RPN calculator`
> Operands are single digit (0-9).
> Operators: `+`, `-`, `/`, `*`.
> Use `std::stack`.

### [Exercise 02: PmergeMe](./ex02/)

**Goal:** Sorting algorithms and container efficiency.

> Sorting a positive integer sequence.
> Implement the **Ford-Johnson algorithm** (merge-insert sort).
> Use at least two different containers (e.g., `std::vector` and `std::deque` or `std::list`).
> Compare the time complexity and execution time for both containers.
> Handle large datasets (3000 integers).

## 🛠️ Usage

```bash
cd exXX/
make
./program
```
