# C++ Module 08

## 📝 Overview

This module is designed to help you understand Templated containers, iterators, and algorithms in C++.

**Key Concepts:**

- STL Containers (`vector`, `list`, `map`, `stack`, `deque`...).
- Iterators.
- Algorithms (`std::for_each`, `std::start`, `std::end`...).

## 📂 Exercises

### [Exercise 00: Easy find](./ex00/)

**Goal:** Introduction to algorithms.

> Write a function template `easyfind` that accepts a type `T`.
> It takes the first argument of type `T` and the second argument is an integer.
> `T` is a container of integers.
> It should find the first occurrence of the integer in the container.

### [Exercise 01: Span](./ex01/)

**Goal:** More complex container usage.

> Create a class `Span` that can store a maximum of N integers.
> `shortestSpan()`: Shortest distance between all stored numbers.
> `longestSpan()`: Longest distance between all stored numbers.
> Ability to add ranges of iterators.

### [Exercise 02: Mutated Abomination](./ex02/)

**Goal:** Modifying STL containers.

> The `std::stack` container is not iterable.
> Create a `MutantStack` class that inherits from `std::stack` but offers iterators.
> It should have `begin()`, `end()`, etc. similar to `std::list`.

## 🛠️ Usage

```bash
cd exXX/
make
./program
```
