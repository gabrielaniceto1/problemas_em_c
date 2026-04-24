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

## Lista 7

**Folder:** `Lista 7/`

This folder continues the practice with **stacks, queues, linked lists, string parsing, and ordering rules**, but with a stronger focus on **sequence transformation** and **text processing**.

Compared to `Lista 6`, which is more centered on implementing classic queue and stack operations, `Lista 7` uses these same structures in more problem-oriented scenarios, where the challenge is to simulate behavior, remove duplicates, sort strings, and organize grouped data.

It is especially useful for strengthening the ability to use data structures as tools for solving higher-level problems.

---

### 1. Sequence Reordering with a Stack

**Description:**  
Given an input sequence of characters and a desired target sequence, this program determines whether the target can be obtained using a stack. It records the required operations: insertion into the stack (`I`) and removal from the stack (`R`). If the transformation is not possible, it reports it as impossible.

#### What this problem covers
- stack simulation;
- sequence transformation;
- push and pop operations;
- validation of reorderability;
- operation trace generation.

#### What it is used for
This exercise is useful for understanding how stacks constrain element ordering and how a desired output sequence may or may not be achievable from a given input.

#### What it strengthens
- LIFO reasoning;
- stack-based simulation;
- sequence matching;
- careful control of multiple indices;
- construction of operation logs.

#### Difficulty
**Medium**

The main difficulty is correctly simulating the stack operations while keeping track of both the source sequence and the target sequence.

#### Complexity
- **Time:** `O(n²)` in this implementation
- **Space:** `O(n)`

> The stack operations themselves are efficient, but repeated string concatenation for recording operations can increase the total cost.

---

### 2. Unique Word Extraction and Alphabetical Sorting

**Description:**  
Reads a full line of text, breaks it into words, removes duplicates, sorts the unique words alphabetically, and prints the final ordered list.

#### What this problem covers
- string parsing;
- token extraction;
- duplicate removal;
- linked list storage;
- bubble sort over linked data.

#### What it is used for
This exercise is useful for practicing text processing, especially when input must be split into meaningful units and then reorganized into a clean output.

#### What it strengthens
- manual string tokenization;
- duplicate detection;
- linked list traversal;
- sorting of textual data;
- output formatting.

#### Difficulty
**Medium**

The logic is not mathematically hard, but it requires careful handling of strings, repeated words, insertion into a linked structure, and sorting.

#### Complexity
- **Time:** `O(w²)` in this implementation
- **Space:** `O(w)`

> Here, `w` is the number of distinct extracted words. The duplicate checks and bubble sort make the solution quadratic in the number of stored items.

---

### 3. Grouped Queue Organization and Interleaved Output

**Description:**  
Reads identifiers grouped under category markers and stores them into separate queues. In the end, it prints the elements in an interleaved grouped order, alternating among the maintained category queues.

#### What this problem covers
- queue insertion;
- grouped data separation;
- category-based storage;
- interleaved traversal of multiple queues;
- linked list queue construction.

#### What it is used for
This exercise is useful for practicing how to split input into multiple logical groups and later merge them into a structured final output.

#### What it strengthens
- queue-based organization;
- handling category markers;
- grouped processing logic;
- simultaneous traversal of multiple linked structures.

#### Difficulty
**Medium**

The difficulty comes from correctly routing each input item into the appropriate queue and then producing the final merged output in the required grouped order.

#### Complexity
- **Time:** `O(n)`
- **Space:** `O(n)`

> Each element is inserted once and printed once, making the overall process linear in the number of stored items.

---

## Summary of Lista 7

Overall, `Lista 7` strengthens topics such as:

- stack-based sequence simulation;
- queue grouping and interleaving;
- linked list manipulation;
- duplicate removal;
- alphabetical ordering of words;
- transformation of raw input into structured output.

This makes the folder especially useful for practicing how **classic data structures support real problem-solving tasks**, especially in cases involving **text, ordering, and controlled sequence transformations**.

## Lista 8

**Folder:** `Lista 8/`

This folder deepens the study of **linked lists** and expands into **sorting algorithms**, especially through implementations of **doubly linked lists**, **circular linked lists**, **Merge Sort**, and **Quick Sort**.

