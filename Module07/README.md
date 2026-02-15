# C++ Module 07

## 📝 Overview

This module is designed to help you understand Templates in C++.

**Key Concepts:**

- Function Templates.
- Class Templates.
- Template Specialization (partial/full).

## 📂 Exercises

### [Exercise 00: Start with a few functions](./ex00/)

**Goal:** Function templates.

> Implement template functions:
>
> - `swap`: Swaps the values of two arguments.
> - `min`: Returns the smallest value.
> - `max`: Returns the largest value.

### [Exercise 01: Iter](./ex01/)

**Goal:** More function templates.

> Implement a template function `iter` that takes an array address, its length, and a function to call on each element.

### [Exercise 02: Array](./ex02/)

**Goal:** Class templates.

> Create a class template `Array<T>`.
>
> - Construction with no parameter (empty constraint).
> - Construction with an unsigned int `n` (creates `n` elements initialized by default).
> - Copy construction and assignment (deep copy).
> - Access elements via `operator[]` (throwing `std::exception` if out of bounds).
> - `size()` member function.

## 🛠️ Usage

```bash
cd exXX/
make
./program
```
