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

