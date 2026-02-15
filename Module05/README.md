# C++ Module 05

## 📝 Overview

This module is designed to help you understand Try/Catch and Exceptions in C++.

**Key Concepts:**

- Exceptions usage
- `try`, `catch`, `throw`
- Creating custom exception classes (`std::exception`)
- Nested classes

## 📂 Exercises

### [Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!](./ex00/)

**Goal:** Basics of exceptions.

> Create a class `Bureaucrat` with a name and a grade (1-150).
> Throw exceptions if the grade is too high or too low.
> Implement increment/decrement methods that can also throw.

### [Exercise 01: Form up, maggots!](./ex01/)

**Goal:** Interactions with exceptions.

> Create a class `Form` that has a name, a boolean signed status, and required grades to sign/execute.
> `Bureaucrat` should have a `signForm()` method.
> Handle exceptions if a Bureaucrat's grade is not high enough.

### [Exercise 02: No, you need form 28B, not 28C...](./ex02/)

**Goal:** Abstract classes and concrete implementations.

> Make `Form` abstract.
> Create concrete forms:
>
> - `ShrubberyCreationForm`: Creates a file with ASCII trees.
> - `RobotomyRequestForm`: 50% chance of drilling noise.
> - `PresidentialPardonForm`: Pardons a target.
>   Implement `execute(Bureaucrat const & executor)` method in forms.

### [Exercise 03: At least this beats coffee-making](./ex03/)

**Goal:** Interns.

> Create an `Intern` class that can create forms.
> The intern has no name or grade.
> Use an array of pointers to member functions or similar logic to create the right form based on a string name.

## 🛠️ Usage

```bash
cd exXX/
make
./program
```
