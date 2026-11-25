import pandas as pd
import matplotlib.pyplot as plt

# ==================================================
# Load Data
# ==================================================

df = pd.read_csv("data/benchmark.csv")

plt.style.use("default")

# ==================================================
# Graph 1
# Insertion Time vs Number of Keys
# ==================================================

plt.figure(figsize=(10, 6))

plt.plot(
    df["Size"],
    df["BSTRandomMs"],
    marker="o",
    linewidth=2,
    label="BST Random"
)

plt.plot(
    df["Size"],
    df["BSTBalancedMs"],
    marker="o",
    linewidth=2,
    label="BST Balanced"
)

plt.plot(
    df["Size"],
    df["AVLMs"],
    marker="o",
    linewidth=2,
    label="AVL"
)

plt.plot(
    df["Size"],
    df["StdSetMs"],
    marker="o",
    linewidth=2,
    label="std::set"
)

plt.title("Insertion Time vs Number of Keys")

plt.xlabel("Number of Keys")
plt.ylabel("Insertion Time (ms)")

plt.grid(True, alpha=0.3)

plt.legend()

plt.tight_layout()

plt.savefig(
    "report/insertion_time.png",
    dpi=300
)

# ==================================================
# Graph 2
# Tree Height vs Number of Keys
# ==================================================

plt.figure(figsize=(10, 6))

plt.plot(
    df["Size"],
    df["BSTRandomHeight"],
    marker="o",
    linewidth=2,
    label="BST Random"
)

plt.plot(
    df["Size"],
    df["BSTBalancedHeight"],
    marker="o",
    linewidth=2,
    label="BST Balanced"
)

plt.plot(
    df["Size"],
    df["AVLHeight"],
    marker="o",
    linewidth=2,
    label="AVL"
)

plt.title("Tree Height vs Number of Keys")

plt.xlabel("Number of Keys")
plt.ylabel("Height")

plt.grid(True, alpha=0.3)

plt.legend()

plt.tight_layout()

plt.savefig(
    "report/tree_height.png",
    dpi=300
)

# ==================================================
# Graph 3
# Deletion Time vs Number of Keys
# ==================================================

plt.figure(figsize=(10, 6))

plt.plot(
    df["Size"],
    df["BSTDeleteMs"],
    marker="o",
    linewidth=2,
    label="BST"
)

plt.plot(
    df["Size"],
    df["AVLDeleteMs"],
    marker="o",
    linewidth=2,
    label="AVL"
)

plt.plot(
    df["Size"],
    df["StdSetDeleteMs"],
    marker="o",
    linewidth=2,
    label="std::set"
)

plt.title("Deletion Time vs Number of Keys")

plt.xlabel("Number of Keys")
plt.ylabel("Deletion Time (ms)")

plt.grid(True, alpha=0.3)

plt.legend()

plt.tight_layout()

plt.savefig(
    "report/deletion_time.png",
    dpi=300
)

# ==================================================
# Graph 4
# AVL vs Balanced BST Height
# ==================================================

plt.figure(figsize=(10, 6))

plt.plot(
    df["Size"],
    df["BSTBalancedHeight"],
    marker="o",
    linewidth=2,
    label="BST Balanced"
)

plt.plot(
    df["Size"],
    df["AVLHeight"],
    marker="o",
    linewidth=2,
    label="AVL"
)

plt.title("AVL Height vs Perfectly Balanced BST")

plt.xlabel("Number of Keys")
plt.ylabel("Height")

plt.grid(True, alpha=0.3)

plt.legend()

plt.tight_layout()

plt.savefig(
    "report/avl_height_comparison.png",
    dpi=300
)

# ==================================================
# Graph 5
# AVL vs BST Insertion
# ==================================================

plt.figure(figsize=(10, 6))

plt.plot(
    df["Size"],
    df["BSTRandomMs"],
    marker="o",
    linewidth=2,
    label="BST Random"
)

plt.plot(
    df["Size"],
    df["AVLMs"],
    marker="o",
    linewidth=2,
    label="AVL"
)

plt.title("AVL vs Random BST Insertion Time")

plt.xlabel("Number of Keys")
plt.ylabel("Insertion Time (ms)")

plt.grid(True, alpha=0.3)

plt.legend()

plt.tight_layout()

plt.savefig(
    "report/avl_vs_bst_insert.png",
    dpi=300
)

# ==================================================
# Graph 6
# AVL vs BST Deletion
# ==================================================

plt.figure(figsize=(10, 6))

plt.plot(
    df["Size"],
    df["BSTDeleteMs"],
    marker="o",
    linewidth=2,
    label="BST"
)

plt.plot(
    df["Size"],
    df["AVLDeleteMs"],
    marker="o",
    linewidth=2,
    label="AVL"
)

plt.title("AVL vs BST Deletion Time")

plt.xlabel("Number of Keys")
plt.ylabel("Deletion Time (ms)")

plt.grid(True, alpha=0.3)

plt.legend()

plt.tight_layout()

plt.savefig(
    "report/avl_vs_bst_delete.png",
    dpi=300
)

print("Graphs saved to report/")

plt.show()