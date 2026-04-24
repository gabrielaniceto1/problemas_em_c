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

