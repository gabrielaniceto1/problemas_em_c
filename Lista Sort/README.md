## Lista Sort

**Folder:** `Lista Sort/`

This folder is dedicated to **sorting algorithms**, with implementations and benchmark-style tests over different input scenarios such as **already sorted arrays**, **reverse-sorted arrays**, and **random arrays**.

Compared to the numbered lists, this section is much more focused on **algorithm analysis**, especially on how different sorting strategies behave in terms of:

- execution time;
- number of comparisons;
- number of swaps or movements;
- sensitivity to input order;
- asymptotic complexity.

It is especially useful for understanding not only **how sorting algorithms work**, but also **why some of them scale much better than others**.

---

### 1. Bubble Sort

**Description:**  
Implements Bubble Sort and evaluates its behavior on ordered, reverse-ordered, and random arrays, measuring execution time, comparisons, and swaps.

#### What this problem covers
- repeated adjacent comparisons;
- swap-based ordering;
- early stopping optimization;
- performance measurement.

#### What it is used for
This implementation is useful for studying one of the most classic introductory sorting algorithms and observing how inefficient it becomes on large inputs.

#### What it strengthens
- understanding of comparison-based sorting;
- analysis of worst-case behavior;
- intuition about quadratic algorithms;
- benchmarking mindset.

#### Difficulty
**Easy**

The implementation is simple, but it is very valuable as a reference point when comparing less efficient and more efficient sorting algorithms.

#### Complexity
- **Best Time:** `O(n)` with early stopping
- **Average Time:** `O(n²)`
- **Worst Time:** `O(n²)`
- **Space:** `O(1)`

---

### 2. Heap Sort

**Description:**  
Implements Heap Sort using a max-heap structure, including `heapify`, heap construction, and repeated extraction of the maximum element.

#### What this problem covers
- binary heap logic;
- heap construction;
- heapify procedure;
- in-place sorting;
- comparison and swap counting.

#### What it is used for
This implementation is useful for understanding a sorting algorithm that guarantees good asymptotic performance without requiring extra auxiliary arrays like Merge Sort.

#### What it strengthens
- tree-based array reasoning;
- heap property maintenance;
- in-place sorting analysis;
- performance comparison with other `O(n log n)` algorithms.

#### Difficulty
**Medium**

The core challenge is understanding the heap structure and how local reorganization through `heapify` produces a globally sorted result.

#### Complexity
- **Time:** `O(n log n)`
- **Space:** `O(1)`

---

### 3. Insertion Sort

**Description:**  
Implements Insertion Sort using repeated swaps between neighboring elements while the current item is smaller than the previous one.

#### What this problem covers
- incremental ordering;
- local shifting by swaps;
- sensitivity to initial order;
- performance counting.

#### What it is used for
This implementation is useful for showing that some quadratic algorithms can still perform very well on nearly sorted input.

#### What it strengthens
- understanding of incremental sorting;
- comparison between best and worst cases;
- awareness of adaptive algorithms.

#### Difficulty
**Easy**

The logic is direct and intuitive, which makes it excellent for learning sorting fundamentals.

#### Complexity
- **Best Time:** `O(n)`
- **Average Time:** `O(n²)`
- **Worst Time:** `O(n²)`
- **Space:** `O(1)`

---

### 4. Merge Sort

**Description:**  
Implements Merge Sort by recursively dividing the array into halves and merging them back in sorted order, while also counting comparisons and movements.

#### What this problem covers
- divide and conquer;
- recursive splitting;
- merging sorted halves;
- auxiliary array usage;
- stable sorting behavior.

#### What it is used for
This implementation is useful for studying one of the most important efficient sorting algorithms, especially for understanding stable sorting and guaranteed `O(n log n)` performance.

#### What it strengthens
- recursive algorithm design;
- merge logic;
- array segment reasoning;
- distinction between time efficiency and memory cost.

#### Difficulty
**Medium**

The merge step requires careful control of indices and temporary storage, but the overall design is elegant and highly educational.

#### Complexity
- **Time:** `O(n log n)`
- **Space:** `O(n)`

---

### 5. Quick Sort

**Description:**  
Implements Quick Sort using the first element as the pivot and a custom partition process, while measuring comparisons, swaps, and execution time.

#### What this problem covers
- partition-based sorting;
- pivot selection;
- recursive subarray sorting;
- in-place swapping;
- benchmark comparison across scenarios.

#### What it is used for
This implementation is useful for understanding one of the fastest practical sorting methods and also for seeing how pivot choice can strongly affect performance.

#### What it strengthens
- partition reasoning;
- recursive divide-and-conquer logic;
- sensitivity analysis for pivot strategies;
- performance tradeoff awareness.

#### Difficulty
**Medium**

The recursion is straightforward, but correctly understanding partitioning is the key challenge.

#### Complexity
- **Best / Average Time:** `O(n log n)`
- **Worst Time:** `O(n²)`
- **Space:** `O(log n)` average recursion stack, `O(n)` worst case

> Since this version uses the first element as pivot, already ordered inputs may lead to worse behavior.

---

### 6. Radix Sort

**Description:**  
Implements Radix Sort using stable Counting Sort on each digit, measuring execution time and counting element movements instead of element-to-element comparisons.

#### What this problem covers
- non-comparison sorting;
- digit-by-digit processing;
- stable counting sort by digit;
- movement-based cost analysis.

#### What it is used for
This implementation is useful for studying an algorithm that does not rely on direct comparisons between elements and can be very efficient for integer sorting.

#### What it strengthens
- understanding of non-comparison sorting;
- digit decomposition logic;
- stability in intermediate sorting steps;
- distinction between comparisons and movements.

#### Difficulty
**Medium**

The algorithm is conceptually different from classic comparison sorts, which makes it especially valuable for expanding sorting knowledge.

#### Complexity
- **Time:** `O(d * (n + k))`
- **Space:** `O(n + k)`

> Here, `d` is the number of digits and `k` is the digit range, which is `10` in base-10 counting sort.

---

### 7. TimSort (Simplified Version)

**Description:**  
Implements a simplified TimSort-like strategy by first sorting small runs with Insertion Sort and then merging them progressively, while counting comparisons and movements.

#### What this problem covers
- hybrid sorting;
- insertion sort on small runs;
- merge-based combination of runs;
- practical optimization ideas;
- benchmarking of a mixed strategy.

#### What it is used for
This implementation is useful for understanding why hybrid algorithms are powerful in practice: they combine the strengths of multiple sorting techniques.

#### What it strengthens
- hybrid algorithm reasoning;
- practical optimization concepts;
- relationship between local ordering and global merging;
- comparison between theoretical and practical performance.

#### Difficulty
**Medium to Hard**

The logic is more elaborate than standard standalone algorithms because it combines two different sorting strategies into one process.

#### Complexity
- **Time:** typically `O(n log n)`
- **Space:** `O(n)`

> This is a simplified educational version inspired by TimSort principles rather than a full production implementation.

---

## Summary of Lista Sort

Overall, `Lista Sort` strengthens topics such as:

- classic comparison-based sorting;
- non-comparison sorting;
- divide and conquer;
- heap-based ordering;
- hybrid sorting strategies;
- benchmarking and empirical analysis;
- interpretation of comparisons, swaps, and movements;
- best, average, and worst-case behavior.

This makes the folder especially valuable for building a strong understanding of **algorithm efficiency**, since it goes beyond simply sorting arrays and helps analyze **how different strategies behave under different input conditions**.

