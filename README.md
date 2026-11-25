# Tree Museum

Assignment III – Tree Museum

University of Lodz  
Algorithms and Data Structures

---

# Overview

Tree Museum is a C++ project that investigates the practical behavior of several tree-based data structures through empirical benchmarking.

The project implements and evaluates:

- Binary Search Tree (BST)
- AVL Tree
- Random Ternary Tree
- Balanced Ternary Tree
- C++ Standard Library `std::set`

The study focuses on:

- insertion performance,
- deletion performance,
- resulting tree height,
- influence of insertion order,
- balancing strategies,
- branching factor.

The benchmark framework automatically generates datasets, executes repeated measurements, exports benchmark results to CSV format, and generates graphs used in the final analysis.

---

# Assignment Tasks

## Task 1 – An Introduction to Applied Dendrology

Compare insertion performance and resulting heights of:

1. BST with random insertion order
2. BST with balanced insertion order
3. `std::set`

---

## Task 2 – Pruning the Bushes

Compare deletion performance of:

1. BST
2. `std::set`

---

## Task 3 – Grow Your Own Arboretum

Extend the project by implementing and evaluating:

1. AVL Tree
2. Random Ternary Tree
3. Balanced Ternary Tree

and compare them against the structures from Tasks 1 and 2.

---

# Project Structure

```text
Assignment-III_Tree_museum/
│
├── data/
│   └── benchmark.csv
│
├── report/
│   ├── graph.py
│   ├── insertion_time.png
│   ├── tree_height.png
│   ├── deletion_time.png
│   ├── avl_height_comparison.png
│   ├── avl_vs_bst_insert.png
│   ├── avl_vs_bst_delete.png
│   ├── ternary_height_comparison.png
│   └── ternary_insert_comparison.png
│
├── src/
│   ├── BST.h
│   ├── BST.cpp
│   ├── AVL.h
│   ├── AVL.cpp
│   ├── TernaryTree.h
│   ├── TernaryTree.cpp
│   ├── Benchmark.h
│   ├── Benchmark.cpp
│   └── main.cpp
│
├── Utils/
│   ├── Utils.h
│   └── Utils.cpp
│
├── task1_report.docx
├── task2_report.docx
├── README.md
└── .gitignore
```

---

# Requirements

## Compiler

The project requires a C++17-compatible compiler.

Tested with:

```text
g++ (MinGW-w64)
```

Examples:

- GCC 11+
- Clang 14+
- Visual Studio 2022

---

## Python

Python is required for graph generation.

Tested with:

```text
Python 3.13
```

Required packages:

```bash
pip install pandas matplotlib
```

---

## Operating System

Tested on:

```text
Windows 11
```

Benchmark timing uses:

```cpp
QueryPerformanceCounter()
```

from the Windows API.

---

# Building

Compile the benchmark executable:

```bash
g++ src/*.cpp Utils/*.cpp -o benchmark
```

---

# Running

Execute:

```bash
./benchmark.exe
```

The program:

1. Generates benchmark datasets.
2. Executes insertion benchmarks.
3. Executes deletion benchmarks.
4. Measures resulting tree heights.
5. Stores measurements in:

```text
data/benchmark.csv
```

---

# Generating Graphs

Generate all figures with:

```bash
py -3.13 report/graph.py
```

Generated graphs:

```text
insertion_time.png
tree_height.png
deletion_time.png
avl_height_comparison.png
avl_vs_bst_insert.png
avl_vs_bst_delete.png
ternary_height_comparison.png
ternary_insert_comparison.png
```

---

# Implemented Data Structures

## Binary Search Tree

Node structure:

```cpp
struct Node
{
    int key;

    Node* left;
    Node* right;
};
```

Implemented operations:

```text
insert()
remove()
height()
size()
empty()
```

Duplicates are ignored.

---

## AVL Tree

Node structure:

```cpp
struct Node
{
    int key;

    int nodeHeight;

    Node* left;
    Node* right;
};
```

Implemented operations:

```text
insert()
remove()
contains()
height()
size()
empty()
```

Balancing uses:

```text
LL Rotation
RR Rotation
LR Rotation
RL Rotation
```

The AVL tree automatically restores balance after insertions and deletions.

---

## Ternary Tree

Node structure:

```cpp
struct Node
{
    int leftKey;
    int rightKey;

    bool hasSecondKey;

    Node* left;
    Node* middle;
    Node* right;
};
```

Routing rules:

```text
key < leftKey
    -> left subtree

leftKey < key < rightKey
    -> middle subtree

key > rightKey
    -> right subtree
```

Implemented operations:

```text
insert()
contains()
height()
size()
empty()
```

---

## Balanced Ternary Tree

The balanced ternary tree uses a custom insertion order generated recursively.

For each key range:

1. Divide the range into thirds.
2. Select two partition keys.
3. Insert both partition keys.
4. Recursively process:
   - left third,
   - middle third,
   - right third.

This produces substantially smaller heights than random ternary insertion.

---

# Complexity Analysis

