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

## Lista 2

**Folder:** `Lista 2/`

This folder expands the repository with problems centered on **strings, ASCII processing, validation rules, custom ordering, and text reconstruction**.

Compared to the first list, this set places a stronger emphasis on **character manipulation**, **string comparison**, **input handling with text lines**, and **rule-based problem solving**, which are essential skills in C programming.

It is especially useful for improving accuracy when dealing with textual data, multiple test cases, and output formatting constraints.

---

### 1. Tell Me the Frequencies (`beecrowd 1251`)

**Description:**  
Given a line of text, this problem counts how many times each character appears and prints the ASCII value of each character together with its frequency. The output must be sorted by ascending frequency, and when frequencies are equal, by descending ASCII value.

#### What this problem covers
- frequency counting;
- ASCII table usage;
- string processing;
- custom sorting rules;
- handling multiple test cases until EOF.

#### What it is used for
This problem is useful for practicing character-based counting and learning how to sort data using more than one criterion.

#### What it strengthens
- array-based counting;
- string traversal;
- ASCII reasoning;
- sorting with tie-breaking rules;
- careful output formatting.

#### Difficulty
**Medium**

The counting itself is simple, but the ordering rule makes the problem more interesting, since it requires attention to both frequency and ASCII priority.

#### Complexity
- **Time:** `O(n + u²)`
- **Space:** `O(1)`

> Here, `n` is the line length and `u` is the number of distinct ASCII characters found. Since the ASCII range is bounded, this is effectively linear for practical purposes.

---

### 2. International Chat (`beecrowd 1581`)

**Description:**  
Given the native language of each person in a group, determines which language should be spoken: if everyone has the same native language, that language is used; otherwise, the answer is English.

#### What this problem covers
- string comparison;
- repeated input handling;
- group consistency checking;
- conditional classification.

#### What it is used for
This problem is useful for practicing how to compare multiple strings and decide whether all inputs belong to the same category.

#### What it strengthens
- string manipulation in C;
- `strcmp` and `strcpy` usage;
- case-based reasoning;
- handling multiple test groups.

#### Difficulty
**Easy**

The core logic is direct: check whether all languages are the same or not.

#### Complexity
- **Time:** `O(k * l)`
- **Space:** `O(1)` auxiliary space, excluding output storage

> Here, `k` is the number of people in the group and `l` is the average string length.

---

### 3. Evergreen's Prank (`beecrowd 2722`)

**Description:**  
Receives two mixed parts of a child's name and reconstructs the correct full name by alternately taking two characters from the first string and two from the second.

#### What this problem covers
- string reconstruction;
- controlled merging of two strings;
- input with spaces;
- use of `fgets`;
- index-based simulation.

#### What it is used for
This problem is useful for practicing custom string merging rules and handling text input that may contain spaces.

#### What it strengthens
- string indexing;
- text input handling;
- reconstruction logic;
- careful character-by-character processing.

#### Difficulty
**Medium**

The challenge is not advanced mathematics or optimization, but correctly applying the reconstruction rule while handling different string lengths.

#### Complexity
- **Time:** `O(n + m)`
- **Space:** `O(n + m)`

> Here, `n` and `m` are the lengths of the two input strings.

---

### 4. Password Validator (`beecrowd 2253`)

**Description:**  
Checks whether a password is valid based on the following rules: it must contain at least one uppercase letter, one lowercase letter, and one digit; it must not contain spaces, punctuation, or accented characters; and its length must be between 6 and 32 characters.

#### What this problem covers
- string validation;
- ASCII-based character classification;
- multiple condition checking;
- input until EOF.

#### What it is used for
This problem is useful for practicing practical validation logic, which is very common in real systems such as login and registration forms.

#### What it strengthens
- string traversal;
- validation rules implementation;
- character classification;
- defensive programming logic.

#### Difficulty
**Easy to Medium**

The logic is straightforward, but the problem is a good exercise in combining several validation rules in a clean and consistent way.

#### Complexity
- **Time:** `O(n)`
- **Space:** `O(1)`

> The algorithm scans the password once and uses only a few counters and flags.

---

## Summary of Lista 2

Overall, `Lista 2` strengthens important topics such as:

- string manipulation;
- ASCII-based reasoning;
- custom sorting rules;
- input handling with full text lines;
- reconstruction of textual patterns;
- validation logic.

This makes the folder especially valuable for improving problem solving in C when the challenge depends more on **careful text processing and rule interpretation** than on heavy mathematical computation.

