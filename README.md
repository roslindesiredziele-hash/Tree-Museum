# An Introduction to Applied Dendrology

A C++ implementation and empirical analysis of Binary Search Trees (BSTs) developed for **Assignment III – Task 1: An Introduction to Applied Dendrology** from the *Tree Museum* coursework.

This project investigates how insertion order affects the shape and performance of binary search trees.

---

## Problem Description

The assignment requires implementing a binary tree container and comparing the cumulative running times of inserting a large set of keys into:

1. A Binary Search Tree using a random insertion order.
2. A Binary Search Tree using a best-case insertion order that produces a perfectly balanced tree.
3. A library implementation using `std::set`.

The assignment also requires reporting the actual height of the generated trees and comparing the empirical results with theoretical expectations.

---

## Project Structure

```text
Assignment-III_Tree_museum/
│
├── data/
│   └── benchmark.csv
│
├── report/
│   ├── graph.py
│   ├── insertion_time.png
│   └── tree_height.png
│
├── src/
│   ├── BST.h
│   ├── BST.cpp
│   ├── Benchmark.h
│   ├── Benchmark.cpp
│   ├── AVL.h
│   ├── AVL.cpp
│   ├── TernaryTree.h
│   ├── TernaryTree.cpp
│   └── main.cpp
│
├── Utils/
│   ├── Utils.h
│   └── Utils.cpp
│
├── README.md
└── .gitignore
```

---

## Building

Compile using:

```bash
g++ src/*.cpp Utils/*.cpp -o benchmark
```

---

## Usage

Run the benchmark:

```bash
./benchmark
```

On Windows:

```bash
./benchmark.exe
```

The program:

1. Generates test datasets.
2. Builds BSTs using random insertion order.
3. Builds BSTs using balanced insertion order.
4. Builds a `std::set`.
5. Measures insertion times.
6. Measures resulting tree heights.
7. Saves benchmark results to:

```text
data/benchmark.csv
```

Generate graphs with:

```bash
py -3.13 report/graph.py
```

---

## Dataset

The benchmark dataset is stored in:

```text
data/benchmark.csv
```

Each record contains:

- Tree size
- BST insertion time (random order)
- BST insertion time (balanced order)
- `std::set` insertion time
- BST height (random order)
- BST height (balanced order)

---

## Binary Search Tree Implementation

### Node Structure

Each node stores:

```cpp
struct Node
{
    int key;

    Node* left;
    Node* right;
};
```

### Insertion

Insertion follows standard BST rules:

```text
key < node->key   → left subtree
key > node->key   → right subtree
```

Duplicate values are ignored.

### Height

Tree height is computed recursively:

```text
height(node)
=
1 + max(
    height(left),
    height(right)
)
```

### Memory Management

All dynamically allocated nodes are released through a recursive postorder traversal:

```cpp
destroy(left);
destroy(right);
delete node;
```

This ensures that no memory leaks occur.

---

## Balanced BST Construction

A perfectly balanced BST cannot be obtained by inserting keys in sorted order.

Instead, the insertion order is generated recursively:

1. Insert the middle element.
2. Insert the middle of the left half.
3. Insert the middle of the right half.
4. Continue recursively.

Example:

Sorted keys:

```text
1 2 3 4 5 6 7
```

Balanced insertion order:

```text
4 2 1 3 6 5 7
```

Resulting tree:

```text
        4
      /   \
     2     6
    / \   / \
   1   3 5   7
```

This construction produces the minimum possible height.

---

## Complexity Analysis

### Binary Search Tree

#### Insertion

Average case:

```text
O(log n)
```

Worst case:

```text
O(n)
```

---

### Balanced BST

Since the generated insertion order produces a balanced tree:

```text
Height ≈ log₂(n)
```

Insertion remains:

```text
O(log n)
```

for all practical operations.

---

### std::set

`std::set` is typically implemented as a self-balancing Red-Black Tree.

Insertion complexity:

```text
O(log n)
```

---

## Expected Graph Behavior

Based on the theoretical complexity:

- Insertion times should increase as the number of keys increases.
- Balanced BST insertion should outperform random BST insertion.
- The height of the balanced BST should grow slowly and remain close to `log₂(n)`.
- The random BST should produce significantly taller trees.
- `std::set` should maintain logarithmic behavior due to self-balancing.

---

## Benchmark Configuration

### Tree Sizes

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

These values satisfy:

```text
n = 2^m − 1
```

which allows perfectly balanced binary trees to be constructed.

### Repetitions

Each benchmark is averaged over:

```text
20 runs
```

---

## Results

### Representative Results

| Keys | Random BST Height | Balanced BST Height |
|------:|------------------:|--------------------:|
| 127 | 14 | 7 |
| 255 | 17 | 8 |
| 511 | 19 | 9 |
| 1023 | 22 | 10 |
| 2047 | 24 | 11 |
| 4095 | 27 | 12 |
| 8191 | 30 | 13 |
| 16383 | 32 | 14 |

### Representative Insertion Times

| Keys | BST Random (ms) | BST Balanced (ms) | std::set (ms) |
|------:|---------------:|------------------:|--------------:|
| 127 | 0.013 | 0.007 | 0.034 |
| 255 | 0.030 | 0.018 | 0.072 |
| 511 | 0.073 | 0.043 | 0.172 |
| 1023 | 0.195 | 0.112 | 0.363 |
| 2047 | 0.336 | 0.229 | 0.768 |
| 4095 | 0.806 | 0.483 | 1.573 |
| 8191 | 1.714 | 0.951 | 3.698 |
| 16383 | 4.059 | 1.988 | 7.123 |

Because randomization is used during benchmarking, exact values may vary between executions.

---

## Generated Graphs

The following graphs are generated from `benchmark.csv`.

### Insertion Time vs Number of Keys

report/insertion_time.png

**Observation**

- Insertion time increases with tree size.
- Balanced BST insertion is consistently faster than random BST insertion.
- `std::set` is slower because it performs balancing operations during insertion.

---

### Tree Height vs Number of Keys

report/tree_height.png

**Observation**

- The balanced BST closely follows the theoretical minimum height.
- Random insertion produces significantly taller trees.
- The height difference becomes more pronounced as the number of keys increases.

---

## Findings

### Effect of Insertion Order

The insertion order has a significant impact on BST structure.

Balanced insertion produced trees whose heights closely matched the theoretical minimum.

For the largest benchmark:

```text
16383 keys

Balanced Height = 14
Random Height   = 32
```

The random BST required more than twice as many levels as the balanced BST.

### Effect on Performance

Balanced insertion also reduced insertion times.

For the largest benchmark:

```text
BST Random   ≈ 4.06 ms
BST Balanced ≈ 1.99 ms
```

The shallower structure required fewer comparisons during insertion.

### Comparison with std::set

Although `std::set` maintained logarithmic behavior, it was slower than both BST variants because it performs additional balancing operations internally.

---

## Conclusions

The experimental results confirm that tree structure has a significant impact on performance.

Balanced insertion produced trees with heights close to the theoretical minimum and consistently lower insertion times than randomly constructed BSTs.

The benchmark results support the theoretical analysis:

- Balanced trees maintain logarithmic height.
- Random BSTs become significantly taller.
- Shallower trees generally provide better insertion performance.

Overall, the results demonstrate why balancing strategies are important in search-tree data structures.

---

## Author

**Desire Roslin Dziele**

University of Lodz  
Algorithms and Data Structures