Compared to the previous lists, `Lista 8` is more focused on **structural variations of linked lists** and on understanding how classic sorting algorithms behave internally.

It is especially useful for strengthening both **pointer-based data structure manipulation** and **divide-and-conquer sorting logic** in C.

---

### 1. Ordered Insertion and Interleaving in a Doubly Linked List

**Description:**  
Implements a doubly linked list with ordered insertion, interleaving of two lists into a third list, and a traversal-based function to count previous and next nodes relative to a given value.

#### What this problem covers
- doubly linked list insertion;
- maintenance of `next` and `prev` pointers;
- ordered insertion;
- list interleaving;
- bidirectional traversal.

#### What it is used for
This exercise is useful for learning how doubly linked lists differ from singly linked lists, especially when insertions and navigation in both directions are needed.

#### What it strengthens
- bidirectional pointer reasoning;
- ordered insertion logic;
- manipulation of multiple linked lists;
- structural traversal from both directions.

#### Difficulty
**Medium**

The main challenge is maintaining pointer consistency while inserting nodes in order and building an interleaved structure correctly.

#### Complexity
- **Ordered insertion:** `O(n)`
- **Interleaving two lists:** `O(n + m)`
- **Space:** `O(n + m)`

---

### 2. Circular Singly Linked List Operations

**Description:**  
Implements a circular singly linked list with insertion at the beginning and at the end, size calculation, traversal printing, and removal from both ends.

#### What this problem covers
- circular linked lists;
- insertion at head and tail;
- deletion at head and tail;
- traversal with circular stopping conditions;
- size calculation.

#### What it is used for
This exercise is useful for understanding how circular structures work and how they differ from linear linked lists, especially in traversal and boundary handling.

#### What it strengthens
- circular list reasoning;
- head-tail synchronization;
- edge case handling with one-node lists;
- loop-based traversal conditions.

#### Difficulty
**Medium**

The operations are manageable, but circular references require extra care to avoid infinite traversal and broken links.

#### Complexity
- **Insert at beginning:** `O(1)`
- **Insert at end:** `O(1)`
- **Remove at beginning:** `O(1)`
- **Remove at end:** `O(n)`
- **Print / size:** `O(n)`
- **Space:** `O(n)`

---

### 3. Doubly Linked List Operations and Reverse Printing

**Description:**  
Implements a standard doubly linked list with insertion at the beginning and end, insertion with tail support, removal from both ends, and printing from end to beginning.

#### What this problem covers
- doubly linked list construction;
- insertion using only `head`;
- insertion using both `head` and `tail`;
- reverse traversal;
- removal at boundaries.

#### What it is used for
This exercise is useful for comparing different strategies for insertion and removal in doubly linked lists, especially when a tail pointer is available.

#### What it strengthens
- `prev` and `next` pointer maintenance;
- reverse traversal logic;
- comparison between linear and tail-assisted insertion;
- deletion safety in linked structures.

#### Difficulty
**Medium**

The logic is not complex mathematically, but maintaining consistency between forward and backward links is essential.

#### Complexity
- **Insert at beginning:** `O(1)`
- **Insert at end using head only:** `O(n)`
- **Insert at end with tail:** `O(1)`
- **Remove at beginning:** `O(1)`
- **Remove at end using head only:** `O(n)`
- **Remove at end with tail:** `O(1)`
- **Reverse print:** `O(n)`
- **Space:** `O(n)`

---

### 4. Merge Sort Implementation

**Description:**  
Implements Merge Sort over an integer array, including the merge step that combines two previously sorted halves.

#### What this problem covers
- divide and conquer;
- recursive splitting;
- merging sorted subarrays;
- temporary auxiliary memory;
- recursive sorting structure.

#### What it is used for
This exercise is useful for studying one of the most important comparison-based sorting algorithms, especially for understanding how recursive decomposition produces an efficient global ordering.

#### What it strengthens
- recursive divide-and-conquer thinking;
- array segment handling;
- merge logic;
- time and space complexity analysis.

#### Difficulty
**Medium**

The algorithm is conceptually elegant, but implementing the merge step correctly requires careful index control.

#### Complexity
- **Time:** `O(n log n)`
- **Space:** `O(n)`

> This is one of the classic efficient stable sorting algorithms.

---

### 5. Quick Sort with First-Element Pivot