## Lista 3

**Folder:** `Lista 3/`

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

## Lista 4

**Folder:** `Lista 4/`

This folder focuses strongly on **ordering, name organization, linked list insertion, ranking rules, and record selection**.

Compared to the previous lists, `Lista 4` emphasizes problems where the main challenge is to **keep data sorted while it is being inserted**, apply **selection criteria**, and produce output according to specific ranking or alphabetical rules.

It is especially useful for improving the ability to model real-world scenarios using **strings**, **linked lists**, and **ordered data processing** in C.

---

### 1. Habay's Friends (`beecrowd 2136`)

**Description:**  
Processes party registrations where each participant chooses `YES` or `NO` for becoming “Habay's Friend.” The final list must be printed grouped by choice and alphabetically ordered, and the winner is selected among the `YES` group by the longest name, with ties broken by earliest registration.

#### What this problem covers
- linked list insertion in sorted order;
- alphabetical ordering;
- duplicate-sensitive registration handling;
- grouping by category;
- winner selection with tie-breaking rules.

#### What it is used for
This problem is useful for practicing how to maintain ordered collections while also applying an additional selection rule over the stored records.

#### What it strengthens
- linked list manipulation;
- string comparison;
- grouped output formatting;
- tie-breaking logic;
- record traversal and selection.

#### Difficulty
**Medium**

The main difficulty is combining multiple requirements at once: alphabetical organization, separation by response type, and winner selection based on name length and registration order.

#### Complexity
- **Time:** `O(n²)` in this implementation
- **Space:** `O(n)`

> Since elements are inserted into sorted linked lists, each insertion may require traversal, leading to quadratic behavior in the worst case.

---

### 2. Sorting Santa's Children List (`beecrowd 2479`)

**Description:**  
Reads the names of children together with a `+` or `-` sign indicating whether they behaved well or not, prints all names in alphabetical order, and then reports the totals of well-behaved and misbehaved children.

#### What this problem covers
- alphabetical ordering;
- linked list sorted insertion;
- counting categories;
- string storage and traversal;
- formatted summary output.

#### What it is used for
This problem is useful for practicing sorted data storage while simultaneously collecting statistics about the input.

#### What it strengthens
- linked list insertion logic;
- counting while reading input;
- alphabetic organization of strings;
- combined processing and reporting.

#### Difficulty
**Easy to Medium**

The logic is straightforward, but it is a good exercise in integrating sorting and counting into a single solution.

#### Complexity
- **Time:** `O(n²)` in this implementation
- **Space:** `O(n)`

> The counting is linear, but maintaining the linked list in sorted order makes the full process quadratic in the worst case.

---

### 3. Attendance List (`beecrowd 2381`)

**Description:**  
Given a set of student names and a number `K`, orders the names alphabetically and prints the `K`-th student in that ordering.

#### What this problem covers
- alphabetical ordering;
- linked list sorted insertion;
- position-based retrieval;
- string comparison;
- traversal to a target index.

#### What it is used for
This problem is useful for practicing how to store names in sorted order and then retrieve an element based on its rank in the ordered collection.

#### What it strengthens
- ordered insertion;
- linked list traversal;
- ranking logic;
- string handling in C.

#### Difficulty
**Easy**

The problem is conceptually simple: sort the names and select the required position.

#### Complexity
- **Time:** `O(n²)` in this implementation
- **Space:** `O(n)`

> The retrieval of the `K`-th name is linear, but the ordered insertion into the linked list dominates the total cost.

---

## Summary of Lista 4

Overall, `Lista 4` strengthens topics such as:

- alphabetical ordering;
- linked list insertion;
- grouped record handling;
- rank-based selection;
- tie-breaking rules;
- summary generation from ordered data.

This makes the folder especially useful for practicing problems where the core challenge is not advanced mathematics, but rather **organizing textual data correctly and efficiently according to multiple rules**.

## Lista 5

**Folder:** `Lista 5/`

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

## Lista 6

**Folder:** `Lista 6/`

This folder is centered on **fundamental linear data structures in C**, especially **queues**, **stacks**, and **linked lists**.

Unlike the previous lists, which are mostly based on competitive programming problems, `Lista 6` is much more focused on **manual implementation of data structures** and on understanding how insertion, removal, traversal, and combination of structures work internally.

It is especially useful for building a stronger foundation in **dynamic memory**, **pointer manipulation**, and **abstract data structure behavior**.