| Structure | Search | Insert | Delete | Height |
|------------|---------|---------|---------|---------|
| BST (Random) | O(log n) avg, O(n) worst | O(log n) avg, O(n) worst | O(log n) avg, O(n) worst | O(n) worst |
| BST (Balanced Order) | O(log n) | O(log n) | O(log n) average | O(log n) |
| AVL Tree | O(log n) | O(log n) | O(log n) | O(log n) |
| std::set (Red–Black Tree) | O(log n) | O(log n) | O(log n) | O(log n) |
| Random Ternary Tree | O(h) avg, O(n) worst | O(h) avg, O(n) worst | Not Implemented | O(n) worst |
| Balanced Ternary Tree | O(log₃ n) | O(log₃ n) | Not Implemented | O(log₃ n) |

where:

```text
h = tree height
```

---

# Benchmark Methodology

## Dataset Generation

Each benchmark uses integer keys:

```text
1, 2, 3, ..., n
```

where:

```text
n ∈ {127, 255, 511, 1023, 2047, 4095, 8191, 16383}
```

The chosen sizes satisfy:

```text
n = 2^m − 1
```

allowing perfectly balanced binary trees to be constructed.

---

## Random Insertion Order

Randomized experiments use:

1. Generate sorted keys.
2. Shuffle using `std::shuffle`.
3. Insert into the target structure.

This approximates average-case insertion behavior.

---

## Balanced BST Construction

Balanced insertion order is generated recursively:

1. Insert the middle element.
2. Recurse on the left half.
3. Recurse on the right half.

Example:

```text
Sorted:
1 2 3 4 5 6 7

Balanced Order:
4 2 1 3 6 5 7
```

---

## Balanced Ternary Construction

Balanced ternary insertion order is generated by recursively partitioning key ranges into thirds.

This attempts to minimize ternary-tree height in the same way balanced insertion minimizes BST height.

---

## Timing Procedure

Execution time is measured using:

```cpp
QueryPerformanceCounter()
```

and

```cpp
QueryPerformanceFrequency()
```

from the Windows API.

All timings are reported in milliseconds.

---

## Repetitions

Each benchmark configuration is repeated:

```text
20 times
```

Reported values represent arithmetic means.

This reduces measurement noise and transient operating-system effects.

---

# Reproducibility

The complete experiment can be reproduced using only the repository contents.

## Build

```bash
g++ src/*.cpp Utils/*.cpp -o benchmark
```

## Benchmark

```bash
./benchmark.exe
```

## Graph Generation

```bash
py -3.13 report/graph.py
```

All graphs are generated directly from:

```text
data/benchmark.csv
```

---

# Limitations

## Platform Dependency

Timing uses Windows-specific APIs.

Absolute timing measurements may differ on Linux or macOS systems.

---

## Hardware Dependency

Benchmark results depend on:

- CPU architecture,
- processor frequency,
- cache hierarchy,
- system load.

The comparative trends are more important than the exact execution times.

---

## Input Distribution

All experiments use sequential integer keys.

Different key distributions may produce different insertion paths and balance characteristics.

---

## Ternary Tree Deletion

Deletion was implemented and benchmarked for:

- BST
- AVL
- std::set

Deletion was not implemented for the ternary-tree variants.

---

## Statistical Variability

Randomized insertion orders are generated using:

```cpp
std::mt19937
```

and

```cpp
std::shuffle
```

As a result, minor differences between benchmark runs may occur.

---

# Benchmark Results

## Height Results

| Keys | BST Random | BST Balanced | AVL | Ternary Random | Ternary Balanced |
|------:|-----------:|-------------:|----:|---------------:|-----------------:|
| 127 | 14 | 7 | 8 | 8 | 5 |
| 255 | 17 | 8 | 9 | 10 | 6 |
| 511 | 19 | 9 | 10 | 11 | 6 |
| 1023 | 22 | 10 | 12 | 12 | 7 |
| 2047 | 24 | 11 | 13 | 14 | 7 |
| 4095 | 28 | 12 | 14 | 16 | 8 |
| 8191 | 30 | 13 | 15 | 17 | 9 |
| 16383 | 33 | 14 | 16 | 19 | 9 |

---

## Insertion Results

| Keys | BST Random (ms) | BST Balanced (ms) | AVL (ms) | Ternary Random (ms) | Ternary Balanced (ms) | std::set (ms) |
|------:|---------------:|------------------:|---------:|--------------------:|----------------------:|--------------:|
| 127 | 0.019135 | 0.012725 | 0.035025 | 0.017290 | 0.013685 | 0.051780 |
| 255 | 0.036100 | 0.017330 | 0.131885 | 0.031485 | 0.013140 | 0.076870 |
| 511 | 0.100315 | 0.066760 | 0.130320 | 0.066275 | 0.039530 | 0.206085 |
| 1023 | 0.246855 | 0.111890 | 0.275780 | 0.107010 | 0.075305 | 0.355775 |
| 2047 | 0.366680 | 0.244410 | 0.613420 | 0.241900 | 0.159515 | 0.753685 |
| 4095 | 0.896000 | 0.467485 | 1.323120 | 0.518745 | 0.385030 | 1.538370 |
| 8191 | 1.681590 | 0.939060 | 3.003570 | 1.191850 | 0.714650 | 3.318510 |
| 16383 | 3.771400 | 1.977560 | 6.777720 | 2.535040 | 1.505450 | 7.213940 |

