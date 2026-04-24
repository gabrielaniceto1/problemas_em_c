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