**Description:**  
Implements Quick Sort using the first element as the pivot and a custom partition strategy.

#### What this problem covers
- partition-based sorting;
- recursive subproblem division;
- pivot placement;
- in-place swapping;
- recursive ordering.

#### What it is used for
This exercise is useful for learning how Quick Sort organizes elements around a pivot and recursively sorts the left and right partitions.

#### What it strengthens
- partition reasoning;
- index movement during sorting;
- in-place sorting logic;
- understanding of pivot strategy effects.

#### Difficulty
**Medium**

The recursion is simple in appearance, but the real challenge is correctly understanding and implementing the partition step.

#### Complexity
- **Average Time:** `O(n log n)`
- **Worst Time:** `O(n²)`
- **Space:** `O(log n)` average recursion stack, `O(n)` worst case

> The pivot choice strongly affects performance, and choosing the first element can lead to poor behavior on unfavorable inputs.

---

### 6. Quick Sort with Execution Tracing

**Description:**  
Implements Quick Sort while printing the recursion depth, pivot choice, swaps, input subarray, and output subarray at each recursive level.

#### What this problem covers
- Quick Sort tracing;
- recursive debugging;
- partition visualization;
- depth-based output formatting;
- random array generation for testing.

#### What it is used for
This exercise is especially useful for educational purposes, since it shows step by step how Quick Sort behaves internally during recursion.

#### What it strengthens
- debugging recursive algorithms;
- visualization of partitioning;
- understanding recursion depth;
- interpretation of sorting state transitions.

#### Difficulty
**Medium**

The sorting itself is familiar, but the tracing output adds an extra layer of care and helps build deeper algorithmic intuition.

#### Complexity
- **Average Time:** `O(n log n)`
- **Worst Time:** `O(n²)`
- **Space:** depends on recursion depth, typically `O(log n)` on average

> This version is valuable mainly as a learning and visualization tool.

---

### 7. Circular Doubly Linked List with Positional Operations and Palindrome Check

**Description:**  
Implements a circular doubly linked list with insertion and removal at the beginning and end, insertion and removal at a given position, forward and reverse printing, and a palindrome check using traversal from both ends. :contentReference[oaicite:1]{index=1}

#### What this problem covers
- circular doubly linked lists;
- positional insertion and removal;
- forward and reverse traversal;
- boundary handling with `head` and `tail`;
- palindrome verification using two-pointer movement. :contentReference[oaicite:2]{index=2}

#### What it is used for
This exercise is useful for combining multiple advanced list operations in a single structure, especially when the list must remain circular and doubly linked at the same time. :contentReference[oaicite:3]{index=3}

#### What it strengthens
- advanced pointer manipulation;
- circular bidirectional traversal;
- insertion and deletion at arbitrary positions;
- structural invariants in linked lists;
- comparison from both ends of a sequence. :contentReference[oaicite:4]{index=4}

#### Difficulty
**Medium to Hard**

This is one of the most structurally demanding exercises in the folder, because circularity, bidirectionality, and positional updates must all remain consistent after every operation. :contentReference[oaicite:5]{index=5}

#### Complexity
- **Insert/remove at beginning:** `O(1)`
- **Insert/remove at end:** `O(1)`
- **Insert/remove at position:** `O(n)`
- **Palindrome check:** `O(n)`
- **Space:** `O(n)` :contentReference[oaicite:6]{index=6}

---

## Summary of Lista 8

Overall, `Lista 8` strengthens topics such as:

- doubly linked lists;
- circular linked lists;
- positional insertion and removal;
- forward and backward traversal;
- Merge Sort;
- Quick Sort;
- recursive divide-and-conquer reasoning;
- structural and algorithmic complexity analysis.

This makes the folder especially valuable for moving into a more advanced stage of C practice, where the focus is not only on solving the problem, but also on **understanding the internal mechanics of data structures and sorting algorithms**.

## Lista 9

**Folder:** `Lista 9/`

This folder continues the study of **linked lists and simulations**, with a stronger focus on **circular structures**, **elimination processes**, and **time-based analysis**.

Compared to the previous lists, `Lista 9` emphasizes problems where the data structure is not just a storage mechanism, but the core of the algorithm itself. The main challenge here is simulating behavior over linked structures while preserving pointer consistency.

