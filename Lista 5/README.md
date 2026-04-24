## Lista 5

This folder focuses on classic recursive and mathematical problems, especially those involving **Fibonacci recursion**, **greatest common divisor**, and the **Josephus problem**.

Compared to the previous lists, `Lista 5` places more emphasis on **recursive reasoning**, **mathematical structure**, and understanding how algorithmic choices affect performance, especially in time complexity.

It is especially useful for strengthening the connection between **mathematics and recursion in C**, while also highlighting the cost of naive recursive solutions.

---

### 1. Fibonacci, How Many Calls? (`beecrowd 1029`)

**Description:**  
Computes the Fibonacci value recursively and also counts how many recursive calls are made during the process.

#### What this problem covers
- recursion;
- Fibonacci sequence;
- recursive call counting;
- function parameter passing by pointer;
- performance awareness.

#### What it is used for
This problem is useful for showing how recursive solutions work internally and for illustrating that a correct solution is not always an efficient one.

#### What it strengthens
- recursive reasoning;
- understanding recursion trees;
- pointer usage for shared counters;
- awareness of repeated subproblems;
- time complexity analysis.

#### Difficulty
**Easy to Medium**

The recursive logic is simple, but the educational value of the problem comes from understanding how expensive naive recursion can become.

#### Complexity
- **Time:** `O(2^n)`
- **Space:** `O(n)`

> The time complexity is exponential because the same Fibonacci values are recomputed many times. The space complexity comes from the recursion stack depth.

---

### 2. Stickers (`beecrowd 1028`)

**Description:**  
Given the number of stickers two players have, determines the largest stack size that can divide both collections equally, which is exactly the greatest common divisor of the two values.

#### What this problem covers
- greatest common divisor;
- Euclidean algorithm;
- recursive mathematical functions;
- repeated test case handling.

#### What it is used for
This problem is useful for practicing one of the most important classical algorithms in mathematics and computer science: the Euclidean algorithm for GCD.

#### What it strengthens
- mathematical reasoning;
- recursive implementation;
- understanding divisibility;
- connection between real-world interpretation and mathematical abstraction.

#### Difficulty
**Easy**

Once the problem is interpreted correctly, the solution becomes a direct application of the GCD concept.

#### Complexity
- **Time:** `O(log(min(a, b)))`
- **Space:** `O(log(min(a, b)))` in this recursive implementation

> The Euclidean algorithm is highly efficient, and the recursive depth is logarithmic in the size of the smaller input.

---

### 3. The Legend of Flavious Josephus (`beecrowd 1030`)

**Description:**  
Solves the Josephus problem: given `n` people arranged in a circle and a step size `k`, determines which person survives after repeated eliminations.

#### What this problem covers
- recursion;
- recurrence relations;
- circular elimination logic;
- mathematical indexing;
- zero-based to one-based conversion.

#### What it is used for
This problem is useful for learning how a complex elimination process can be reduced to a compact recursive formula.

#### What it strengthens
- recurrence-based thinking;
- recursive problem reduction;
- modular arithmetic intuition;
- understanding indexing transformations.

#### Difficulty
**Medium**

The implementation is short, but the real challenge is understanding why the recurrence works and how the circular structure is encoded mathematically.

#### Complexity
- **Time:** `O(n)`
- **Space:** `O(n)` in this recursive implementation

> Each recursive call reduces the problem by one person, and the recursion stack grows linearly with `n`.

---

## Summary of Lista 5

Overall, `Lista 5` strengthens topics such as:

- recursion;
- recurrence relations;
- Fibonacci computation;
- greatest common divisor;
- circular elimination problems;
- mathematical modeling in code;
- time complexity awareness.

This makes the folder especially valuable for practicing problems where the key idea is not only to implement the solution, but also to **understand the mathematical structure behind the algorithm**.