---

## Deletion Results

| Keys | BST Delete (ms) | AVL Delete (ms) | std::set Delete (ms) |
|------:|----------------:|----------------:|---------------------:|
| 127 | 0.016635 | 0.033235 | 0.053185 |
| 255 | 0.024690 | 0.075530 | 0.110170 |
| 511 | 0.059290 | 0.132290 | 0.186345 |
| 1023 | 0.118685 | 0.258125 | 0.347200 |
| 2047 | 0.265135 | 0.571300 | 0.750510 |
| 4095 | 0.594220 | 1.443000 | 1.610800 |
| 8191 | 1.481230 | 2.881750 | 3.599290 |
| 16383 | 2.996350 | 6.538830 | 7.661030 |

---

# Graph Analysis and Observations

## Figure 1 – Insertion Time vs Number of Keys

report/insertion_time.png

### Observation

All structures exhibit increasing insertion times as tree size grows.

Balanced variants consistently outperform their random counterparts.

For 16,383 keys:

```text
Balanced Ternary = 1.505 ms
BST Balanced     = 1.978 ms
Random Ternary   = 2.535 ms
BST Random       = 3.771 ms
AVL              = 6.778 ms
std::set         = 7.214 ms
```

Balanced Ternary achieved the fastest insertion performance.

---

## Figure 2 – Tree Height vs Number of Keys

report/tree_height.png

### Observation

For 16,383 keys:

```text
BST Random        = 33
Random Ternary    = 19
AVL               = 16
BST Balanced      = 14
Balanced Ternary   = 9
```

The graph demonstrates the effect of balancing and branching factor on resulting tree height.

Balanced Ternary achieved the smallest height.

---

## Figure 3 – Deletion Time vs Number of Keys

report/deletion_time.png

### Observation

Deletion time increases with tree size for all structures.

For 16,383 keys:

```text
BST      = 2.996 ms
AVL      = 6.539 ms
std::set = 7.661 ms
```

BST deletion produced the lowest execution times throughout the study.

---

## Figure 4 – AVL Height vs Balanced BST Height

report/avl_height_comparison.png

### Observation

AVL height remained close to that of a perfectly balanced BST.

For 16,383 keys:

```text
BST Balanced = 14
AVL          = 16
```

This demonstrates the effectiveness of AVL balancing.

---

## Figure 5 – AVL vs BST Insertion

report/avl_vs_bst_insert.png

### Observation

AVL insertion consistently required more time than ordinary BST insertion because balancing and rotation operations are performed after updates.

The additional overhead guarantees logarithmic height.

---

## Figure 6 – AVL vs BST Deletion

report/avl_vs_bst_delete.png

### Observation

AVL deletion incurs greater cost than BST deletion due to post-deletion rebalancing and height maintenance.

This reflects the trade-off between performance and guaranteed balance.

---

## Figure 7 – Random vs Balanced Ternary Height

report/ternary_height_comparison.png

### Observation

For 16,383 keys:

```text
Random Ternary   = 19
Balanced Ternary = 9
```

Balanced ternary construction reduced height by more than 50%.

---

## Figure 8 – Random vs Balanced Ternary Insertion

report/ternary_insert_comparison.png

### Observation

For 16,383 keys:

```text
Random Ternary   = 2.535 ms
Balanced Ternary = 1.505 ms
```

Balanced ternary insertion consistently outperformed random ternary insertion.

---

# Conclusions

This project investigated the influence of insertion order, balancing strategies, and branching factor on the behavior of tree-based data structures.

The benchmark results confirmed that tree height plays a crucial role in insertion performance and overall efficiency.

For Binary Search Trees, balanced insertion dramatically reduced height:

```text
BST Random Height = 33
BST Balanced Height = 14
```

for 16,383 keys.

The AVL implementation successfully maintained logarithmic height independently of insertion order:

```text
AVL Height = 16
```

while the random BST reached:

```text
33
```

levels.

The ternary-tree experiments demonstrated the benefits of increasing branching factor. Random ternary trees achieved substantially smaller heights than random BSTs, and the balanced ternary construction produced the best overall results.

For the largest benchmark:

```text
Balanced Ternary Height = 9
Balanced Ternary Insert = 1.505 ms
```

These were the best values measured during the study.

The results support three main conclusions:

1. Balancing significantly reduces tree height.
2. Smaller heights generally improve insertion performance.
3. Increasing branching factor further improves structural efficiency.

Among all tested structures, the Balanced Ternary Tree produced the most compact structure and the best insertion-time performance.

---

# Author

**Desire Roslin Dziele**

University of Lodz  
Algorithms and Data Structures