It is especially useful for improving skills in **circular doubly linked lists**, **removal logic**, **direction-based traversal**, and **event-driven simulation**.

---

### 1. Circular Elimination Game with Dynamic Direction

**Description:**  
Implements a circular doubly linked list of children, where each child has a name and a numeric value. At each step, one child is eliminated, and the next traversal direction depends on whether the eliminated value is even or odd. The process continues until only one child remains, who becomes the winner.

#### What this problem covers
- circular doubly linked lists;
- elimination simulation;
- direction switching based on parity;
- node removal during traversal;
- winner selection in a cyclic structure.

#### What it is used for
This exercise is useful for practicing circular list simulations in which each removal changes the future behavior of the process.

#### What it strengthens
- pointer updates in circular structures;
- handling head and tail changes after deletion;
- simulation of rule-based elimination;
- reasoning about clockwise and counterclockwise traversal.

#### Difficulty
**Medium to Hard**

The hardest part is keeping the circular structure valid while repeatedly removing nodes and changing the traversal direction based on dynamic rules.

#### Complexity
- **Time:** depends on the step values used in the simulation
- **Space:** `O(n)`

> Since the algorithm walks through the circle repeatedly and removes one node at a time, its cost grows with both the number of children and the traversal distances used at each round.

---

### 2. Critical Patient Waiting Analysis

**Description:**  
Stores patient arrival times and critical waiting thresholds, then simulates a service routine where appointments happen every 30 minutes starting at 7:00. The goal is to count how many patients become critical because their waiting time exceeds their allowed limit.

#### What this problem covers
- linked list storage of records;
- time conversion into minutes;
- sequential simulation of service scheduling;
- waiting-time analysis;
- threshold-based classification.

#### What it is used for
This exercise is useful for modeling real-world waiting systems, especially when events happen at fixed intervals and each record has its own tolerance limit.

#### What it strengthens
- time normalization;
- sequential processing of ordered records;
- simulation of scheduling systems;
- interpretation of constraints using arithmetic in minutes.

#### Difficulty
**Medium**

The logic is direct once the times are converted properly, but it is a good exercise in modeling time-based systems and checking conditions consistently.

#### Complexity
- **Time:** `O(n)`
- **Space:** `O(n)`

> Each patient is inserted once and processed once.

---

### 3. Dual-Direction Circular Elimination

**Description:**  
Implements a circular doubly linked list of numbered participants and removes people from both directions at each round: one selected by moving forward and another selected by moving backward. If both pointers land on the same participant, only one removal happens. The program prints the elimination order in the required format. :contentReference[oaicite:1]{index=1}

#### What this problem covers
- circular doubly linked lists;
- simultaneous traversal from opposite directions;
- multiple removal cases;
- special handling when both pointers meet;
- formatted simulation output. :contentReference[oaicite:2]{index=2}

#### What it is used for
This exercise is useful for understanding more advanced elimination simulations, especially when multiple traversals interact with the same circular structure at the same time. :contentReference[oaicite:3]{index=3}

#### What it strengthens
- circular pointer reasoning;
- careful removal of one or two nodes per round;
- handling edge cases after deletions;
- synchronization of forward and backward traversal. :contentReference[oaicite:4]{index=4}

#### Difficulty
**Hard**

This is one of the most delicate simulations in the repository, since removing nodes from a circular list while two moving pointers are active requires very careful pointer adjustment. :contentReference[oaicite:5]{index=5}

#### Complexity
- **Time:** depends on the traversal step sizes `k` and `m`
- **Space:** `O(n)` :contentReference[oaicite:6]{index=6}

> The total cost depends on how many positions must be advanced or reversed at each round before each elimination.

---

## Summary of Lista 9

Overall, `Lista 9` strengthens topics such as:

- circular doubly linked lists;
- elimination-based simulations;
- direction-dependent traversal;
- removal in cyclic structures;
- time-based scheduling analysis;
- pointer consistency during repeated updates;
- handling complex edge cases in linked structures.

This makes the folder especially valuable for practicing problems where the solution depends on **accurately simulating a process over a dynamic linked structure**, rather than only storing and printing data.

## Lista 10

**Folder:** `Lista 10/`

