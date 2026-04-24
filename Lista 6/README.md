## Lista 6

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

