## Lista 4

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