This folder advances into classic **searching and tree-based data structures**, especially **binary search trees**, **linear and binary search**, and **hash tables with open addressing**.

Compared to the previous lists, `Lista 10` shifts the focus from linked structures and sorting into problems that are more directly related to **data organization, retrieval, and structural properties**.

It is especially useful for strengthening the foundations of **search algorithms**, **tree traversal**, **node removal cases**, and **hash table collision handling** in C.

---

### 1. Binary Search Tree Operations

**Description:**  
Implements a binary search tree with insertion, node removal, maximum-value lookup, height calculation, leaf printing, validation of whether every node has either zero or two children, and the three classic traversals: preorder, inorder, and postorder.

#### What this problem covers
- binary search tree insertion;
- node removal in all major cases;
- recursive tree traversal;
- tree height computation;
- leaf detection;
- structural property checking.

#### What it is used for
This exercise is useful for understanding one of the most important hierarchical data structures in computer science and for practicing how recursive logic naturally fits tree operations.

#### What it strengthens
- tree recursion;
- structural reasoning;
- handling node deletion cases;
- traversal order understanding;
- interpretation of binary search tree properties.

#### Difficulty
**Medium to Hard**

The insertion and traversals are relatively direct, but deletion and structural validation require more careful reasoning, especially when the removed node has two children.

#### Complexity
- **Insertion:** `O(h)`
- **Removal:** `O(h)`
- **Search for maximum:** `O(h)`
- **Height calculation:** `O(n)`
- **Traversals:** `O(n)`
- **Space:** `O(n)` for the tree, plus recursion stack `O(h)`

> Here, `h` is the tree height. In balanced cases, `h = O(log n)`, but in the worst case it can degrade to `O(n)`.

---

### 2. Linear Search and Binary Search

**Description:**  
Implements both linear search and binary search over an array. The binary search version includes a sorting step before the search, ensuring that the array satisfies the ordering condition required by binary search.

#### What this problem covers
- linear search;
- binary search;
- sorting before binary search;
- iterative search logic;
- comparison between searching strategies.

#### What it is used for
This exercise is useful for comparing two fundamental search techniques and understanding when each one is appropriate.

#### What it strengthens
- array traversal;
- index-based reasoning;
- ordered vs unordered search understanding;
- awareness of preprocessing requirements for binary search.

#### Difficulty
**Easy to Medium**

The algorithms themselves are classic and accessible, but the exercise is valuable because it highlights an important idea: binary search is only valid on ordered data.

#### Complexity
- **Linear search:** `O(n)`
- **Binary search only:** `O(log n)`
- **Binary search with sorting in this implementation:** `O(n²)` because of insertion sort
- **Space:** `O(1)`

> This is a good example of how preprocessing can dominate the total cost even when the final search step is fast.

---

### 3. Hash Table with Open Addressing and Tombstones

**Description:**  
Implements a hash table using open addressing with linear probing. It supports insertion, search, deletion with tombstones, and explicit clearing of the table.

#### What this problem covers
- hash table structure;
- open addressing;
- linear probing;
- collision handling;
- tombstone-based deletion;
- table reset.

#### What it is used for
This exercise is useful for understanding how hash tables can be implemented without linked chains, relying instead on probing strategies to resolve collisions.

#### What it strengthens
- hashing logic;
- collision resolution strategies;
- handling deleted slots safely;
- search continuity through tombstones;
- constant-time average-case lookup reasoning.

#### Difficulty
**Medium**

The core operations are short, but the logic behind tombstones and probing must be understood carefully to avoid incorrect search and insertion behavior.

#### Complexity
- **Average search / insert / remove:** `O(1)`
- **Worst-case search / insert / remove:** `O(n)`
- **Space:** `O(m)`

> Performance is usually efficient, but clustering and heavy collision scenarios can make probing degrade toward linear time.

---

## Summary of Lista 10

Overall, `Lista 10` strengthens topics such as:

- binary search trees;
- recursive tree algorithms;
- tree traversal patterns;
- search strategies in arrays;
- differences between linear and binary search;
- hash tables;
- open addressing and collision handling;
- structural and performance analysis of search-oriented data structures.

This makes the folder especially valuable for practicing core topics in **data structures and search algorithms**, helping build a stronger foundation for more advanced study in algorithms, databases, and systems design.

