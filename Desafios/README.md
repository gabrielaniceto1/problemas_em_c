## Desafios

This folder is dedicated to **harder algorithmic problems**, especially challenges that require stronger optimization, deeper pattern recognition, and more advanced data structure or recursion techniques.

Compared to the numbered lists, this section is much more focused on **interview-style and competitive-style problems**, where writing a correct solution is not enough — the solution also needs to be efficient in terms of **time and space complexity**.

It is especially useful for improving performance-oriented problem solving in C and for practicing classic high-value patterns such as:

- two pointers;
- hash-based lookup;
- DFS / flood fill;
- backtracking;
- linked structures with fast access;
- digit-based counting techniques.

---

### 1. Container With Most Water

**Description:**  
Given an array of heights, finds the maximum amount of water that can be contained between two vertical lines using a two-pointer strategy.

#### What this problem covers
- two pointers;
- greedy movement;
- area maximization;
- linear-time optimization.

#### What it is used for
This problem is useful for learning how a brute-force quadratic solution can be improved into a linear-time solution by exploiting structural properties of the problem.

#### What it strengthens
- two-pointer reasoning;
- optimization from `O(n²)` to `O(n)`;
- geometric intuition in arrays;
- decision-making based on limiting values.

#### Difficulty
**Medium**

The main challenge is realizing why moving the shorter pointer is the only useful choice.

#### Complexity
- **Time:** `O(n)`
- **Space:** `O(1)`

---

### 2. Number of Digit One

**Description:**  
Counts how many times the digit `1` appears in all numbers from `0` to `n`, using positional digit analysis instead of direct iteration.

#### What this problem covers
- digit-based counting;
- place-value analysis;
- mathematical decomposition of numbers;
- optimized counting over large ranges.

#### What it is used for
This problem is useful for understanding how some counting problems can be solved mathematically without enumerating every number.

#### What it strengthens
- number decomposition;
- pattern recognition in decimal positions;
- replacing brute force with formula-based reasoning;
- logarithmic-time problem solving.

#### Difficulty
**Hard**

The implementation is short, but the logic behind it is subtle and requires strong understanding of how digits behave across ranges.

#### Complexity
- **Time:** `O(log n)`
- **Space:** `O(1)`

---

### 3. Number of Islands

**Description:**  
Given a grid of `'1'` and `'0'`, counts how many connected islands exist by using recursive DFS to mark visited land.

#### What this problem covers
- depth-first search;
- grid traversal;
- flood fill;
- connected components;
- recursive marking of visited cells.

#### What it is used for
This problem is useful for practicing graph traversal ideas in matrix form, where each land cell belongs to a connected region.

#### What it strengthens
- recursive exploration;
- grid-based problem solving;
- mutation of state to avoid revisits;
- recognition of connected-component patterns.

#### Difficulty
**Medium**

The traversal itself is manageable, but the key idea is recognizing that each island should be fully explored and marked once.

#### Complexity
- **Time:** `O(rows * cols)`
- **Space:** `O(rows * cols)` worst case due to recursion stack

> The algorithm visits each cell at most once.

---

### 4. LRU Cache

**Description:**  
Implements an **LRU (Least Recently Used) Cache** using a doubly linked list and direct-access map storage, supporting `get` and `put` operations while maintaining recent usage order.

#### What this problem covers
- cache design;
- doubly linked lists;
- hash/direct-access table;
- node movement in constant time;
- eviction policy management.

#### What it is used for
This problem is useful for studying one of the most classic interview-level data structure designs, where both lookup speed and update speed must be efficient.

#### What it strengthens
- combining two data structures in one solution;
- constant-time updates;
- eviction logic;
- recency tracking.

#### Difficulty
**Hard**

This is one of the most important data structure design challenges because it requires both structural correctness and efficient operations.

#### Complexity
- **Get:** `O(1)`
- **Put:** `O(1)`
- **Space:** `O(capacity)` plus map support

> The key idea is that the map gives direct access to nodes, while the doubly linked list maintains usage order.

---

### 5. Sudoku Solver

**Description:**  
Solves a `9x9` Sudoku board using backtracking, trying valid digits recursively until the board is completed.

#### What this problem covers
- backtracking;
- constraint checking;
- recursive search;
- pruning invalid states;
- board validation.

#### What it is used for
This problem is useful for learning one of the most important recursive search paradigms: exploring possibilities, undoing choices, and backtracking when a path fails.

#### What it strengthens
- backtracking logic;
- recursive state exploration;
- constraint-based search;
- careful board mutation and restoration.

#### Difficulty
**Hard**

The core idea is elegant, but backtracking problems require disciplined recursion and strong attention to validity conditions.

#### Complexity
- **Time:** exponential in the worst case
- **Space:** `O(81)` recursion depth bound in practice

> Sudoku solving is highly dependent on pruning, so real performance is much better than naive exhaustive search in many cases.

---

### 6. Two Sum (Hash-Based Pair Search)

**Description:**  
Searches for two values in an array whose sum matches a target, using a hash-style auxiliary array for faster lookup.

#### What this problem covers
- hash-based lookup;
- complement search;
- array preprocessing;
- pair-sum detection.

#### What it is used for
This problem is useful for understanding the common optimization pattern of storing seen values or frequencies to reduce repeated searches.

#### What it strengthens
- complement-based reasoning;
- hashing intuition;
- reduction from nested loops to faster lookup;
- array-based auxiliary storage.

#### Difficulty
**Easy to Medium**

The general problem is classic, but efficient solutions are important because brute-force approaches scale poorly.

#### Complexity
- **Time:** `O(n + k)` in this implementation
- **Space:** `O(k)`

> Here, `k` depends on the maximum value used to size the auxiliary hash array. This version is best suited for non-negative bounded values.

---

## Summary of Desafios

Overall, `Desafios` strengthens topics such as:

- two-pointer optimization;
- mathematical counting;
- DFS and flood fill;
- backtracking;
- cache design;
- hash-based lookup;
- interview-style problem solving;
- time and space optimization under stricter constraints.

This makes the folder especially valuable for practicing problems where the solution must go beyond correctness and show **algorithmic efficiency, pattern recognition, and stronger problem-solving maturity**.