---

### 1. Medical Clinic Queue System

**Description:**  
Implements a queue-based patient management system for a clinic. The program allows the user to register patients, perform appointments in FIFO order, search for a patient by name, and display how many patients have already been served.

#### What this problem covers
- queue implementation with linked lists;
- insertion at the tail;
- removal from the head;
- searching by traversal;
- menu-driven interaction.

#### What it is used for
This exercise is useful for practicing how queues behave in real-world scenarios, especially when the first person to arrive must be the first to be served.

#### What it strengthens
- linked list queue logic;
- head and tail pointer management;
- dynamic memory allocation and deallocation;
- linear search in linked structures;
- practical modeling of service systems.

#### Difficulty
**Medium**

The individual operations are straightforward, but combining them into a complete interactive system requires consistency in memory handling and pointer updates.

#### Complexity
- **Insert patient:** `O(1)`
- **Remove patient:** `O(1)`
- **Search patient by name:** `O(n)`
- **Space:** `O(n)`

> This is a good example of how queues can be implemented efficiently when both head and tail pointers are maintained.

---

### 2. Merging Two Queues into a Single Output Queue

**Description:**  
Reads two sequences of integers and combines them into a single linked queue, alternating elements according to which queue has priority at the beginning.

#### What this problem covers
- queue construction with linked lists;
- merging two input sequences;
- alternating insertion logic;
- conditional ordering rules;
- dynamic node creation.

#### What it is used for
This exercise is useful for practicing controlled merging, where two input sources must be interleaved according to a given policy.

#### What it strengthens
- queue assembly logic;
- pointer updates during append operations;
- reasoning about alternating patterns;
- transformation from arrays into linked structures.

#### Difficulty
**Medium**

The challenge lies in correctly preserving the intended alternation rule while handling different queue sizes and maintaining the linked output structure.

#### Complexity
- **Time:** `O(n + m)`
- **Space:** `O(n + m)`

> Here, `n` and `m` are the sizes of the two original queues.

---

### 3. Concatenating and Interleaving Queues into Stacks

**Description:**  
Builds two queues of names and then creates two stack-based outputs: one by concatenating both queues and another by interleaving them element by element.

#### What this problem covers
- queue insertion;
- stack insertion;
- conversion between linear structures;
- concatenation;
- interleaving logic.

#### What it is used for
This exercise is useful for understanding the differences between queue and stack behavior, especially when data is moved from one structure type into another.

#### What it strengthens
- comparison between FIFO and LIFO structures;
- linked list reuse across abstractions;
- data transformation between structures;
- pointer-based insertion strategies.

#### Difficulty
**Medium**

The core operations are accessible, but the exercise becomes more interesting because it combines multiple data structures in the same program.

#### Complexity
- **Time:** `O(n + m)`
- **Space:** `O(n + m)`

> The solution traverses both queues and creates new stack nodes from their contents.

---

### 4. Basic Stack Operations

**Description:**  
Implements a stack of integers with operations such as insertion, removal, printing the top element, printing the bottom element, and printing elements in alternating positions.

#### What this problem covers
- stack insertion;
- stack removal;
- top access;
- traversal to the bottom;
- filtered traversal.

#### What it is used for
This exercise is useful for learning the essential operations of a stack and for understanding which operations are naturally efficient and which require full traversal.

#### What it strengthens
- LIFO reasoning;
- linked stack implementation;
- dynamic memory usage;
- distinction between constant-time and linear-time operations.

#### Difficulty
**Easy to Medium**

The push and pop operations are simple, but the printing variations help reinforce how the internal structure of a stack affects access patterns.

#### Complexity
- **Push:** `O(1)`
- **Pop:** `O(1)`
- **Print top:** `O(1)`
- **Print bottom:** `O(n)`
- **Print alternating elements:** `O(n)`
- **Space:** `O(n)`

> This exercise is useful for showing that a stack is optimized for access at the top, while deeper access usually requires traversal.

---

## Summary of Lista 6

Overall, `Lista 6` strengthens topics such as:

- queue implementation;
- stack implementation;
- linked list manipulation;
- dynamic memory management;
- head and tail pointer control;
- structural transformations between queues and stacks;
- practical data structure modeling.

This makes the folder especially valuable for building a strong foundation in **data structures in C**, since it shifts the focus from solving isolated problems to **implementing the structures themselves and understanding how they behave internally**.

