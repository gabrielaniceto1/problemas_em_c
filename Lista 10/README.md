## Lista 10

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

