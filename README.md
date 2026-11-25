# Tree Museum

Assignment III – Tree Museum

University of Lodz  
Algorithms I

## Overview

Tree Museum is a C++ project that investigates the practical behavior of several tree-based data structures through empirical benchmarking.

The project implements and evaluates:

- Binary Search Trees (BST)
- AVL Trees
- Random Ternary Trees
- Balanced Ternary Trees
- C++ Standard Library `std::set`

The study focuses on:

- insertion performance,
- deletion performance,
- resulting tree height,
- influence of insertion order,
- influence of balancing strategies,
- influence of branching factor.

The benchmark framework automatically generates datasets, executes repeated measurements, exports results to CSV format, and generates comparison graphs.

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
- MSVC 2022

---

## Python

Python is required to generate graphs.

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

The benchmark framework uses:

```cpp
QueryPerformanceCounter()
```

from the Windows API.

---

# Building

Compile:

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
4. Measures tree heights.
5. Stores the results in:

```text
data/benchmark.csv
```

---

# Generating Graphs

Generate all graphs using:

```bash
py -3.13 report/graph.py
```

Generated graphs:

- insertion_time.png
- tree_height.png
- deletion_time.png
- avl_height_comparison.png
- avl_vs_bst_insert.png
- avl_vs_bst_delete.png
- ternary_height_comparison.png
- ternary_insert_comparison.png

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

Balancing operations:

```text
LL Rotation
RR Rotation
LR Rotation
RL Rotation
```

The AVL tree automatically restores balance after insertion and deletion.

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

Duplicates are ignored.

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

Balanced ternary trees are generated through a custom insertion order.

The key range is recursively divided into thirds.

Two partition keys are inserted first and recursion continues on:

```text
left third
middle third
right third
```

This produces significantly smaller heights than random ternary insertion.

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

# Benchmark Configuration

## Tree Sizes

```text
127
255
511
1023
2047
4095
8191
16383
```

These sizes satisfy:

```text
n = 2^m − 1
```

which allows perfectly balanced binary trees to be generated.

---

## Repetitions

Each measurement is averaged over:

```text
20 runs
```

---

# Benchmark Results

The following results correspond to the latest benchmark execution.

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

# Key Findings

## Influence of Insertion Order

For 16383 keys:

```text
BST Random Height   = 33
BST Balanced Height = 14
```

Balanced insertion reduced the height by more than half.

---

## AVL Trees

For 16383 keys:

```text
AVL Height = 16
```

The AVL tree maintained logarithmic height independently of insertion order.

---

## Random Ternary Trees

For 16383 keys:

```text
Random BST Height     = 33
Random Ternary Height = 19
```

Increasing the branching factor significantly reduced height.

---

## Balanced Ternary Trees

Balanced ternary trees produced the best overall results.

For 16383 keys:

```text
Height = 9
Insertion Time = 1.505 ms
```

This was the smallest height and fastest insertion performance measured during the study.

---

# Generated Graphs

## Insertion Time vs Number of Keys

report/insertion_time.png

## Tree Height vs Number of Keys

report/tree_height.png

## Deletion Time vs Number of Keys

report/deletion_time.png

## AVL Height Comparison

report/avl_height_comparison.png

## AVL vs BST Insertion

report/avl_vs_bst_insert.png

## AVL vs BST Deletion

report/avl_vs_bst_delete.png

## Random vs Balanced Ternary Height

report/ternary_height_comparison.png

## Random vs Balanced Ternary Insertion

report/ternary_insert_comparison.png

---

# Conclusions

The study confirms that both balancing and branching factor have a major impact on tree performance.

Main observations:

- Random BSTs produced the greatest heights.
- Balanced BSTs dramatically reduced tree height.
- AVL trees guaranteed logarithmic height through rotations.
- Random ternary trees outperformed random BSTs due to their higher branching factor.
- Balanced ternary trees achieved the smallest heights and fastest insertion times.

For the largest dataset:

```text
BST Random Height      = 33
AVL Height             = 16
BST Balanced Height    = 14
Balanced Ternary Height = 9
```

Among all tested implementations, the Balanced Ternary Tree achieved the best overall insertion performance and the most compact tree structure.

---

# Author

**Desire Roslin Dziele**

University of Lodz  
Algorithms I