# C++ Module 06

## 📝 Overview

This module is designed to help you understand the different types of Casts in C++.

**Key Concepts:**

- Casting: `static_cast`, `dynamic_cast`, `reinterpret_cast`, `const_cast`.
- Serialization (interpreting memory blocks).
- Identifying types at runtime (RTTI).

## 📂 Exercises

### [Exercise 00: Scalar conversion](./ex00/)

**Goal:** Understanding scalar types and casts.

> Create a program `ScalarConverter::convert(std::string literal)`.
> It detects the type of the literal (char, int, float, double).
> It displays the value in all 4 types, handling pseudo-literals (`nan`, `+inf`, `-inf`).

### [Exercise 01: Serialization](./ex01/)

**Goal:** Reinterpreting data.

> Create a structure `Data`.
> Implement `serialize` (Data* -> uintptr_t) and `deserialize` (uintptr_t -> Data*).
> Use `reinterpret_cast`.
> Verify that the pointer is preserved.

### [Exercise 02: Identify real type](./ex02/)

**Goal:** Identify type at runtime.

> Create a base class `Base` and derived classes `A`, `B`, `C`.
> Implement `generate()` to return a random instance.
> Implement `identify(Base* p)` using `dynamic_cast`.
> Implement `identify(Base& p)` using `dynamic_cast` (and catching `std::bad_cast`).

## 🛠️ Usage

```bash
cd exXX/
make
./program
```
