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

