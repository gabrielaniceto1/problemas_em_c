# PROBLEMAS_EM_C

A repository focused on **study, practice, and growth in C programming**, bringing together problems of different difficulty levels, classical algorithms, more advanced challenges, and code experiments.

The purpose of this project is not only to store solutions, but also to serve as a **study progress map**, covering everything from language fundamentals to more demanding topics such as **time and space optimization**, **sorting algorithms**, **problem solving**, **threads**, and various implementation tests.

Here you will find exercises that help strengthen skills such as:

- programming logic;
- memory and data structure manipulation in C;
- complexity analysis;
- algorithmic thinking;
- problem solving under time and space constraints;
- solution organization and practical experimentation.

Throughout this repository, the problems and implementations are organized with focus on:

- **covered content**;
- **study purpose**;
- **skills strengthened**;
- **difficulty level**, considering not only what the problem does, but also how demanding it is in terms of computational efficiency.

---

## Index

### Exercise Lists
- [List 1](#lista-1)
- [List 2](#lista-2)
- [List 3](#lista-3)
- [List 4](#lista-4)
- [List 5](#lista-5)
- [List 6](#lista-6)
- [List 7](#lista-7)
- [List 8](#lista-8)
- [List 9](#lista-9)
- [List 10](#lista-10)

### Specific Content
- [List Sort](#lista-sort) — sorting algorithms and variations
- [Desafios](#desafios) — more challenging problems, including more advanced solutions
- [Infra de Software](#infra-de-software) — problems and experiments involving threads and concurrency
- [C_random](#c_random) — test code, experiments, and miscellaneous implementations

---

## Repository Organization

This repository is divided into folders with different purposes:

- **Lista 1 to Lista 10** contain a variety of C exercises covering different topics and difficulty levels.
- **Lista Sort** gathers sorting algorithms, useful for studying performance, comparing approaches, and understanding complexity.
- The **Desafios** folder contains harder problems, requiring a stronger command of logic, data structures, and efficiency.
- The **Infra de Software** folder focuses on topics closer to systems and concurrency, especially involving threads.
- The **C_random** folder works as a space for tests, drafts, and practical experiments in C.

---

## Goal

To build a solid foundation in C through continuous practice, documenting solutions and studies that help develop not only the ability to code, but also to **analyze, optimize, and justify algorithmic choices**.

## Lista 1

**Folder:** `Lista 1/`

This folder contains introductory and intermediate C problems focused on logic building, matrix manipulation, mathematical reasoning, simulation, and basic algorithm analysis.

It helps strengthen core problem-solving skills while building a solid foundation in reading input, processing constraints, and implementing correct solutions in C.

---

### 1. Engine Failure (`beecrowd 2167`)

**Description:**  
Finds the first position in a sequence of engine RPM measurements where the value becomes smaller than the previous one.

#### What this problem covers
- array input;
- sequential scanning;
- comparison between adjacent elements;
- early stopping when the first valid condition is found.

#### What it is used for
This problem is useful for practicing how to analyze a sequence and detect the first occurrence of a pattern change.

#### What it strengthens
- basic array manipulation;
- loop control;
- condition checking;
- understanding of linear scan problems.

#### Difficulty
**Easy**

Although simple in logic, it is a good exercise for learning how to process ordered input and identify the first relevant event efficiently.

#### Complexity
- **Time:** `O(n)`
- **Space:** `O(n)` in this implementation

> Note: this problem can also be solved with `O(1)` extra space by storing only the previous RPM value instead of the whole array.

---

### 2. Above the Main Diagonal (`beecrowd 1183`)

**Description:**  
Reads a `12 x 12` matrix and performs either a sum or an average using only the elements above the main diagonal.

#### What this problem covers
- matrix input;
- traversal of two-dimensional arrays;
- main diagonal logic;
- conditional accumulation;
- average calculation.

#### What it is used for
This problem is useful for understanding how matrix regions work and how to select elements based on row and column relationships.

#### What it strengthens
- matrix reasoning;
- nested loop usage;
- coordinate-based filtering;
- basic numerical processing.

#### Difficulty
**Easy**

The main challenge is correctly understanding which elements are above the main diagonal and applying the requested operation.

#### Complexity
- **Time:** `O(12²)` → effectively constant
- **Space:** `O(12²)` in this implementation

> Note: since the matrix size is fixed, this is constant in practice. It could also be implemented with less memory if the values were processed on the fly.

---

### 3. Pythagorean Triple (`beecrowd 1582`)

**Description:**  
Checks whether three integers form a Pythagorean triple and, if they do, determines whether the triple is primitive.

#### What this problem covers
- mathematical validation;
- identification of the hypotenuse;
- greatest common divisor (GCD);
- primitive triple classification;
- repeated test cases until EOF.

#### What it is used for
This problem is useful for combining math with programming logic, especially when classification depends on more than one condition.

#### What it strengthens
- mathematical reasoning in code;
- conditional branching;
- function decomposition;
- Euclidean algorithm usage;
- handling multiple test cases.

#### Difficulty
**Medium**

The logic is still manageable, but the problem requires more structure than a simple direct check, especially because it combines triangle validation with primitive triple verification.

#### Complexity
- **Time:** `O(log(min(a, b, c)))` for the GCD part, per test case
- **Space:** `O(1)`

---

### 4. Counting / Clapping Game

**Description:**  
Simulates a counting game in which people speak numbers back and forth in a line. A clap happens whenever the current number is divisible by `7` or contains the digit `7`. The goal is to find the real number being counted when the `m`-th person claps for the `k`-th time.

#### What this problem covers
- simulation;
- directional movement in a sequence;
- pattern-based event detection;
- digit inspection;
- repeated state updates.

#### What it is used for
This problem is useful for practicing full process simulation, where the answer is not obtained by a direct formula but by carefully reproducing the behavior of the game.

#### What it strengthens
- simulation logic;
- state tracking;
- handling alternating movement;
- pattern detection in numbers;
- patience with implementation details.

#### Difficulty
**Medium to Hard**

The main difficulty is not advanced syntax, but correctly modeling the game rules, the change of direction, and the clap condition while keeping the simulation consistent.

#### Complexity
- **Time:** depends on how far the simulation must go until the target clap is reached
- **Space:** `O(1)` logically, with small auxiliary storage in this implementation

> This kind of problem is more demanding in implementation logic than in pure mathematical complexity.

---

## Summary of Lista 1

Overall, `Lista 1` helps build important skills such as:

- sequential reasoning;
- matrix traversal;
- mathematical validation;
- simulation-based problem solving;
- basic complexity awareness.

It is a strong starting point for improving in C, especially for competitive-style exercises and logic-focused programming practice.

