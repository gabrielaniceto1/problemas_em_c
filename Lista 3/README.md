## Lista 3

This folder moves further into problems that require more structured reasoning, combining **sorting rules, simulations, dynamic memory usage, structs, and hash table concepts**.

Compared to the previous lists, `Lista 3` puts more emphasis on **data organization**, **custom ordering criteria**, **state transitions**, and **intermediate-level implementation details in C**.

It is especially useful for strengthening problem solving when the challenge depends not only on reading input correctly, but also on modeling the data in a way that makes processing and output easier.

---

### 1. Bad Vibes Report (`beecrowd 2958`)

**Description:**  
Reads a matrix of problems, where each cell contains a criticality level and a type (`V` for life problems, `D` for discipline problems). The output must list all life problems first and then discipline problems, both ordered by criticality.

#### What this problem covers
- matrix flattening;
- string storage;
- category separation;
- custom sorting;
- dynamic memory allocation.

#### What it is used for
This problem is useful for practicing how to reorganize sparse data into a more readable report format using explicit ordering rules.

#### What it strengthens
- data grouping;
- sorting by priority;
- handling dynamically allocated strings;
- separating logic by category;
- transforming matrix data into linear reports.

#### Difficulty
**Medium**

The challenge is less about advanced algorithms and more about correctly modeling the input, separating categories, and sorting them according to the required priority rules.

#### Complexity
- **Time:** `O((n*m)²)` in this implementation
- **Space:** `O(n*m)`

> The current solution separates the entries into two groups and sorts each one with a quadratic approach.

---

### 2. The Clover Bride (`beecrowd 3149`)

**Description:**  
Given a time window around midnight and several reported sightings, this problem filters the valid reports and prints the names of the residents whose sightings happened close enough to midnight, ordered by time.

#### What this problem covers
- time conversion;
- interval filtering;
- struct usage;
- stable ordering logic;
- handling special cases around midnight.

#### What it is used for
This problem is useful for learning how to convert formatted time into comparable numeric values and how to sort records while respecting both primary and secondary ordering criteria.

#### What it strengthens
- struct-based organization;
- time normalization;
- sorting records;
- handling boundary values;
- preserving input order for ties.

#### Difficulty
**Medium**

The main difficulty comes from the interpretation of time near midnight and from maintaining the correct order when two valid sightings happen at the same time.

#### Complexity
- **Time:** `O(q²)` in this implementation
- **Space:** `O(q)`

> Here, `q` is the number of reports. The filtering is linear, while the ordering is done with a quadratic sorting approach.

---

### 3. Billiards Triangle (`beecrowd 2466`)

**Description:**  
Given the colors of the first row of billiard balls, this problem simulates the construction of the next rows until only one ball remains. The final color depends on whether adjacent balls in the previous row have the same or different colors.

#### What this problem covers
- simulation;
- iterative reduction of an array;
- dynamic memory allocation;
- repeated transformation of states.

#### What it is used for
This problem is useful for practicing direct simulation, where each iteration builds a smaller version of the current state until a final result is reached.

#### What it strengthens
- simulation thinking;
- array transformation;
- dynamic allocation and deallocation;
- understanding recursive-like processes through iteration.

#### Difficulty
**Easy to Medium**

The rule itself is simple, but the problem is a good exercise in repeated state reduction and careful memory handling.

#### Complexity
- **Time:** `O(n²)`
- **Space:** `O(n)`

> Since each new row is one element smaller than the previous one, the total number of operations is quadratic.

---

### 4. Hash Tables (`beecrowd 1256`)

**Description:**  
Simulates the insertion of keys into a hash table using the function `h(x) = x mod M` and collision handling through separate chaining. The program prints the contents of each index in the expected output format.

#### What this problem covers
- hash table fundamentals;
- modulo-based hashing;
- collision handling;
- dynamic memory with `realloc`;
- struct usage for chained storage.

#### What it is used for
This problem is useful for understanding one of the core ideas in data structures: mapping keys into table positions and resolving collisions when multiple values fall into the same bucket.

#### What it strengthens
- hash table reasoning;
- collision treatment by chaining;
- dynamic resizing of arrays;
- structured storage with structs;
- formatted output construction.

#### Difficulty
**Medium**

Even though the hash function is simple, the problem introduces an important data structure concept and requires careful implementation of chained storage.

#### Complexity
- **Time:** `O(C)`
- **Space:** `O(M + C)`

> Here, `M` is the number of base addresses in the table and `C` is the number of inserted keys.

---

## Summary of Lista 3

Overall, `Lista 3` strengthens topics such as:

- custom sorting rules;
- data grouping and reporting;
- time-based filtering;
- simulation of transformations;
- dynamic memory management;
- struct-based modeling;
- introductory hash table concepts.

This makes the folder especially valuable for moving from basic implementation practice toward problems that require more deliberate data organization and stronger control over processing logic in C.

